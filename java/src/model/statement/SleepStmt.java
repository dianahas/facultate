package model.statement;

import model.ProgState;

public class SleepStmt implements Statement {
	private int nr;
	
	public SleepStmt(int nr) {
		this.nr = nr;
	}
	@Override
	public ProgState execute(ProgState p) {
		if(nr != 0){
			nr--;
			p.getExeStack().push(new SleepStmt(nr));
		}
		return null;	
	}
	
	public String toString(){
		return "sleep (" + nr + ")";
	}
}
