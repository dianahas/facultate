package gui;
import controller.Controller;
import repository.*;
import utils.InterpretorException;
import model.*;
import model.heap.*;
import model.statement.*;
import model.file.*;

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.stream.Collector;
import java.util.stream.Collectors;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.layout.BorderPane;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.BufferedReader;
import java.io.IOException;

public class MainWindowController {

    @FXML
    private TableView<Map.Entry<String, Integer>> SymbolTableTable;

    @FXML
    private TableColumn<Map.Entry<String, Integer>,String> SymbolTableValue;
    
    @FXML
    private TableColumn<Map.Entry<String, Integer>, String> SymbolTableKey;

    @FXML
    private Button ChooseExampleButton;

    @FXML
    private Button RunOneStepButton;

    @FXML
    private TableView<Map<Integer, String>> FileTableTable;

    @FXML
    private TableColumn<Map<Integer, String>, String> FileTableValue;
    
    @FXML
    private TableColumn<Map<Integer, String>, String> FileTableKey;
    
    @FXML
    private TableView<Map.Entry<Integer, Integer>> heapTable;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> HeapKey;
    
    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> HeapValue;
    
    @FXML
    private ListView<String> programStates;

    @FXML
    private ListView<String> ExecutionStackList;

    @FXML
    private ListView<Integer> OutputList;
    
    @FXML
    private TableView<Map.Entry<Integer, Integer>> LockTableTable;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> LockTableKey;

    @FXML
    private TableColumn<Map.Entry<Integer, Integer>, String> LockTableValue;

    @FXML
    private Text programStatesTitle;

    private Controller ctrl;
    
    public void setController(Controller controller) {
		ctrl = controller;
	}
    
    @FXML
    void handleChooseExample(ActionEvent event) {
    	try {
            // Load the fxml file and create a new stage for the popup dialog.
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(ProgramsController.class.getResource("Programs.fxml"));
            BorderPane root = loader.load();

            // Create the dialog Stage.
            Stage dialogStage = new Stage();
            //dialogStage.setTitle("Edit Student");
            dialogStage.initModality(Modality.WINDOW_MODAL);
            Scene scene = new Scene(root);
            dialogStage.setScene(scene);

            ProgramsController programsController = loader.getController();
            programsController.setController(ctrl, this, dialogStage);

            dialogStage.show();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
   
    @FXML
    void handleRunOneStep(ActionEvent event) throws InterruptedException {
           ctrl.allStepGUI();
           update();
    }
    
    private void populateProgramStates(){
    	List<ProgState> programs = ctrl.getCurrentProgramStates();
    	
    	ObservableList<String> model = FXCollections.observableArrayList(
    			programs.stream().map(p -> "Program #" + p.getId()).collect(Collectors.toList())
        );
    	programStatesTitle.setText("Program States: " + programs.size());
    	programStates.setItems(model);
    	programStates.refresh();
    }
    
    @FXML
    void handleUpdateProgramState() {
    	update();
    }
    
    public void update() {
        populateProgramStates();

        int index = programStates.getFocusModel().getFocusedIndex();
        if (index < 0 && !programStates.getItems().isEmpty()) {
            programStates.getFocusModel().focus(0);
            index = 0;
        }

        populateHeap(index);
        populateOutput(index);
        populateFileTable(index);
        populateSymbolTable(index);
        populateExecutionStack(index);
        populateLockTable(index);
    }
    
    @FXML
    private void initialize() {
        HeapKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        HeapValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));
        
        LockTableKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        LockTableValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));

        FileTableKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue() + ""));

        FileTableValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue() + ""));

        SymbolTableKey.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getKey() + ""));

        SymbolTableValue.setCellValueFactory(
                p -> new SimpleStringProperty(p.getValue().getValue() + ""));
    }
    
    private void populateExecutionStack(int index) {
        ObservableList<String> model;

        if (index == -1) {
            model = FXCollections.observableArrayList(new ArrayList<>());

        } else {
        	List<ProgState> programs = ctrl.getCurrentProgramStates();
    		ProgState prgr = programs.get(index);
            List<Statement> all_elements = iterableToList(prgr.getExeStack().getAll());
            List<String> elements = all_elements.stream().map(p -> p.toString()).collect(Collectors.toList());

            model = FXCollections.observableArrayList(elements);
        }

        ExecutionStackList.setItems(model);
        ExecutionStackList.refresh();
    }
    
    private void populateHeap(int index){
    	ObservableList<Map.Entry<Integer, Integer>> model;
    	
    	if (index == -1)
             model = FXCollections.observableArrayList(new ArrayList<>());
    	else{
    		List<ProgState> programs = ctrl.getCurrentProgramStates();
    		ProgState prgr = programs.get(index);
    		List<Map.Entry<Integer, Integer>> heapElems = iterableToList(prgr.getHeap().getAll());
    		model = FXCollections.observableArrayList(heapElems);
    	}
        heapTable.setItems(model);
        heapTable.refresh();    
    }
    
    private void populateLockTable(int index){
    	ObservableList<Map.Entry<Integer, Integer>> model;
    	
    	if (index == -1)
             model = FXCollections.observableArrayList(new ArrayList<>());
    	else{
    		List<ProgState> programs = ctrl.getCurrentProgramStates();
    		ProgState prgr = programs.get(index);
    		List<Map.Entry<Integer, Integer>> lockElems = iterableToList(prgr.getLockTable().getAll());
    		model = FXCollections.observableArrayList(lockElems);
    	}
        LockTableTable.setItems(model);
        LockTableTable.refresh();    
    }
    
    private void populateSymbolTable(int index){
    	ObservableList<Map.Entry<String, Integer>> model;
    	if (index == -1)
            model = FXCollections.observableArrayList(new ArrayList<>());
    	else{
	    	List<ProgState> programs = ctrl.getCurrentProgramStates();
	    	ProgState prgr = programs.get(index);
	    	List<Map.Entry<String, Integer>> symbolElems = iterableToList(prgr.getSymbolTable().getAll());
	    	model = FXCollections.observableArrayList(symbolElems);
    	}
    	
    	SymbolTableTable.setItems(model);
    	SymbolTableTable.refresh();
    }
    
    private void populateOutput(int index){
    	ObservableList<Integer> model;
    	if (index == -1)
            model = FXCollections.observableArrayList(new ArrayList<>());
    	else{
	    	List<ProgState> programs = ctrl.getCurrentProgramStates();
	    	ProgState prgr = programs.get(index);
	    	List<Integer> outputElems = iterableToList(prgr.getOutput().getAll());
	    	model = FXCollections.observableArrayList(outputElems);
    	}
    	
    	OutputList.setItems(model);
    	OutputList.refresh();
    }
    
    private void populateFileTable(int index){
    	ObservableList<Map<Integer, String>> model;
    	if (index == -1)
            model = FXCollections.observableArrayList(new ArrayList<>());
    	else{
	    	List<ProgState> programs = ctrl.getCurrentProgramStates();
	    	ProgState prgr = programs.get(index);
	    	Map<Integer, String> newFile = new HashMap();
	    	for(Map.Entry<Integer, FileData> data : prgr.getFileTable().getAll())
	    		newFile.put(data.getKey(), data.getValue().getFileName());
	    	
	    	model = FXCollections.observableArrayList(newFile);
    	}
    	
    	FileTableTable.setItems(model);
    	FileTableTable.refresh();
    }
    
    
    
    private static <E> List<E> iterableToList(Iterable<E> iter) {
        List<E> list = new ArrayList<E>();
        for (E item : iter) {
            list.add(item);
        }
        return list;
    }
}
