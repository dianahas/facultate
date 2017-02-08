package model.statement;

import model.ProgState;
import utils.*;

public class ForkStmt implements Statement {
	private Statement stmt;
	
	public ForkStmt(Statement s){
		stmt = s;
	}
	
	@Override
	public ProgState execute(ProgState p) {
		ISymbolTable<String, Integer> t = p.getSymbolTable();
		ISymbolTable<String, Integer> newT = t.clone();
		ProgState newPS = new ProgState(new ExeStack<Statement>(), newT,p.getOutput(),p.getFileTable(),p.getHeap(),p.getLockTable(),stmt);
		return newPS;
	}
	
	public String toString(){
		return "fork" +stmt;
	}
}
