package utils;
import java.util.*;

public class FileTable<K,V> implements IFileTable<K,V> {
	private Map<K,V> map;
	
	public FileTable(){
		map = new HashMap<>();
	}
	
	public void add(K key, V val) {
		map.putIfAbsent(key, val);
	}

	@Override
	public V getValue(K key){
		V value = map.get(key);
		return value;
	}

	@Override
	public void remove(K key){
		map.remove(key);
	}

	@Override
	public Iterable<Map.Entry<K, V>> getAll() {
		return map.entrySet();
	}
	
	public String toString(){
		StringBuilder s = new StringBuilder();
		for(K key:map.keySet()){
			s.append(key);
			s.append(" = ");
			s.append(map.get(key)+" ");
		}
		return s.toString();
	}
}
