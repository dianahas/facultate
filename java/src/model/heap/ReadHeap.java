package model.heap;
import model.*;
import utils.IHeap;
import utils.ISymbolTable;
import utils.InterpretorException;

public class ReadHeap implements Expression{
	private String varName;
	
	public ReadHeap(String varName){
		this.varName = varName;
	}
	
	@Override
	public int evaluate(ISymbolTable<String, Integer> t,IHeap<Integer,Integer> hp) {
			Integer location = t.getValue(varName);
			if (location == null)
				throw new InterpretorException("no such variable in table");
			Integer value = hp.getValue(location);
			if(value == null)
				throw new InterpretorException("heap memory not allocated for that value");
		return value;
	}
	
	public String toString(){
		return "rH(" + varName + ")"; 
	}
}
