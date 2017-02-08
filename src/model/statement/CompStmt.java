package model.statement;
import model.ProgState;
import utils.*;
public class CompStmt implements Statement{
	
	private Statement first;
	private Statement second;
	
	public CompStmt(Statement first, Statement second){
		this.first = first;
		this.second = second;
	}
	
	@Override
	public ProgState execute(ProgState p) {
		IExeStack<Statement> stack1 = p.getExeStack();
		stack1.push(second);
		stack1.push(first);
		return null;
	}
	
	public String toString(){
		return "{" + first + ";" + second + "}";
	}
}
