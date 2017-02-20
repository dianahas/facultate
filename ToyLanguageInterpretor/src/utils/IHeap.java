package utils;

import java.util.Map;

public interface IHeap<K,V> {
	void add(K key,V value);
	boolean contains(K key);
	V getValue(K key);
	void setValue(K key,V value);
	Iterable<Map.Entry<K, V>> getAll();
	boolean empty();
	Map<K, V> getHeap();
	void setHeap(Map<K, V> newContent);
}
