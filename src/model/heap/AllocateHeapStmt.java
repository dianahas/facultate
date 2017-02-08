package model.heap;
import model.*;
import model.statement.Statement;
import utils.*;

public class AllocateHeapStmt implements Statement{
	private String varName;
	private Expression exp;
	
	public AllocateHeapStmt(String name,Expression ex){
		varName = name;
		exp = ex;
	}
	
	@Override
	public ProgState execute(ProgState p) {
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		IHeap<Integer,Integer> hp = p.getHeap();
		int result = exp.evaluate(t,hp);
		int id = IdGenerator.generator();
		if(p.getSymbolTable().contains(varName))
			p.getSymbolTable().setValue(varName,id);
		else{
			p.getSymbolTable().add(varName, id);
		}
		p.getHeap().add(id, result);
		return null;
	}
	
	public String toString(){
		StringBuffer s=new StringBuffer();
		s.append(varName);
		s.append(" = ");
		s.append(exp);
		return s.toString();
	}
	
}
