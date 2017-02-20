using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class CompStmt : Statement
    {
        Statement stm1;
        Statement stm2;

        public CompStmt(Statement stm1,Statement stm2)
        {
            this.stm1 = stm1;
            this.stm2 = stm2;
        }

        public ProgState execute(ProgState state)
        {
            ExeStack<Statement> stack = state.getExeStack;
            stack.push(stm2);
            stack.push(stm1);
            return state;
        }

        public string toString()
        {
            return stm1.toString() + "; " + stm2.toString();
        }
    }
}
