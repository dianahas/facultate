package repository;
import java.util.*;

import model.ProgState;

public interface IRepository {
	//ProgState getCurrent();
	void add(ProgState p);
	void logPrgStateExec(ProgState p);
	List<ProgState> getProgStates();
	void setProgState(List<ProgState> e);
	
	void serProg(String fileName);
	ProgState deserialize(String fName);
}
