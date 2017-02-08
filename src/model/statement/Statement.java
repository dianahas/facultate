package model.statement;

import java.io.Serializable;
import model.ProgState;

public interface Statement extends Serializable{
	public ProgState execute(ProgState p);
}
