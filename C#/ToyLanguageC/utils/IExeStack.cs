using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.utils
{
    interface IExeStack<E>
    {
        void push(E elem);
        E pop();
        bool isEmpty();
        List<E> getAll();
        E peek();
    }
}
