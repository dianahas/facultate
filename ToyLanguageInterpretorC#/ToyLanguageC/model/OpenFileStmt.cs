using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class OpenFileStmt : Statement
    {
        private string fileId;
        private string fileName;

        public OpenFileStmt(string fileId, string fileName)
        {
            this.fileId = fileId;
            this.fileName = fileName;
        }

        private bool isOpen(String fileName2, FileTable<int, FileData> fileTable)
        {
            foreach (KeyValuePair<int, FileData> it in fileTable.getAll())
            {
                if (it.Value.Name==fileName2)
                    return true;
            }
            return false;
        }

        public ProgState execute(ProgState state)
        {
            FileTable<int, FileData> fileT = state.getFileTable;
            if (isOpen(fileName, fileT))
                throw new InterpreterException("error: file could not be open");
            try
            {
                StreamReader bufferedReader = new StreamReader(fileName);
                FileData fd = new FileData(fileName, bufferedReader);
                int id = Generator.generator();
                SymbolTable<string, int> symT = state.getSymbolTable;
                fileT.add(id, fd);
                symT.add(fileId, id);
            }
            catch (IOException e)
            {
                throw new InterpreterException("error: file could not be open");
            }
            return state;
        }

        public string toString()
        {
            return "openRFile(" + fileId + ", \"" + fileName + "\")";
        }
    }
}
