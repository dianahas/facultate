package utils;
import java.util.*;

public class SymbolTable<K,V> implements ISymbolTable<K,V> {
	private Map<K,V> map;
	
	public SymbolTable(){
		map = new HashMap<>();
	}
	@Override
	public void add(K key, V value) {
		map.put(key, value);
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
	
	public ISymbolTable<K,V> clone(){
		ISymbolTable<K,V> newST = new SymbolTable<K,V>();
		for(Map.Entry<K, V> entry:getAll())
			newST.add(entry.getKey(), entry.getValue());
		return newST;
	}
	@Override
	public List<V> values() {
		List<V> list = new ArrayList<>(); 
		for(Map.Entry<K, V> s:getAll())
			list.add(s.getValue());
		return list;
	}
	
}
