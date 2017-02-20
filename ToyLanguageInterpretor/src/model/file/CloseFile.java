package model.file;
import java.io.*;

import model.ProgState;
import model.statement.Statement;
import utils.InterpretorException;

public class CloseFile implements Statement{
	private String fileId;
	
	public CloseFile(String fileId){
		this.fileId = fileId;
	}
	
	@Override
	public ProgState execute(ProgState p){
		Integer e = p.getSymbolTable().getValue(fileId);
		if(e == null)
			throw new InterpretorException("no such valueeee in table");
		FileData d = p.getFileTable().getValue(e);
		if(d == null)
			throw new InterpretorException("no such file");
		BufferedReader br = d.getReader();
		try{
			br.close();
		}
		catch(IOException f){
			throw new InterpretorException("problema");
		}
		p.getFileTable().remove(e);
		return null;
	}
	
	public String toString(){
		StringBuffer s=new StringBuffer();
		s.append("Close: ");
		s.append(fileId);
		return s.toString();
	}	

}
