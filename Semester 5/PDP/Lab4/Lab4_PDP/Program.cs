using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.Intrinsics.Arm;
using Lab4_PDP.Implementations;
using static System.Net.WebRequestMethods;

namespace Lab4
{
    class Program
    {
        static void Main()
        {
            Stopwatch stopwatch = new Stopwatch();
            var hosts = new List<string>
            {
               //"example.com",
               "www.cs.ubbcluj.ro/~rlupsa/edu/pdp"
                //"www.cs.ubbcluj.ro/~forest"
                // "www.cs.ubbcluj.ro/~arthur",
            };

            Console.WriteLine("\n");
            Console.WriteLine("Direct Callback");
            stopwatch.Start();
            try
            {
                CallbackImplementation.Run(hosts);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
            stopwatch.Stop();
            TimeSpan directCallbackTime = stopwatch.Elapsed;

            Console.WriteLine("\n");
            Console.WriteLine("Tasks");
            stopwatch.Restart();
            try
            {
                TasksImplementation.Run(hosts);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
            stopwatch.Stop();
            TimeSpan taskMechanismTime = stopwatch.Elapsed;

            Console.WriteLine("\n");
            Console.WriteLine("Async + Await Tasks");
            stopwatch.Restart();
            try
            {
                AsyncTasksImplementation.Run(hosts);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
            stopwatch.Stop();
            TimeSpan asyncTaskMechanismTime = stopwatch.Elapsed;

            Console.WriteLine("Direct callback: {0}", directCallbackTime);
            Console.WriteLine("Task mechanism: {0}", taskMechanismTime);
            Console.WriteLine("Async+await task mechanism: {0}", asyncTaskMechanismTime);
        }
    }
    
}