using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    interface Expression
    {
        int evaluate(SymbolTable<string, int> sym);
        string toString();
    }
}
