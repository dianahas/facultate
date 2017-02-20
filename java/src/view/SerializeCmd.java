package view;

import java.util.*;
import controller.Controller;
import utils.*;

public class SerializeCmd extends Command{
	
	private Controller ctrl;
	public SerializeCmd(Controller ctrl, String key, String description) {
		super(key, description);
		this.ctrl = ctrl;
	}
	@Override
	public void execute() {
		Scanner scanner = new Scanner(System.in);
		String fileName = scanner.nextLine();
		try{
			this.ctrl.serialize(fileName);
		} catch(InterpretorException e){
			System.out.println(e.what());
		}
	}

}
