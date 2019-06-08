using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    interface ICriticalSection
    {
        void Enter();
        bool TryEnter(int timeout);
        void SetSpinCount(int count);
        void Leave();
    }
}
