package model.statement;
import model.Expression;
import model.ProgState;
import utils.*;
public class AssignStmt implements Statement{
	private Expression expr;
	private String var;
	
	public AssignStmt(Expression exp,String a){
		expr = exp;
		var = a;
	}
	@Override
	public ProgState execute(ProgState p){
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		IHeap<Integer,Integer> hp = p.getHeap();
		int result = expr.evaluate(t,hp);
		t.add(var,result);
		return null ;
	}
	
	public String toString(){
		return " " + var + "=" + expr;
	}

}
