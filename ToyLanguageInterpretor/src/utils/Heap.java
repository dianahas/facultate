package utils;

import java.util.HashMap;
import java.util.Map;

public class Heap<K,V> implements IHeap<K,V>{
private Map<K,V> map;
	
	public Heap(){
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

	@Override
	public void setValue(K key, V value) {
		map.put(key, value);
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
	public void setHeap(Map<K, V> newContent) {
		map = newContent;
	}
	@Override
	public Map<K, V> getHeap() {
		return map;
	}
}
