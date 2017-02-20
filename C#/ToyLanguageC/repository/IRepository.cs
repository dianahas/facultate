using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.model;

namespace ToyLanguageC.repository
{
    interface IRepository
    {
        ProgState getCurrentProgr();
        void add(ProgState programState);
        void logCurrentProgramState();
    }
}
