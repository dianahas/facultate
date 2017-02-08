package model.statement;

import model.Expression;
import model.ProgState;
import utils.IHeap;
import utils.ISymbolTable;

public class IfStmt implements Statement{
	private Expression exp;
	private Statement stm1,stm2;
	
	public IfStmt(Expression ex,Statement st1,Statement st2){
		exp=ex;
		stm1=st1;
		stm2=st2;
	}
	
	@Override
	public ProgState execute(ProgState p){
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		IHeap<Integer,Integer> hp = p.getHeap();
		int result = exp.evaluate(t,hp);
		if(result==1)
			p.getExeStack().push(stm1);
		else p.getExeStack().push(stm2);
		return null;
	}
		
	public String toString(){
		return "if ("+exp+") then "+stm1+"; else "+stm2;
	}
}
