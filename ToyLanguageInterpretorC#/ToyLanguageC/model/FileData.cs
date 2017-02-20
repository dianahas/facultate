using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.model
{
    class FileData
    {
        private string name;
        private StreamReader buffer;

        public FileData(string name,StreamReader buffer)
        {
            this.name = name;
            this.buffer = buffer;
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public StreamReader Buffer
        {
            get { return buffer; }
            set { buffer = value; }
        }

        public string toString()
        {
            return name;
        }

    }
}
