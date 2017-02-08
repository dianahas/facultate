package utils;

import java.util.HashMap;
import java.util.Map;

public class LockTable<K,V> implements ILockTable<K, V> {
	private Map<K,V> map;
	public LockTable(){
		map = new HashMap<>();
	}
	@Override
	public void add(K key, V value) {
		map.putIfAbsent(key, value);
	}

	@Override
	public boolean contains(K key) {
		return map.containsKey(key);
	}

	@Override
	public V getValue(K key){
		V value = map.get(key);
		return value;
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
	@Override
	public Iterable<Map.Entry<K, V>> getAll() {
		return map.entrySet();
	}
	@Override
	public boolean empty() {
		return map.isEmpty();
	}
	@Override
	public void setValue(K key, V value) {
		map.put(key, value);
	}

}
