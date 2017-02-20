package utils;

public interface IExeStack<E> {

	void push(E elem);
	E pop();
	boolean isEmpty();
	E top();
	Iterable<E> getAll();
}
