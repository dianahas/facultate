using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class PrintStmt : Statement
    {
        Expression exp;

        public PrintStmt(Expression exp)
        {
            this.exp = exp;
        }
        public ProgState execute(ProgState state)
        {
            SymbolTable<string, int> table = state.getSymbolTable;
            Output<int> outs = state.getOutput;
            outs.add(exp.evaluate(table));
            return state;
        }

        public string toString()
        {
            return "print(" + exp.toString() + ")";
        }
    }
}
