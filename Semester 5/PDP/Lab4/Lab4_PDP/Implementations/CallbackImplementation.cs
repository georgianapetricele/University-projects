using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Lab4_PDP.Implementations
{
    class CallbackImplementation
    {
        private static List<string> hostNames;

        public static void Run(List<string> hostnames)
        {

            for (var i = 0; i < hostnames.Count; i++)
            {
                StartClient(hostnames[i], i);
            }
        }

        private static void StartClient(string host, int id)
        {
            // server endpoint
            var hostInfo = Dns.GetHostEntry(host.Split('/')[0]);
            var ipAddress = hostInfo.AddressList[0];
            var remoteEndpoint = new IPEndPoint(ipAddress, HttpUtils.HTTP_PORT);

            // create the TCP/IP socket
            var client = new Socket(ipAddress.AddressFamily, SocketType.Stream, ProtocolType.Tcp);

            // create a state containing the connection information
            var state = new State
            {
                socket = client,
                hostname = host.Split('/')[0],
                endpointPath = host.Contains("/") ? host.Substring(host.IndexOf("/")) : "/",
                remoteEndpoint = remoteEndpoint,
                clientID = id
            };

            // connect to the remote endpoint  
            state.socket.BeginConnect(state.remoteEndpoint, ConnectCallback, state);
        }

        // Callback function when the connection attempt completes
        private static void ConnectCallback(IAsyncResult asyncRes)
        {
           // Thread.Sleep(5000);
            // retrieve the details from the connection information wrapper
            var state = (State)asyncRes.AsyncState;
            var clientSocket = state.socket;
            var clientId = state.clientID;
            var hostname = state.hostname;

            // If the connection succeeds then it is completed using EndConnect
            clientSocket.EndConnect(asyncRes);
            Console.WriteLine("{0}) Socket connected to {1} ({2})", clientId, hostname, clientSocket.RemoteEndPoint);

            // convert the string data to byte data using ASCII encoding.  
            var byteData = Encoding.ASCII.GetBytes(HttpUtils.getRequestString(state.hostname, state.endpointPath));

            // begin sending the HTTP GET request to the server
            state.socket.BeginSend(byteData, 0, byteData.Length, 0, SendCallback, state);
        }

        private static void SendCallback(IAsyncResult ar)
        {
            var state = (State)ar.AsyncState;
            var clientSocket = state.socket;
            var clientId = state.clientID;

            // complete sending the data to the server  
            var bytesSent = clientSocket.EndSend(ar);
            Console.WriteLine("{0}) Sent {1} bytes to server.", clientId, bytesSent);

            // begin receiving the data from the server asynchronously
            state.socket.BeginReceive(state.receiveBuffer, 0, State.BUFFER_SIZE, 0, ReceiveCallback, state);
        }

        private static void ReceiveCallback(IAsyncResult ar)
        {
            var state = (State)ar.AsyncState;
            var clientSocket = state.socket;
            var clientId = state.clientID;

            try
            {
                // read data after ending the receiving
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
                    var contentLengthHeaderValue = HttpUtils.getContentLength(state.responseContent.ToString());
                    if (responseBody.Length < contentLengthHeaderValue)
                    {
                        // if it isn't, than more data is to be retrieved
                        clientSocket.BeginReceive(state.receiveBuffer, 0, State.BUFFER_SIZE, 0, ReceiveCallback, state);
                    }
                    else
                    {
                        // otherwise, all the data has been received  
                        // write the response details to the console
                        //Console.WriteLine(
                        //"{0}) Response received : expected {1} chars in body, got {2} chars (headers + body)",
                        //clientId, contentLengthHeaderValue, state.responseContent.Length);
                        var outputDirectory = "C:\\Downloads";
                        Directory.CreateDirectory(outputDirectory); // Ensure the directory exists
                        var outputFilePath = Path.Combine(outputDirectory, $"response_{clientId}.html");
                        File.WriteAllText(outputFilePath, responseBody);

                        Console.WriteLine(state.responseContent);

                        // release the socket
                        clientSocket.Shutdown(SocketShutdown.Both);
                        clientSocket.Close();
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
