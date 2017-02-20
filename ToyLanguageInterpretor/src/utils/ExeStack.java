package utils;
import java.util.*;
public class ExeStack<E> implements IExeStack<E>{
	private Deque<E> stack;
	
	public ExeStack() {
		stack = new ArrayDeque<E>();
	}
	public void push(E elem) {
		stack.push(elem);		
	}

	@Override
	public E pop() {
		return stack.pop();
	}

	@Override
	public boolean isEmpty() {
		return stack.isEmpty();
	}

	@Override
	public E top() {
		return stack.peek();
	}
	
	public String toString() {
		return stack.toString();
	}
	@Override
	public Iterable<E> getAll() {
		return stack;
	}
}
