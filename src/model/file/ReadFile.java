package model.file;
import java.io.*;

import model.ProgState;
import model.statement.Statement;
import utils.InterpretorException;

public class ReadFile implements Statement{
	private String fileId,varName;
	
	public ReadFile(String fileId,String varName){
		this.fileId = fileId;
		this.varName = varName;
	}
	
	public ProgState execute(ProgState p){
		Integer e = p.getSymbolTable().getValue(fileId);
		if(e==null)
			throw new InterpretorException("no such value in table");
		FileData d = p.getFileTable().getValue(e);
		if(d==null)
			throw new InterpretorException("no such file");
		BufferedReader br = d.getReader();
		Integer v;
		try{
			String s = br.readLine();
			
			if(s==null)
				v=0;
			else v = Integer.parseInt(s);
			p.getSymbolTable().add(varName, v);
		}catch(IOException|NumberFormatException f){
			throw new InterpretorException("altceva");
		}
		return null;	
	}
	
	public String toString(){
		StringBuffer s=new StringBuffer();
		s.append("Read: ");
		s.append(fileId);
		return s.toString();
	}
}
