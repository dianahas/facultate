package utils;
import java.util.*; 

public interface IFileTable<K,V> {
	void add(K key, V val);
	V getValue(K key);
	void remove(K key);
	Iterable<Map.Entry<K, V>> getAll();
	
}
