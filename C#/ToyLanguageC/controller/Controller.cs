using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.model;
using ToyLanguageC.repository;
using ToyLanguageC.utils;

namespace ToyLanguageC.controller
{
    class Controller
    {
        private IRepository repo;

        public Controller(IRepository repo)
        {
            this.repo = repo;
        }

        public ProgState oneStep(ProgState state)
        {
            ExeStack<Statement> stack = state.getExeStack;
            if (stack.isEmpty()) throw (new InterpreterException("error: no current state"));
            else
            {
                Statement crtStmt = stack.pop();
                return crtStmt.execute(state);
            }
        }

        public void allStep()
        {
            ProgState prg = repo.getCurrentProgr(); // repo is the controller field of type MyRepoInterface
            while (!prg.getExeStack.isEmpty())
            {
                oneStep(prg);
                repo.logCurrentProgramState();
            }
        }

        public string currentProgramToString()
        {
            ProgState currentProgram = repo.getCurrentProgr();
            return currentProgram.ToString();
        }
    }
}
