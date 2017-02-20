using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class ReadFileStmt : Statement
    {
        private Expression fileDescriptor;
        private string variable;

        public ReadFileStmt(Expression fileDescriptor, string variable)
        {
            this.fileDescriptor = fileDescriptor;
            this.variable = variable;
        }


        public ProgState execute(ProgState programState)
        {
            try
            {
                int descriptor = fileDescriptor.evaluate(programState.getSymbolTable);
                FileTable<int, FileData> fileTable = programState.getFileTable;
                StreamReader bufferedReader = fileTable.getValue(descriptor).Buffer;

                string line = bufferedReader.ReadLine();
                ConstExpr value;

                if (line == null)
                {
                    value = new ConstExpr(0);
                }
                else
                {
                    value = new ConstExpr(int.Parse(line));
                }

                Statement assignment = new AssignStmt(variable, value);

                return assignment.execute(programState);

            }
            catch (IOException)
            {
                throw (new InterpreterException("error: file could not be read"));
            }
        }


        public string toString()
        {
            return "readFile(" + fileDescriptor + ", " + variable + ")";
        }
    }
}
