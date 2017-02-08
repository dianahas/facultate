package utils;

import java.util.Map;

public interface ILockTable<K,V> {
	void add(K key,V value);
	boolean contains(K key);
	V getValue(K key);
	void setValue(K key,V value);
	Iterable<Map.Entry<K, V>> getAll();
	boolean empty();
}
