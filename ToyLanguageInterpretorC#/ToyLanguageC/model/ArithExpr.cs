using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class ArithExpr : Expression
    {
        private char oper;
        private Expression first;
        private Expression second;

        public ArithExpr(char oper,Expression first,Expression second)
        {
            this.oper = oper;
            this.first = first;
            this.second = second;
        }

        public int evaluate(SymbolTable<string, int> sym)
        {
            int firstRes = first.evaluate(sym);
            int secondRes = second.evaluate(sym);

            switch(oper)
            {
                case '+': return firstRes + secondRes;
                case '-': return firstRes - secondRes;
                case '*': return firstRes * secondRes;
                case '/': if (secondRes == 0) throw (new InterpreterException("error: division by zero"));
                    else return firstRes / secondRes;
                default:
                    throw (new InterpreterException("error: invalid op"));
            }
        }

        public string toString()
        {
            return first.toString() + oper + second.toString();
        }
    }
}
