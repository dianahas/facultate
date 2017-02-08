package model;
import utils.*;
import java.io.*;
public interface Expression extends Serializable{
	public int evaluate(ISymbolTable<String,Integer> t,IHeap<Integer,Integer> hp);
}
