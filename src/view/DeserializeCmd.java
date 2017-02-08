package view;

import java.util.Scanner;

import controller.Controller;
import model.ProgState;
import utils.InterpretorException;

public class DeserializeCmd extends Command{
	private Controller ctrl;
	public DeserializeCmd(Controller ctrl,String key, String desc)
	{
		super(key,desc);
		this.ctrl=ctrl;
	}
	public void execute(){
		Scanner scn=new Scanner(System.in);
		String fN=scn.nextLine();
		try{
			ProgState p= ctrl.deserialize(fN);
			System.out.println(p);
		}
		catch(InterpretorException e)
		{
			System.out.println(e.what());
		}
	}

}
