package model.heap;
import model.*;
import model.statement.*;
import utils.IHeap;
import utils.ISymbolTable;
import utils.InterpretorException;

public class WriteHeap implements Statement {
	private String varName;
	private Expression exp;
	
	public WriteHeap(String varName,Expression expp){
		this.varName = varName;
		exp = expp;
	}
	
	@Override
	public ProgState execute(ProgState p) {
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		IHeap<Integer,Integer> hp = p.getHeap();
		Integer addr = t.getValue(varName);
		if(addr == null)
			throw new InterpretorException("invalid address");
		int result = exp.evaluate(t, hp);
		if (hp.contains(addr))
			p.getHeap().setValue(addr, result);
		else throw new InterpretorException("invalid address");
		return null;
	}
	
	public String toString(){
		return "wH(" + varName + "=" + exp + ")";
	}

}
