using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class CloseFileStmt : Statement
    {
        private Expression fileDescriptor;

        public CloseFileStmt(Expression fileDescriptor)
        {
            this.fileDescriptor = fileDescriptor;
        }


        public ProgState execute(ProgState programState)
        {
            try
            {
                int descriptor = fileDescriptor.evaluate(programState.getSymbolTable);
                FileTable<int, FileData> fileTable = programState.getFileTable;
                StreamReader bufferedReader = fileTable.getValue(descriptor).Buffer;

                bufferedReader.Close();
                fileTable.remove(descriptor);

                return programState;

            }
            catch (IOException)
            {
                throw (new InterpreterException("error: file could not be closed"));
            }
        }


        public string toString()
        {
            return "closeRFile(" + fileDescriptor + ")";
        }
    }
}
