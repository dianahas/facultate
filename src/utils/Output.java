package utils;
import java.util.*;
public class Output<E> implements IOutput<E> {
	private ArrayList <E> outs;
	
	public Output(){
		outs = new ArrayList<E>();
	}
	@Override
	public void add(E elem) {
		outs.add(elem);		
	}

	@Override
	public int size() {
		return outs.size();
	}
	
	public String toString(){
		return outs.toString();
	}
	@Override
	public Iterable<E> getAll() {
		return outs;
	}

}
