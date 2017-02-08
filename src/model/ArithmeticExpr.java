package model;
import utils.*;

public class ArithmeticExpr implements Expression{
	private char operator;
	private Expression oper1,oper2;
	
	public ArithmeticExpr(char oper,Expression first,Expression second){
		operator=oper;
		oper1=first;
		oper2=second;
	}
	
	@Override
	public int evaluate(ISymbolTable<String,Integer> t,IHeap<Integer,Integer> hp){
		int firstR = oper1.evaluate(t,hp);
		int secondR = oper2.evaluate(t,hp);
		switch(operator)
		{
		case '+':return firstR+secondR;
		case '-':return firstR-secondR;
		case '*':return firstR*secondR;
		case '/': 
			if(secondR==0)
				throw new InterpretorException("cannot devide by 0");
			return firstR/secondR;
		default: throw new InterpretorException("data not valid");
		}
	}
	
	public String toString() {
		return " " + oper1 + operator + oper2;
	}
	
}
