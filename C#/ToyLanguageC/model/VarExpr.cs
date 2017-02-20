using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class VarExpr : Expression
    {
        private string var;

        public VarExpr(string var)
        {
            this.var = var;
        }

        public int evaluate(SymbolTable<string, int> sym)
        {
            return sym.getValue(var);
        }

        public string toString()
        {
            return var;
        }
    }
}
