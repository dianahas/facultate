using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.utils
{
    interface IOutput<E>
    {
        void add(E elem);
        List<E> getAll();
    }
}
