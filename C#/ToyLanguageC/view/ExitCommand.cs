using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.view
{
    class ExitCommand : Command
    {
        public ExitCommand(string key, string description) : base(key, description)
        {
        }

        public override void execute()
        {
            throw (new InterpreterException(""));
        }
    }
}
