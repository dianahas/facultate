package application;
import utils.*;
import model.*;
import model.file.*;
import model.heap.AllocateHeapStmt;
import model.heap.ReadHeap;
import model.heap.WriteHeap;
import model.statement.*;
import view.*;
import repository.*;
import controller.Controller;
import gui.MainWindowController;
import gui.ProgramsController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;


public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			Repository repository = new Repository("file30.txt");
			Controller ctrl=new Controller(repository);
			
			FXMLLoader loader = new FXMLLoader();
			loader.setLocation(Main.class.getResource("/gui/MainWindow.fxml"));
			BorderPane root = loader.load();
			
			Scene scene = new Scene(root);
			primaryStage.setScene(scene);
			MainWindowController controller = loader.getController();
			controller.setController(ctrl);
			primaryStage.show();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		Application.launch(args);
	}
}
