using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class ConstExpr : Expression
    {
        int number;

        public ConstExpr(int nr)
        {
            this.number = nr;
        }

        public int evaluate(SymbolTable<string, int> sym)
        {
            return number;
        }

        public string toString()
        {
            return "" + number;
        }
    }
}
