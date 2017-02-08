package gui;
import model.*;
import model.file.CloseFile;
import model.file.OpenFileStmt;
import model.file.ReadFile;
import model.heap.AllocateHeapStmt;
import model.heap.ReadHeap;
import model.heap.WriteHeap;
import model.statement.*;

import javafx.event.ActionEvent;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import com.sun.org.apache.bcel.internal.generic.NEW;

import controller.Controller;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import repository.Repository;

public class ProgramsController {

    @FXML
    private Button CancelButton;

    @FXML
    private Button ChooseButton;

    @FXML
    private ListView<String> AllPrograms;

    private Stage dialogStage;
    private Controller controller;  
    private MainWindowController mainWindowController;
    
    @FXML
    void handleCancel(ActionEvent event) {
    	dialogStage.close();
    }
    
    @FXML
    void handleChooseExampleButton(MouseEvent event) {
    	int index = AllPrograms.getFocusModel().getFocusedIndex();
        if (index < 0) return;

        String logFile = "fileRepo" + index + ".txt";
        Statement statement = getProgram(index);

        Repository repository = new Repository(logFile);
        controller.setRepository(repository);
        controller.add(statement);

        mainWindowController.update();
        dialogStage.close();
    }

    public void setController(Controller controller, MainWindowController mainWindowController, Stage dialogStage) {
	    this.controller = controller;
	    this.dialogStage = dialogStage;
	    this.mainWindowController = mainWindowController;
	}
    
    @FXML
    private void initialize() {
    	populateList();
    }
    
    private void populateList(){
    	List<Statement> programs=new ArrayList<Statement>();
	
    	Statement progr;
    	int index = 0;
	
    	while (true){
    		progr = getProgram(index);
    		index ++;
		
    		if(progr == null)
    			break;
		
    		programs.add(progr);
    	}
	
    	ObservableList<String> model = FXCollections.observableArrayList(
            programs.stream().map(p -> p.toString()).collect(Collectors.toList())
    			);
	
    	AllPrograms.setItems(model);
    }

    private Statement getProgram(int option) {
	    switch (option) {
	        case 0: {
	            /* a = 3/0; */
	
	            return new AssignStmt(new ArithmeticExpr('/',new ConstExp(3), new ConstExp(0)), "a");
	        }
	
	        case 1: {
	            /* v = 2;
	             * PRINT(v); */
	
	            return new CompStmt(
	                    new AssignStmt(new ConstExp(2), "v"),
	                    new PrintStmt(new VarExpr("v")));
	        }
	
	        case 2: {
	            /* a = 2 + 3 * 5;
	             * b = a + 1;
	             * PRINT(b); */
	
	            return new CompStmt(
	                    new AssignStmt(
	                            new ArithmeticExpr(
	                                    '+',
	                                    new ArithmeticExpr(
	                                            '*',
	                                            new ConstExp(5),
	                                            new ConstExp(3)
	                                    ),
	                                    new ConstExp(2)),
	                            "a"),
	                    new CompStmt(
	                            new AssignStmt(
	                                    new ArithmeticExpr(
	                                            '+',
	                                            new ConstExp(1),
	                                            new VarExpr("a")),
	                                    "b"),
	                            new PrintStmt(new VarExpr("b"))));
	        }

	        case 3: {
	            /* a = 2 - 2;
	             * IF(a) THEN(
	             *    v = 2
	             * ) ELSE(
	             *    v = 3
	             * );
	             * PRINT(v) */
	
	            return new CompStmt(
	                    new AssignStmt(
	                            new ArithmeticExpr(
	                                    '-',
	                                    new ConstExp(2),
	                                    new ConstExp(2)
	                            ),
	                            "a"),
	                    new CompStmt(
	                            new IfStmt(
	                                    new VarExpr("a"),
	                                    new AssignStmt(
	                                            new ConstExp(2),
	                                            "v"
	                                    ),
	                                    new AssignStmt(
	                                            new ConstExp(3),
	                                            "v"
	                                    )
	                            ),
	                            new PrintStmt(new VarExpr("v"))
	                    )
	            );
	        }
	
	        case 4: {
	            /* a = 3;
	             * b = (a * 10 - 10 * 3);
	             * IF(b) THEN(
	             *   c = 100 / b;
	             *   PRINT(c);
	             * ) ELSE(
	             *    IF(a - 2) THEN (
	             *      PRINT(b);
	             *      PRINT(2 * a + 3);
	             *      c = a;
	             *      PRINT(c);
	             * );
	             * */
	
	            return new CompStmt(
	                    new AssignStmt(new ConstExp(3),"a"
	                    ),
	                    new CompStmt(
	                            new AssignStmt(
	                                    new ArithmeticExpr('-',
	                                            new ArithmeticExpr('*',new ConstExp(3),new ConstExp(10)),
	                                            new ArithmeticExpr( '*',new ConstExp(10),new VarExpr("a"))),
	                                    "b"
	                            ),
	                            new IfStmt(
	                                    new VarExpr("b"),
	                                    new CompStmt(
	                                            new AssignStmt(
	                                                    new ArithmeticExpr('/',new VarExpr("b"),new ConstExp(100)),
	                                                    "c"
	                                            ),
	                                            new PrintStmt(new VarExpr("c")
	                                            )
	                                    ),
	                                    new IfStmt(
	                                            new ArithmeticExpr('-',new ConstExp(2),new VarExpr("a")
	                                            ),
	                                            new CompStmt(
	                                                    new PrintStmt(new VarExpr("b")
	                                                    ),
	                                                    new CompStmt(
	                                                            new PrintStmt( new ArithmeticExpr('+',new ConstExp(3),
	                                                                            new ArithmeticExpr('*',new VarExpr("a"),new ConstExp(2)
	                                                                            )
	                                                                    )
	                                                            ),
	                                                            new CompStmt(
	                                                                    new AssignStmt(new VarExpr("a"), "c"
	                                                                    ),
	                                                                    new PrintStmt(new VarExpr("c")
	                                                                    )
	                                                            )
	                                                    )
	                                            ),
	                                            null
	                                    )
	                            )
	                    )
	            );
	        }
	
	        case 5: {
	            /* a = 3;
	             * b = a + 3;
	             * d = c - 3;
	             * PRINT(a);
	             * PRINT(b);
	             * PRINT(d);
	             */
	
	            return new CompStmt(
	                    new AssignStmt(new ConstExp(3),"a"),
	                    new CompStmt(
	                            new AssignStmt(
	                                    new ArithmeticExpr('+',new ConstExp(3),new VarExpr("a")),"b"
	                            ),
	                            new CompStmt(
	                                    new AssignStmt(
	                                            new ArithmeticExpr( '-',new ConstExp(3), new VarExpr("c")),"d"
	                                    ),
	                                    new CompStmt(
	                                            new PrintStmt(new VarExpr("a")
	                                            ),
	                                            new CompStmt(
	                                                    new PrintStmt(new VarExpr("b")),
	                                                    new PrintStmt(new VarExpr("d"))
	                                            )
	                                    )
	                            )
	                    )
	            );
	        }
	        case 6: {
	              /* v = 10;
	               * NEW(v, 20);
	               * NEW(a, 22);
	               * PRINT(v);
	               * PRINT(100 + READHEAP(v));
	               * PRINT(100 + READHEAP(a));
	               * WRITEHEAP(a, 30)
	               * PRINT(READHEAP(a))
	               * a = 0 */

	                return new CompStmt(
	                        new AssignStmt(new ConstExp(10), "v"),
	                        new CompStmt(
	                                new AllocateHeapStmt("v", new ConstExp(20)),
	                                new CompStmt(
	                                        new AllocateHeapStmt("a", new ConstExp(22)),
	                                        new CompStmt(
	                                                new PrintStmt(new VarExpr("v")),
	                                                new CompStmt(
	                                                        new PrintStmt(
	                                                                new ArithmeticExpr(
	                                                                        '+',
	                                                                        new ReadHeap("v"),
	                                                                        new ConstExp(100))),
	                                                        new CompStmt(
	                                                                new PrintStmt(
	                                                                        new ArithmeticExpr(
	                                                                                '+',
	                                                                                new ReadHeap("a"),
	                                                                                new ConstExp(100))),
	                                                                new CompStmt(
	                                                                        new WriteHeap("a", new ConstExp(30)),
	                                                                        new CompStmt(
	                                                                                new PrintStmt(new ReadHeap("a")),
	                                                                                new AssignStmt(new ConstExp(0), "a")
	                                                                        )
	                                                                )
	                                                        )
	                                                )
	                                        )
	                                )
	                        )
	                );
	            }
	        case 7: {
	        	return new CompStmt(
                        new AssignStmt(new ConstExp(10), "v"),
                        new CompStmt(
                                new AllocateHeapStmt("a", new ConstExp(22)),
                                new CompStmt(
                                        new ForkStmt(
                                                new CompStmt(
                                                        new WriteHeap("a", new ConstExp(30)),
                                                        new CompStmt(
                                                                new AssignStmt(new ConstExp(32), "v"),
                                                                new CompStmt(
                                                                        new PrintStmt(new VarExpr("v")),
                                                                        new PrintStmt(new ReadHeap("a"))
                                                                )
                                                        )
                                                )

                                        ),
                                        new CompStmt(
                                                new PrintStmt(new VarExpr("v")),
                                                new PrintStmt(new ReadHeap("a"))
                                        )
                                )
                        )
                );
	        }
	        
	        case 8:{
	        	return new CompStmt(
	        			new AssignStmt(new ConstExp(0), "v"), 
	        			new CompStmt(
	        					new WhileStmt(new BooleanExpr("<", new VarExpr("v"), new ConstExp(3)), 
	        							new CompStmt(
	        									new ForkStmt(new CompStmt(
	        											new PrintStmt(new VarExpr("v")), 
	        											new AssignStmt(
	        													new ArithmeticExpr('+', new VarExpr("v"), new ConstExp(1)),
	        													"v"))), 
	        									new AssignStmt(new ArithmeticExpr('+', new VarExpr("v"), new ConstExp(1)),
	    	        													"v"))), new CompStmt(new SleepStmt(5), new PrintStmt(new ArithmeticExpr('*', new VarExpr("v"), new ConstExp(10))))));
	        }
	        case 9:{
	        	return new CompStmt(new AssignStmt(new ConstExp(20), "v"), 
	        			new CompStmt(new ForStmt(new AssignStmt(new ConstExp(0),"v"), new BooleanExpr("<", new VarExpr("v"), new ConstExp(3)), new AssignStmt(new ArithmeticExpr('+', new VarExpr("v"), new ConstExp(1)), "v"),
	        									new ForkStmt(new CompStmt(new PrintStmt(new VarExpr("v")), new AssignStmt(new ArithmeticExpr('+', new VarExpr("v"), new ConstExp(1)), "v")))), new PrintStmt(new ArithmeticExpr('*', new VarExpr("v"), new ConstExp(10)))));	        
	        	}
	        case 10:{
	        	/* OPENRFILE(var_f, "test.in");
                 * READFILE(var_f, var_c);
                 * IF(var_c) THEN(
                 *   READFILE(var_f, var_c);
                 *   PRINT(var_c);
                 * ) ELSE(
                 *   PRINT(var_c);
                 * );
                 * CLOSERFILE(var_f); */

                return new CompStmt(new CompStmt(new OpenFileStmt("test.in","inFile"), new ReadFile("inFile", "a")),new PrintStmt(new VarExpr("a")));
	        }
	        case 11:{
	        	return new CompStmt(new AllocateHeapStmt("v1", new ConstExp(20)), 
	        			new CompStmt(new AllocateHeapStmt("v2", new ConstExp(30)), 
	        					new CompStmt(new NewLockStmt("x"), 
	        							new CompStmt(new ForkStmt(new CompStmt(
	        									new ForkStmt(new CompStmt(
	        											new LockStmt("x"), new CompStmt(new WriteHeap("v1", new ArithmeticExpr('-', new ReadHeap("v1"), new ConstExp(1))), 
	        													new UnlockStmt("u")))), 
	        									new CompStmt(new LockStmt("x"), new CompStmt(new WriteHeap("v1", new ArithmeticExpr('+', new ReadHeap("v1"), new ConstExp(1))), 
	        											new UnlockStmt("x"))))), 
	        									new CompStmt(new NewLockStmt("q"), 
	        											new CompStmt(new ForkStmt(new CompStmt(
	        													new ForkStmt(new CompStmt(
	        															new LockStmt("q"), new CompStmt(
	        																	new WriteHeap("v2", new ArithmeticExpr('+', new ReadHeap("v2"), new ConstExp(5))), 
	        																	new UnlockStmt("q")))), 
	        													new CompStmt(new AssignStmt(new ConstExp(100), "m"), 
	        															new CompStmt(new LockStmt("q"), new CompStmt(new WriteHeap("v2", new ArithmeticExpr('+', new ReadHeap("v2"), new ConstExp(1))), 
	        																	new UnlockStmt("q")))))), 
	        													new CompStmt(new AssignStmt(new ConstExp(200), "z"), 
	        															new CompStmt(new AssignStmt(new ConstExp(300), "z"), 
	        																	new CompStmt(new AssignStmt(new ConstExp(400), "z"), 
	        																			new CompStmt(new LockStmt("x"), 
	        																					new CompStmt(new PrintStmt(new ReadHeap("v1")), 
	        																							new CompStmt(new UnlockStmt("x"), 
	        																									new CompStmt(new LockStmt("q"), 
	        																											new CompStmt(new PrintStmt(new ReadHeap("v2")), new UnlockStmt("q")))))))))))))));
	        	}
	        default: {
	            return null;
	        }
	    }
	    
	}
}

