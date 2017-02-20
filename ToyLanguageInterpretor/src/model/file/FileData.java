package model.file;
import java.io.BufferedReader;

public class FileData {
	private String FName;
	private BufferedReader buffer;
	
	public FileData(String name,BufferedReader buff){
		FName = name;
		buffer=buff;
	}
	
	public String toString(){
		return FName;
	}

	public BufferedReader getReader() {
		return buffer;
	}
	public String getFileName(){
		return FName;
	}
}
