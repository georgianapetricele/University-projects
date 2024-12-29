using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Lab4_PDP.Implementations
{
    class TasksImplementation
    {
        private static List<string> Hosts;
        private static List<Task> Tasks;

        public static void Run(List<string> hostnames)
        {
            Hosts = hostnames;
            Tasks = new List<Task>();

            for (var i = 0; i < Hosts.Count; i++)
            {
                Tasks.Add(Task.Factory.StartNew(StartCurrent, i));
            }

            Task.WaitAll(Tasks.ToArray());
        }

        private static void StartCurrent(object idObject)
        {
            var id = (int)idObject;

            StartClient(Hosts[id], id);
        }

        private static void StartClient(string host, int id)
        {
            // Establish the remote endpoint of the server  
            var ipHostInfo = Dns.GetHostEntry(host.Split('/')[0]);
            var ipAddress = ipHostInfo.AddressList[0];
            var remoteEndpoint = new IPEndPoint(ipAddress, HttpUtils.HTTP_PORT);

            // Create the TCP/IP socket
            var client = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            // Create a wrapper state for the connection information
            var state = new State
            {
                socket = client,
                hostname = host.Split('/')[0],
                endpointPath = host.Contains("/") ? host.Substring(host.IndexOf("/")) : "/",
                remoteEndpoint = remoteEndpoint,
                clientID = id
            };

            // Start asynchronous operations
            Connect(state).ContinueWith(connectTask =>
            {
                if (connectTask.IsFaulted)
                {
                    Console.WriteLine($"Error connecting: {connectTask.Exception}");
                    return Task.CompletedTask;
                }

                return Send(state, HttpUtils.getRequestString(state.hostname, state.endpointPath));
            }).ContinueWith(sendTask =>
            {
                if (sendTask.Result.IsFaulted)
                {
                    Console.WriteLine($"Error sending: {sendTask.Result.Exception}");
                    return Task.CompletedTask;
                }

                return Receive(state);
            }).ContinueWith(receiveTask =>
            {
                if (receiveTask.Result.IsFaulted)
                {
                    Console.WriteLine($"Error receiving: {receiveTask.Result.Exception}");
                    return;
                }

                Console.WriteLine(state.responseContent);


                client.Shutdown(SocketShutdown.Both);
                client.Close();
            });
        }


        private static Task Connect(State state)
        {
            state.socket.BeginConnect(state.remoteEndpoint, ConnectCallback, state);

            return Task.FromResult(state.connectDone.WaitOne());
        }

        private static void ConnectCallback(IAsyncResult ar)
        {
            // retrieve the details from the connection information wrapper
            var state = (State)ar.AsyncState;
            var clientSocket = state.socket;
            var clientId = state.clientID;
            var hostname = state.hostname;

            // complete the connection  
            clientSocket.EndConnect(ar);

            Console.WriteLine("{0}) Socket connected to {1} ({2})", clientId, hostname, clientSocket.RemoteEndPoint);

            // signal that the connection has been made 
            state.connectDone.Set();
        }

        private static Task Send(State state, string data)
        {
            // convert the string data to byte data using ASCII encoding.  
            var byteData = Encoding.ASCII.GetBytes(data);

            // begin sending the data to the server  
            state.socket.BeginSend(byteData, 0, byteData.Length, 0, SendCallback, state);

            return Task.FromResult(state.sendDone.WaitOne());
        }

        private static void SendCallback(IAsyncResult ar)
        {
            var state = (State)ar.AsyncState;
            var clientSocket = state.socket;
            var clientId = state.clientID;

            // complete sending the data to the server  
            var bytesSent = clientSocket.EndSend(ar);
            Console.WriteLine("{0}) Sent {1} bytes to server.", clientId, bytesSent);

            // signal that all bytes have been sent
            state.sendDone.Set();
        }

        private static Task Receive(State state)
        {
            // begin receiving the data from the server
            state.socket.BeginReceive(state.receiveBuffer, 0, State.BUFFER_SIZE, 0, ReceiveCallback, state);

            return Task.FromResult(state.receiveDone.WaitOne());
        }

        private static void ReceiveCallback(IAsyncResult ar)
        {
            // retrieve the details from the connection information wrapper
            var state = (State)ar.AsyncState;
            var clientSocket = state.socket;

            try
            {
                // read data from the remote device.  
                var bytesRead = clientSocket.EndReceive(ar);

                // get from the buffer, a number of characters <= to the buffer size, and store it in the responseContent
                state.responseContent.Append(Encoding.ASCII.GetString(state.receiveBuffer, 0, bytesRead));

                // if the response header has not been fully obtained, get the next chunk of data
                if (!HttpUtils.responseHeaderFullyObtained(state.responseContent.ToString()))
                {
                    clientSocket.BeginReceive(state.receiveBuffer, 0, State.BUFFER_SIZE, 0, ReceiveCallback, state);
                }
                else
                {
                    // header has been fully obtained
                    // get the body
                    var responseBody = HttpUtils.getResponseBody(state.responseContent.ToString());

                    // the custom header parser is being used to check if the data received so far has the length
                    // specified in the response headers
                    if (responseBody.Length < HttpUtils.getContentLength(state.responseContent.ToString()))
                    {
                        // if it isn't, than more data is to be retrieve
                        clientSocket.BeginReceive(state.receiveBuffer, 0, State.BUFFER_SIZE, 0, ReceiveCallback, state);
                    }
                    else
                    {
                        // otherwise, all the data has been received  
                        // signal that all bytes have been received  
                        state.receiveDone.Set();
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}
