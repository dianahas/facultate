package repository;
import java.io.*;
import java.util.*;

import model.*;
import model.file.FileData;
import model.statement.Statement;
import utils.InterpretorException;


public class Repository implements IRepository{
	private List<ProgState> progStates;
	private String fileName;
	
	public Repository(ProgState p,String file){
		progStates=new ArrayList<>();
		fileName=file;
		progStates.add(p);
	}
	
	public Repository(String file) {
		progStates = new ArrayList<>();
		fileName = file;
	}
	public void add(ProgState prog){
		progStates.add(prog);
	}
	public List<ProgState> getProgStates(){
		return progStates;
	}
	public void setProgState(List<ProgState> newP){
		progStates = newP;
	}
	
	@Override
	public void logPrgStateExec(ProgState p) {
		try(PrintWriter logFile=new PrintWriter(new BufferedWriter(new FileWriter(fileName, true)))){
			logFile.println("Id: ");
			logFile.println(p.getId());
			logFile.println("ExeStack: ");
			for(Statement s:p.getExeStack().getAll())
				logFile.println(s);
			logFile.println();
			logFile.println("SymbolTable: ");
			for(Map.Entry<String, Integer> s:p.getSymbolTable().getAll())
				logFile.println(s.getKey()+"-->"+s.getValue());
			logFile.println();
			logFile.println("Output: ");
			for(Integer s:p.getOutput().getAll())
				logFile.println(s.toString());
			logFile.println();
			logFile.println("FileTable");
			for(Map.Entry<Integer, FileData> s: p.getFileTable().getAll())
			{
				logFile.println(s.getKey()+"-->"+s.getValue());
			}
			logFile.println();
			logFile.println("Heap");
			for(Map.Entry<Integer, Integer> s: p.getHeap().getAll())
			{
				logFile.println(s.getKey()+"-->"+s.getValue());
			}
			logFile.println();
			logFile.println("LockTable");
			for(Map.Entry<Integer, Integer> s: p.getLockTable().getAll())
			{
				logFile.println(s.getKey()+"-->"+s.getValue());
			}
			logFile.println();
		} catch (IOException e) {
			e.printStackTrace();
		};
		
	}
	
	@Override
	public ProgState deserialize(String fileName) {
		try{
			ObjectInputStream str = new ObjectInputStream(new FileInputStream(fileName));
			Object o = str.readObject();
			if(o instanceof ProgState)
				return (ProgState) o;
			throw new InterpretorException("cannot deserialize");
		
		}catch(Exception e){
			throw new InterpretorException("cannot deserialize");
		}
	}

	public void serProg(String fileName) {
		try{
			ObjectOutputStream str = new ObjectOutputStream(new FileOutputStream(fileName));
			str.writeObject(progStates);
		}catch(Exception e){
			throw new InterpretorException("cannot serialize");
		}
	}
}

