package utils;

public class InterpretorException extends RuntimeException {
	
	private static final long serialVersionUID = 1L;
	private String desc;
	private Throwable e;
	public InterpretorException(String s){
		desc=s;
	}
	public InterpretorException(String s,Throwable ex){
		desc=s;
		e=ex;
	}
	public String what(){
		return desc;
	}
	public Throwable exception(){
		return e;
	}

}
