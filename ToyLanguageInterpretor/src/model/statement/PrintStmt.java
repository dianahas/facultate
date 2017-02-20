package model.statement;

import model.Expression;
import model.ProgState;
import utils.IHeap;
import utils.IOutput;
import utils.ISymbolTable;

public class PrintStmt implements Statement{
	private Expression exp;
	
	public PrintStmt(Expression exp){
		this.exp=exp;
	}
	@Override
	public ProgState execute(ProgState p){
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		IHeap<Integer,Integer> hp = p.getHeap();
		int result = exp.evaluate(t,hp);
		IOutput<Integer> out = p.getOutput();
		out.add(result);
		return null;
	}
	
	public String toString(){
		return "Print ( "+exp+")";
	}
}
