using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class IfStmt : Statement
    {
        Expression exp;
        Statement stm1;
        Statement stm2;

        public IfStmt(Expression exp1,Statement stm1,Statement stm2)
        {
            this.exp = exp1;
            this.stm1 = stm1;
            this.stm2 = stm2;
        }

        public ProgState execute(ProgState state)
        {
            ExeStack<Statement> stack = state.getExeStack;
            SymbolTable<string, int> table = state.getSymbolTable;
            int val = exp.evaluate(table);
            if (val != 0)
                stack.push(stm1);
            else stack.push(stm2);
            return state;
        }

        public string toString()
        {
            return "IF(" + exp.toString() + ") THEN(" + stm1.toString()+ ")ELSE(" + stm2.toString() + ")"; ;
        }
    }
}
