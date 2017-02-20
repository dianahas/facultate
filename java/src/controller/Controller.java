package controller;
import utils.*;

import java.util.*;
import java.util.concurrent.*;
import java.util.stream.Collectors;

import model.*;
import model.file.FileData;
import model.statement.Statement;
import repository.*;
public class Controller {
	private IRepository repo;
	private ExecutorService executor;
	private static int id = 1;
	public Controller(IRepository repo){
		this.repo=repo;
	}
	
	Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues,Map<Integer,Integer> heap){
		return heap.entrySet().stream().filter(e->symTableValues.contains(e.getKey())).collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
			}
	
	public void add(Statement st) {
		ExeStack<Statement> exe = new ExeStack<>();
		SymbolTable<String, Integer> symbolTable = new SymbolTable<>();
		Output<Integer> output = new Output<>();
		FileTable<Integer, FileData> fileTable = new FileTable<>();
		Heap<Integer, Integer> heap = new Heap<>();
		LockTable<Integer, Integer> lockTable = new LockTable<>();
        ProgState state = new ProgState(exe,symbolTable,output,fileTable,heap,lockTable,st);
        this.repo.add(state);
        id++;
    }
/*
	public void executeAll() {
		ProgState currentState = repo.getCurrent();
		IExeStack<Statement> stack = currentState.getExeStack();
			while(!stack.isEmpty()){
				executeOneStep(currentState);
				List<Integer> list = currentState.getSymbolTable().values();
				currentState.getHeap().setHeap(conservativeGarbageCollector(list,currentState.getHeap().getHeap()));
				repo.logPrgStateExec();
			}
		}
*/		
	public void serialize(String fileName) {
		this.repo.serProg(fileName);
	}
	
	public ProgState deserialize(String fName){
		return this.repo.deserialize(fName);
	}

	public List<ProgState> remCompPrg(List<ProgState> l){
		return l.stream().filter(p->p.isNotCompleted()).collect(Collectors.toList());
	}
	
	public void OneStepForAll(List<ProgState> those) throws InterruptedException{
		those.forEach(prg->this.repo.logPrgStateExec(prg));
		List<Callable<ProgState>> collList= those.stream().map((ProgState prg)->(Callable<ProgState>) (()->prg.oneStep())).collect(Collectors.toList());
		List<ProgState> these = executor.invokeAll(collList).stream()
				.map(future->{try{
					return future.get();
					}
				catch(Exception e){
                    System.err.println("There is an exception in Controller::oneStepForAllPrograms");
                    e.printStackTrace();
                	}
				return null;
		}).filter(p->p!=null).collect(Collectors.toList());
		those.addAll(these);
		those.forEach(prg->repo.logPrgStateExec(prg));
		repo.setProgState(those);
	}
	
	public void allStepGUI() throws InterruptedException {
		 executor = Executors.newFixedThreadPool(2);
		 //remove the completed programs
		 List<ProgState> prgList=remCompPrg(repo.getProgStates());
		 if(prgList.size() ==0){
		 //display a window message saying that the execution terminates
		 executor.shutdownNow();
		 }
		 else {
			OneStepForAll(prgList);
		} 
		 executor.shutdownNow();
	}
	
	public void allStep() throws InterruptedException{
		executor = Executors.newFixedThreadPool(2);
		while(true){
			List<ProgState> list = removeCompletedProg(repo.getProgStates());
			if(list.size()==0)
				break;
			OneStepForAll(list);
		}
		executor.shutdownNow();
	}

	private List<ProgState> removeCompletedProg(List<ProgState> progStates) {
		 return progStates.stream()
	                .filter(ProgState::isNotCompleted)
	                .collect(Collectors.toList());
	}
	
	public List<ProgState> getCurrentProgramStates() {
        return repo.getProgStates();
    }
	
	public String currentProgramStatesToString() throws InterpretorException {
        StringBuilder result = new StringBuilder();
        for (ProgState programState : repo.getProgStates()) {
            result.append(programState + "\n");
        }
        return result.toString();
    }
	
	public void setRepository(Repository repository) {
        this.repo = repository;
    }
}
