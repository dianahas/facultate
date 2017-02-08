package model;
import utils.*;

public class ConstExp implements Expression{
	private int value;
	
	public ConstExp(int val){
		value=val;
	}
	
	public int evaluate(ISymbolTable<String,Integer> t,IHeap<Integer,Integer> hp) {
		return value;
	}
	
	public String toString() {
		return " " + value;
	}
	
}
