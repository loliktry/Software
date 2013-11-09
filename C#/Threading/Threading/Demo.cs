using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Threading
{
    class Demo
    {
        public void Execution1()
        {
            for (int i = 0; i <= 500; i++)
            {
                for (int j = 0; j <= 500; j++)
                {
                    
                }
                Console.Write(".");
            }
        }

        public void Execution2()
        {
            for (int number = 0; number <= 10; number++)
            {
                Console.WriteLine("Thread2");
            }
        }

    }
}
