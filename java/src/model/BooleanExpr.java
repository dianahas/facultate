package model;
import utils.*;

public class BooleanExpr implements Expression {
	private String operator;
	private Expression oper1,oper2;
	
	public BooleanExpr(String oper,Expression first,Expression second){
		operator=oper;
		oper1=first;
		oper2=second;
	}
	
	@Override
	public int evaluate(ISymbolTable<String, Integer> t, IHeap<Integer, Integer> hp) {
		int firstR = oper1.evaluate(t,hp);
		int secondR = oper2.evaluate(t,hp);
		switch(operator)
		{
		case "<":
			if(firstR<secondR)
				return 1;
			else return 0;		
		case "<=":
			if(firstR<=secondR)
				return 1;
			else return 0;
		case "==":
			if(firstR==secondR)
				return 1;
			else return 0;
		case "!=":
			if(firstR!=secondR)
				return 1;
			else return 0;
		case ">":
			if(firstR>secondR)
				return 1;
			else return 0;
		case ">=":
			if(firstR>=secondR)
				return 1;
			else return 0;
		default: throw new InterpretorException("data not valid");
		}
	}
	
	public String toString() {
		return "(" + oper1 + operator + oper2 + ")";
	}
}
