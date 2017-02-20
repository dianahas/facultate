package model.statement;
import model.*;
import utils.*;

public class WhileStmt implements Statement {
	private Expression expr;
	private Statement stmt;
	
	public WhileStmt(Expression expr, Statement st) {
		this.expr = expr;
		stmt = st;
	}
	@Override
	public ProgState execute(ProgState p) {
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		IHeap<Integer,Integer> hp = p.getHeap();
		int result = expr.evaluate(t, hp);
		IExeStack<Statement> exe= p.getExeStack();
		if(result!=0){
			exe.push(this);
			exe.push(stmt);
		}
		return null;
	}
	
	public String toString(){
		return " while(" + expr + ")" + stmt;
	}

}
