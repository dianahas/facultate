using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ToyLanguageC.utils;

namespace ToyLanguageC.utils
{
    class ExeStack<E> : IExeStack<E>
    {
        Stack<E> exeStack;

        public ExeStack()
        {
            exeStack = new Stack<E>();
        }
        public List<E> getAll()
        {
            return exeStack.ToList();
        }

        public bool isEmpty()
        {
            return exeStack.Count()==0;
        }

        public E peek()
        {
            return exeStack.Peek();
        }

        public E pop()
        {
            return exeStack.Pop();
        }

        public void push(E elem)
        {
            exeStack.Push(elem);
        }

        public string toString()
        {
            string str = "";
            str += "ExecutionStackImpl = {";

            if (exeStack.Count() > 0)
            {
                str += "\n";
            }

            foreach (E statement in exeStack)
            {
                str += "   " + statement + "\n";
            }

            str += "}";
            return str;
        }
    }
}
