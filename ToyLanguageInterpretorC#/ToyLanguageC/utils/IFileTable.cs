using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.utils
{
    interface IFileTable<K,V>
    {
        void add(K key, V value);
        bool contains(K key);
        V remove(K key);
        V getValue(K key);
        List<KeyValuePair<K, V>> getAll();
    }
}
