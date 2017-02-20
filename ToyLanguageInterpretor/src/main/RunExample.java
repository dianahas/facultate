package main;
import controller.*;
import utils.InterpretorException;
import view.*;

public class RunExample extends Command{
	private Controller ctr;
	
	public RunExample(String key, String desc,Controller ctr){
		super(key, desc);
		this.ctr=ctr;
	}
	
	@Override
	public void execute(){
		try{
			ctr.allStep();
		}
		catch (InterpretorException a){
			System.out.println(a.what());
			a.printStackTrace();
		} catch (InterruptedException e) {
			e.printStackTrace();
		} 
	}
}
