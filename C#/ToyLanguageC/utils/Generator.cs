using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.utils
{
    class Generator
    {
        private static int counter = 0;
        public static int generator()
        {
            return ++counter;
        }
    }
}
