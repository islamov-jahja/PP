using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using lab3;
namespace lab3
{
    class AutoResetEventCriticalSection : ICriticalSection
    {
        private const int COUNT_MILLI_SECONDS = 10;

        public void Enter()
        {
            while (true)
            {
                for (int i = 0; i < m_spinCount; i++)
                {
                    if (m_resetEvent.WaitOne(COUNT_MILLI_SECONDS))
                        return;
                }

                Thread.Sleep(COUNT_MILLI_SECONDS);
            }
        }

        public void Leave()
        {
            m_resetEvent.Set();
        }

        public void SetSpinCount(int count)
        {
            if (count > 1)
            {
                m_spinCount = count;
            }
        }

        public bool TryEnter(int timeout)
        {
            if (timeout > 0)
            {
                DateTime endingTime = DateTime.UtcNow.AddMilliseconds(timeout);

                while(endingTime > DateTime.UtcNow)
                {
                    for (int i = 0; i < m_spinCount; i++)
                    {
                        if (m_resetEvent.WaitOne(10))
                            return true;
                        if (endingTime <= DateTime.UtcNow)
                            return false;
                    }
                    
                    Thread.Sleep(COUNT_MILLI_SECONDS);
                }
            }

            return false;
        }

        private readonly AutoResetEvent m_resetEvent = new AutoResetEvent(true);
        private int m_spinCount = 1;
    }
}
