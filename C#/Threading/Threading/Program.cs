using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Threading
{
    class Program
    {
        static void Main(string[] args)
        {
            Demo obj = new Demo();
            Thread thread1, thread2;

            thread1 = new Thread(new ThreadStart(obj.Execution1));
            thread2 = new Thread(new ThreadStart(obj.Execution2));

            thread1.Priority = ThreadPriority.Highest;
            thread1.Start();

            thread2.Start();
            Console.ReadLine();
        }
    }
}
