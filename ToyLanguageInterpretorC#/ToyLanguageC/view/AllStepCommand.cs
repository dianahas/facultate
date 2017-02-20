using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.controller;
using ToyLanguageC.utils;

namespace ToyLanguageC.view
{
    class AllStepCommand : Command
    {
        private Controller controller;

        public AllStepCommand(string key, string description, Controller controller) : base(key, description)
		{
            this.controller = controller;
        }


        public override void execute()
        {
            try
            {
                controller.allStep();
                Console.WriteLine(controller.currentProgramToString());
            }
            catch (InterpreterException error)
            {
                Console.WriteLine(error.Message);
            }
        }
    }
}
