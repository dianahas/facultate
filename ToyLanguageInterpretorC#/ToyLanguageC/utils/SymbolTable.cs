﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToyLanguageC.utils
{
    class SymbolTable<K,V> : ISymbolTable<K, V>
    {
        private Dictionary<K, V> table;

        public SymbolTable()
        {
            this.table = new Dictionary<K, V>();
        }

        public void add(K key, V value)
        {
            if (table.ContainsKey(key))
                table[key] = value;
            else table.Add(key, value);
        }

        public bool contains(K key)
        {
            return table.ContainsKey(key);
        }

        public List<KeyValuePair<K, V>> getAll()
        {
            return table.ToList();
        }

        public V getValue(K key)
        {
            if (table.ContainsKey(key))
                return table[key];
            else return default(V);
        }

        public string toString()
        {
            string str = "";
            str += "SymbolTableImpl = {";

            if (table.Count() > 0) str += "\n";

            foreach (KeyValuePair<K, V> pair in table.ToList())
            {
                str += "   " + pair.Key + " <- " + pair.Value + "\n";
            }

            str += "}";
            return str;
        }
    }
}