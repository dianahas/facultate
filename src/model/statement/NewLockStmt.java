package model.statement;

import java.util.concurrent.locks.*;

import model.ProgState;
import utils.ILockTable;
import utils.ISymbolTable;
import utils.IdLockGener;

public class NewLockStmt implements Statement {
	private String var;
	
	public NewLockStmt(String var) {
		this.var = var;
	}
	@Override
	public ProgState execute(ProgState p) {
		int newFreeLoc = -1;
		ISymbolTable <String,Integer> t = p.getSymbolTable();
		ILockTable<Integer, Integer> lt = p.getLockTable();
		Lock lock = new ReentrantLock();
		lock.lock();
		int id = IdLockGener.generator();
		if(t.contains(var))
			p.getSymbolTable().setValue(var, id);
		else p.getSymbolTable().add(var, id);
		p.getLockTable().add(id, newFreeLoc);
		lock.unlock();
		return null;
	}
	
	public String toString(){
		return "new lock( " + var + ")";
	}
}
