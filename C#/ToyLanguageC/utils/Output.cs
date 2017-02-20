using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.utils
{
    class Output<E> : IOutput<E>
    {
        private List<E> outs;

        public Output()
        {
            outs = new List<E>();
        }

        public void add(E elem)
        {
            outs.Add(elem);
        }

        public List<E> getAll()
        {
            return outs;
        }

        public string toString()
        {
            string str = "";
            str += "OutputImpl = {";

            if (outs.Count() > 0) str += "\n";

            foreach (E output in outs)
            {
                str += "   " + output + "\n";
            }

            str += "}";
            return str;
        }

    }
}
