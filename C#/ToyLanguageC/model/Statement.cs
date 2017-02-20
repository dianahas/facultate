using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.model
{
    interface Statement
    {
        ProgState execute(ProgState state);
        string toString();
    }
}
