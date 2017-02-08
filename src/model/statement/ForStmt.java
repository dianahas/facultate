package model.statement;

import model.*;
import utils.*;

public class ForStmt implements Statement {
	private Expression exp1;
	private Statement statement,stmt1,stmt3;
	Boolean first = false;
	public ForStmt(Statement stmt1,Expression exp1, Statement stmt3,Statement statement) {
		this.exp1 = exp1;
		this.stmt1 = stmt1;
		this.stmt3 = stmt3;
		this.statement = statement;
	}
	
	@Override
	public ProgState execute(ProgState p) {
		ISymbolTable<String, Integer> table = p.getSymbolTable();
		IHeap<Integer, Integer> hp = p.getHeap();
		if(first == false){
			stmt1.execute(p);
			first = true;
		}
		IExeStack<Statement> exeStack = p.getExeStack();
		if(exp1.evaluate(table, hp)!=0){
			exeStack.push(this);
			exeStack.push(stmt3);
			exeStack.push(statement);
		}
		return null;
	}
	
	public String toString(){
		return "for (" + stmt1 + exp1 + stmt3 + ") then " + statement;
	}
}
