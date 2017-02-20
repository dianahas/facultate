package model.statement;

import java.util.concurrent.locks.*;

import model.ProgState;
import utils.InterpretorException;

public class LockStmt implements Statement {
	private String var;
	
	public LockStmt(String var) {
		this.var = var;
	}
	@Override
	public ProgState execute(ProgState p) {
		Integer foundIndex = p.getSymbolTable().getValue(var);
		ReadWriteLock readWriteLock = new ReentrantReadWriteLock();
		readWriteLock.readLock().lock();
		if(foundIndex == null)
			throw new InterpretorException("no such value in symbol table");
		if(!p.getLockTable().contains(foundIndex)){
			throw new InterpretorException("no such value in lock table");
		}
		else if(p.getLockTable().getValue(foundIndex) == -1){
			//readWriteLock.writeLock().lock();
			p.getLockTable().setValue(foundIndex, p.getId());
			//readWriteLock.writeLock().unlock();
		}
		else {
			//readWriteLock.writeLock().lock();
			p.getExeStack().push(new LockStmt(var));
			//readWriteLock.writeLock().unlock();
		}
		readWriteLock.readLock().unlock();

		return null;
	}
	
	public String toString(){
		return "lock( " + var + ")";
	}
}
