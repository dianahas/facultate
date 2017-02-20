package model;
import java.io.Serializable;

import model.file.*;
import model.statement.*;
import utils.*;

public class ProgState implements Serializable{
	private IExeStack<Statement> exe;
	private ISymbolTable<String,Integer> t1;
	private IOutput<Integer> out;
	private IFileTable<Integer,FileData> file;
	private IHeap<Integer,Integer> heap;
	private ILockTable<Integer, Integer> lockTable;
	private Statement stm;
	private int id;
	
	public ProgState(IExeStack<Statement> exe, ISymbolTable<String,Integer> t1, IOutput<Integer> out,IFileTable<Integer,FileData> file,IHeap<Integer,Integer> heap,ILockTable<Integer, Integer> lockTable, Statement stm){
		this.exe = exe;
		this.t1 = t1;
		this.out = out;
		this.file = file;
		this.heap = heap;
		this.lockTable = lockTable;
		this.stm = stm;
		this.id = generator.generateProgStateId();
		this.exe.push(stm);
	}
	
	public String toString(){
		StringBuffer s = new StringBuffer();
		s.append("the prog state with the id");
		s.append(id);
		s.append("the stack: ");
		s.append(exe);
		s.append("\n");
		s.append("the table: ");
		s.append(t1);
		s.append("\nThis is the file table\n");
		s.append(file);
		s.append("\nthe output: ");
		s.append(out);
		s.append("\nthe heap: ");
		s.append(heap);
		s.append("\n");
		return s.toString();
	}
	
	public int getId(){
		return id;
	}

	public IExeStack<Statement> getExeStack() {
		return exe;
	}

	public ISymbolTable<String,Integer> getSymbolTable() {
		return t1;
	}
	
	public IFileTable<Integer,FileData> getFileTable() {
		return file;
	}
	
	public IHeap<Integer,Integer> getHeap() {
		return heap;
	}
	
	public ILockTable<Integer, Integer> getLockTable(){
		return lockTable;
	}

	public Statement getStm() {
		return stm;
	}

	public void setStm(Statement stm) {
		this.stm = stm;
	}
	
	public IOutput<Integer> getOutput() {
		return out;
	}
	
	public boolean isNotCompleted(){
		return !exe.isEmpty();
	}
	
	public ProgState oneStep() {
		if(exe.isEmpty())
			throw new InterpretorException("execution stack is empty");
		Statement s = exe.pop();
		return s.execute(this);
	}
	
	public static class generator{
		private static int fileTableId = 0, heapId = 0, PrgStateId = 0;
		public static int generateProgStateId(){
			return ++PrgStateId;
		}
		public static int generateheapId(){
			return ++heapId;
		}
		public static int generatefileTableId(){
			return ++fileTableId;
		}
	}
}
