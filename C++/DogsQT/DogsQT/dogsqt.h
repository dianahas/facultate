#ifndef DOGSQT_H
#define DOGSQT_H

#include <QtWidgets/QMainWindow>
#include "ui_dogsqt.h"

#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include "ControlUser.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class DogsQT : public QWidget
{
	Q_OBJECT

public:
	DogsQT(Controller ctrl, ControlUser ctrl2, QWidget *parent = 0);
	~DogsQT();

private:
	Controller admin_ctrl;
	ControlUser user_ctrl;
	std::vector<Dog> DogsInRepoList;
	std::vector<Dog> DogsInWatchlist;
	std::vector<Dog> DogsInSortedList;
	Ui::DogsQTClass ui;

	//LeftSide -> Start
	QListWidget* repoList;

	QLineEdit* breedEdit;
	QLineEdit* nameEdit;
	QLineEdit* ageEdit;
	QLineEdit* photographEdit;

	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	//LeftSide -> End
	
	//Middle -> Start
	QPushButton* seeAllDogsByBreedButton;
	QPushButton* deleteWatchlistMovieButton;
	//Middle -> End

	//RightSide -> Start
	QListWidget* watchlist;
	QPushButton* saveButton;
	QPushButton* openButton;
	
	void initGUI();
	void populateRepoList();
	void populateWatchlist();
	int getRepoListSelectedIndex();

	void connectSignalsAndSlots();

private slots:
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();

	void addNewDog();
	void deleteDog();
	void updateDog();
	
	void moveAllDogsToWatchlist();
	void moveAllDogsByBreedToWatchlist();

	void openWatchlistFile();
	
};

#endif // DOGSQT_H
