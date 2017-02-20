using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class AssignStmt : Statement
    {
        private string name;
        private Expression exp;

        public AssignStmt(string name, Expression exp)
        {
            this.name = name;
            this.exp = exp;
        }
        public ProgState execute(ProgState state)
        {
            SymbolTable<string, int> table = state.getSymbolTable;
            int val = exp.evaluate(table);
            table.add(name, val);
            return state;
        }

        public string toString()
        {
            return name + "=" + exp.toString(); 
        }
    }
}
