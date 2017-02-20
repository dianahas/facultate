using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.model;
using ToyLanguageC.utils;

namespace ToyLanguageC.repository
{
    class Repository : IRepository
    {
        private ProgState state;
        private string logFilee;

        public Repository(ProgState state,string logFile)
        {
            this.state = state;
            this.logFilee = logFile;
        }

        public void add(ProgState programState)
        {
            this.state = programState;
        }

        public ProgState getCurrentProgr()
        {
            return state;
        }

        public void logCurrentProgramState()
        {
            using (StreamWriter logFile = new StreamWriter(logFilee, true))
            {
                try
                {
                    logFile.WriteLine("Execution Stack\n");
                    foreach (Statement statement in state.getExeStack.getAll())
                    {
                        logFile.WriteLine("  " + statement + "\n");
                    }
                    logFile.WriteLine("\n");

                    logFile.WriteLine("Symbol Table\n");
                    foreach (KeyValuePair<string, int> entry in state.getSymbolTable.getAll())
                    {
                        logFile.WriteLine("  " + entry.Key + " --> " + entry.Value + "\n");
                    }
                    logFile.WriteLine("\n");

                    logFile.WriteLine("File Table\n");
                    foreach (KeyValuePair<int, FileData> entry in state.getFileTable.getAll())
                    {
                        logFile.WriteLine("  " + entry.Key + " --> " + entry.Value + "\n");
                    }
                    logFile.WriteLine("\n");

                    logFile.WriteLine("Output\n");
                    foreach (int output in state.getOutput.getAll())
                    {
                        logFile.WriteLine("  " + output + "\n");
                    }
                    logFile.WriteLine("-------------------\n");
                }
                catch (IOException)
                {
                    throw (new InterpreterException("error: could not write to the given file"));
                }
            }
        }
    }
}
