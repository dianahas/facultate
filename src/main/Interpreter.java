package main;
import utils.*;
import model.*;
import model.file.*;
import model.heap.AllocateHeapStmt;
import model.heap.ReadHeap;
import model.heap.WriteHeap;
import model.statement.*;
import view.*;
import repository.*;

import java.nio.charset.CoderMalfunctionError;

import controller.*;
public class Interpreter {

	public static void main(String[] args) {
		
		Statement st1 = new CompStmt(
                new AssignStmt(new ConstExp(10), "v"),
                new AllocateHeapStmt("a", new ConstExp(22))
        );
		
		Statement st2 = new ForkStmt(
                new CompStmt(
                        new WriteHeap("a", new ConstExp(30)),
                        new AssignStmt(new ConstExp(32), "v")
                        )
        );
		
		Statement st3 = new ForkStmt(
                new CompStmt(
                		new PrintStmt(new VarExpr("v")),
                        new PrintStmt(new ReadHeap("a"))
                        )
        );
		
		Statement st4 = new CompStmt(
                new PrintStmt(new VarExpr("v")),
                new PrintStmt(new ReadHeap("a"))
        );
		
		Statement ret = new CompStmt(st1, new CompStmt(st2, new CompStmt(st3,st4)));
		
		//Statement st8 = new CompStmt(new AssignStmt(new ConstExp(10),"v"),new CompStmt(new AllocateHeapStmt("v",new ConstExp(22)),new CompStmt(new ForkStmt(new CompStmt(new WriteHeap("a",new ConstExp(30)),new CompStmt(new AssignStmt(new ConstExp(32),"v"),new PrintStmt(new VarExpr("v"))))),new CompStmt(new PrintStmt(new ReadHeap("a")),new CompStmt(new PrintStmt(new VarExpr("v")),new PrintStmt(new ReadHeap("a")))))));		
		ProgState prg8=new ProgState(new ExeStack<Statement>(),new SymbolTable<String,Integer>(),new Output<Integer>(),new FileTable<Integer,FileData>(),new Heap<Integer,Integer>(),ret);
		IRepository repo8=new Repository(prg8,"file30.txt");
		Controller ctr8=new Controller(repo8);
		
		TextMenu menu = new TextMenu();
		menu.addCommand(new ExitCommand("0", "exit"));
		menu.addCommand(new RunExample("10",ret.toString(),ctr8));
		menu.show();
	}

}
