using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.view
{
    class TextMenu
    {
        private Dictionary<String, Command> commands;

        public TextMenu()
        {
            commands = new Dictionary<String, Command>();
        }

        public void addCommand(Command c)
        {
            commands.Add(c.getKey(), c);
        }

        private void printMenu()
        {
            foreach (KeyValuePair<string, Command> command in commands)
            {
                string line = string.Format("{0} : {1}", command.Value.getKey(), command.Value.getDescription());
                Console.WriteLine(line);
            }
        }

        public void show()
        {
            while (true)
            {
                printMenu();

                Console.Write("Type an option: ");
                string key = Console.ReadLine();
                Command command = commands[key];

                if (command == null)
                {
                    Console.WriteLine("Option doesn't exist.");
                    continue;
                }

                try
                {
                    command.execute();
                }
             
                catch (InterpreterException err)
                {
                    Console.WriteLine(err.Message);
                }
            }
        }
    }
}
