using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace lab3
{
    class Program
    {
        static void Main(string[] args)
        {
            ICriticalSection criticalSection = new AutoResetEventCriticalSection();
            IPICalculator pICalculator = new PICalculator((Convert.ToInt32(args[0])), Convert.ToInt32(args[2]), Convert.ToInt32(args[1]), criticalSection);// 1) количество итераций 2) spinCount  3)timeout 
            Stopwatch watch = Stopwatch.StartNew();
            double pi = pICalculator.ToCalculate();
            watch.Stop();

            Console.WriteLine("Pi: " + pi);
            Console.WriteLine("Time (ms): " + watch.ElapsedMilliseconds);
        }
        
    }
}
