package model.file;
import java.io.*;
import java.util.Map;

import model.ProgState;
import model.statement.Statement;
import utils.*;

public class OpenFileStmt implements Statement{
	private String fileName;
	private String idDescName;
	
	public OpenFileStmt(String name,String id){
		fileName = name;
		idDescName = id;
	}
	
	private boolean isOpen(String fileName2, IFileTable<Integer,FileData> fileTable) {
		for(Map.Entry<Integer, FileData> it: fileTable.getAll()){
			if(fileName2.equals(it.getValue().getFileName()))
				return true;
		}
		return false;
	}
	
	@Override
	public ProgState execute(ProgState p){
		if(isOpen(fileName,p.getFileTable()))
			throw new InterpretorException("file has already been opened");
		try{
			BufferedReader buffer = new BufferedReader(new FileReader(fileName));
			FileData fd = new FileData(fileName,buffer);
			int id = IdGenerator.generator();
			p.getFileTable().add(id,fd);
			p.getSymbolTable().add(idDescName, id);
		}
		catch(IOException e){
			throw new InterpretorException("cannot open file",e);
		}
		return null;
	} 
	
	public String toString(){
		StringBuffer s=new StringBuffer();
		s.append("Open: ");
		s.append(fileName);
		return s.toString();
	}

}
