package model;
import utils.*;

public class VarExpr implements Expression{
	private String name;
	public VarExpr(String name){
		this.name=name;
	}
	
	public int evaluate(ISymbolTable<String,Integer> s,IHeap<Integer,Integer> hp){
		if(s.contains(name))
			return s.getValue(name);
		else throw new InterpretorException("no such variable");
	}
	
	public String toString() {
		return name;
	}
}
