using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.model
{
    class ProgState
    {
        SymbolTable<string, int> symTable;
        ExeStack<Statement> exe;
        Output<int> outs;
        FileTable<int, FileData> fileT;
        Statement stm;

        public ProgState(SymbolTable<string, int> symTable, ExeStack<Statement> exe, Output<int> outs, FileTable<int, FileData> fileT, Statement stm)
        {
            this.symTable = symTable;
            this.exe = exe;
            this.outs = outs;
            this.fileT = fileT;
            this.exe.push(stm);
        }

        public ExeStack<Statement> getExeStack
        {
            get { return exe; }
            set { exe = value; }
        }

        public SymbolTable<string, int> getSymbolTable
        {
            get { return symTable; }
            set { symTable = value; }
        }
        
        public FileTable<int, FileData> getFileTable
        {
            get { return fileT; }
            set { fileT = value; }
        }
        
        public Output<int> getOutput
        {
            get { return outs; }
            set { outs = value; }
        }

        public override string ToString()
        {
            return exe.toString() + "\n"
                    + symTable.toString() + "\n"
                    + fileT.toString() + "\n"
                    + outs.toString();
        }
    }
}
