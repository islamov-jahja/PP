using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace lab3
{
    class PICalculator : IPICalculator
    {
        private const int COUNT_OF_THREAD = 4;

        private double m_PI = 0;

        private readonly int m_stepsCount;
        private readonly int m_timeout;
        private readonly int m_spinCount;
        private readonly ICriticalSection m_criticalSection;
        private readonly double m_step;

        public PICalculator(int stepsCount, int timeout, int spinCount, ICriticalSection criticalSection)
        {
            m_stepsCount = stepsCount;
            m_timeout = timeout;
            m_criticalSection = criticalSection;
            m_spinCount = spinCount;
            m_criticalSection.SetSpinCount(spinCount);
            m_step = 1f / m_stepsCount;
        }

        public double ToCalculate()
        {
            List<Thread> listOfThreads = new List<Thread>();
            m_PI = 0;
            int stepsCountPerThread = m_stepsCount / COUNT_OF_THREAD;

            for (int i = 0; i < COUNT_OF_THREAD; i++)
            {
                Thread newThread = new Thread(CalculatePartOfPi);
                newThread.Start(new ArgumentOfThread
                {
                    left = i * stepsCountPerThread,
                    right = (i + 1) * stepsCountPerThread,
                    calculator = this
                });

                listOfThreads.Add(newThread);
            }

            foreach (Thread thread in listOfThreads)
            {
                thread.Join();
            }

            return m_PI;
        }


        private static void CalculatePartOfPi(object arg)
        {
            ArgumentOfThread settingOfThread = (ArgumentOfThread)arg;
            double x = 0;
            double sum = 0;
            double step = settingOfThread.calculator.m_step;

            //Console.WriteLine(settingOfThread.left + " " + settingOfThread.right);
            //Console.WriteLine(step);

            for (long i = settingOfThread.left; i < settingOfThread.right; i++)
            {

                x = (i + .5) * step;
                sum = sum + 4.0 / (1.0 + x * x);
            }

            settingOfThread.calculator.m_criticalSection.TryEnter(settingOfThread.calculator.m_timeout);
            settingOfThread.calculator.m_PI += sum * step;
            settingOfThread.calculator.m_criticalSection.Leave();
        }

    }
}
