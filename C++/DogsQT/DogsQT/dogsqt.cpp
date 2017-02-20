#include "dogsqt.h"
#include <vector>
#include <cstring>
#include "Dog.h"
#include <QMessagebox>
#include <QInputDialog>
#include <QtGui>
#include "RepoExceptions.h"


DogsQT::DogsQT(Controller ctrl, ControlUser ctrl2, QWidget *parent) : admin_ctrl{ ctrl }, user_ctrl{ ctrl2 }, QWidget { parent }
{
	this->initGUI();
	this->DogsInRepoList = this->admin_ctrl.getRepo().getDogs();
	this->DogsInWatchlist = this->user_ctrl.getAdoptRepo();
	//this->DogsInSortedList = this->user_ctrl.getSortRepo().getSortAdopt();
	this->populateRepoList();
}

DogsQT::~DogsQT() {}

void DogsQT::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	/*
	Prepare left side components - vertical layout with:
	- list
	- form layout with the movie data
	- grid layout with buttons: add, delete, update
	*/
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	//list
	this->repoList = new QListWidget{};
	//set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	//movie data
	QWidget* movieDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ movieDataWidget };
	this->breedEdit = new QLineEdit{};
	this->nameEdit = new QLineEdit{};
	this->ageEdit = new QLineEdit{};
	this->photographEdit = new QLineEdit{};
	formLayout->addRow("&Breed:", breedEdit);
	formLayout->addRow("&Name:", nameEdit);
	formLayout->addRow("&Age:", ageEdit);
	formLayout->addRow("&Photograph:", photographEdit);

	//buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);

	//add everything to the left layout
	leftSide->addWidget(new QLabel{ "All Dogs" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(movieDataWidget);
	leftSide->addWidget(buttonsWidget);
	
	//middle component: just two buttons - to add the movies from the repository to the watchlist by genre or move all of them
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->seeAllDogsByBreedButton = new QPushButton{ "Pick Dogs" };
	this->deleteWatchlistMovieButton = new QPushButton{ "Get sorted Dogs" };
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	QVBoxLayout* vLayoutLowerPart = new QVBoxLayout{ lowerPart };
	vLayoutUpperPart->addWidget(this->seeAllDogsByBreedButton);
	vLayoutLowerPart->addWidget(this->deleteWatchlistMovieButton);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	//right component: the watchlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	//watchlist
	watchlist = new QListWidget{};

	// two buttons
	QWidget* watchlistButtonsWidget = new QWidget{};
	QHBoxLayout* watchlistButtonsLayout = new QHBoxLayout{ watchlistButtonsWidget };
	//this->saveButton = new QPushButton("Save");
	this->openButton = new QPushButton("Open");
	//watchlistButtonsLayout->addWidget(this->saveButton);
	watchlistButtonsLayout->addWidget(this->openButton);

	//add everything to the right layout
	rightSide->addWidget(new QLabel{ "Watchlist" });
	rightSide->addWidget(watchlist);
	rightSide->addWidget(watchlistButtonsWidget);
	
	//add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	//connect the signals and slots
	this->connectSignalsAndSlots();
}

void DogsQT::populateRepoList()
{
	//clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();

	for (auto m : this->DogsInRepoList)
	{
		QString itemInList = QString::fromStdString(m.getBreed() + " - " + m.getName() + " - " + std::to_string(m.getAge()));
		this->repoList->addItem(itemInList);
	}

	// set the selection on the first item in the list
	if (this->DogsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void DogsQT::populateWatchlist()
{
	// clear the list, if there are elements in it
	if (this->watchlist->count() > 0)
		this->watchlist->clear();

	for (auto m : this->user_ctrl.getAdoptRepo())
	{
		QString itemInList = QString::fromStdString(m.getBreed() + " - " + m.getName());
		this->watchlist->addItem(itemInList);
	}
}

int DogsQT::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->breedEdit->clear();
		this->nameEdit->clear();
		this->ageEdit->clear();
		this->photographEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void DogsQT::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Dog> dogs = this->DogsInRepoList;

	//get the movie at the selected index
	if (idx >= dogs.size())
		return;
	Dog m = dogs[idx];

	this->breedEdit->setText(QString::fromStdString(m.getBreed()));
	this->nameEdit->setText(QString::fromStdString(m.getName()));
	this->ageEdit->setText(QString::fromStdString(std::to_string(m.getAge())));
	this->photographEdit->setText(QString::fromStdString(m.getPhoto()));
}

void DogsQT::connectSignalsAndSlots()
{
	//add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));

	//add buton connections
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewDog()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteDog()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateDog()));

	QObject::connect(this->seeAllDogsByBreedButton, SIGNAL(clicked()), this, SLOT(moveAllDogsToWatchlist()));
	QObject::connect(this->deleteWatchlistMovieButton, SIGNAL(clicked()), this, SLOT(moveAllDogsByBreedToWatchlist()));

	//QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(saveWatchlistToFile()));
	QObject::connect(this->openButton, SIGNAL(clicked()), this, SLOT(openWatchlistFile()));
	
}

void DogsQT::addNewDog()
{
	std::string breed = this->breedEdit->text().toStdString();
	std::string name = this->nameEdit->text().toStdString();
	std::string age = this->ageEdit->text().toStdString();
	std::string photo = this->photographEdit->text().toStdString();

	try
	{
		this->admin_ctrl.addDogtoRepo(breed, name, stoi(age), photo);
		//refresh the list
		this->DogsInRepoList = this->admin_ctrl.getRepo().getDogs();
		this->populateRepoList();
	}
	catch (DogException &e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateDogException &e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void DogsQT::deleteDog()
{
	std::string breed = this->breedEdit->text().toStdString();
	std::string name = this->nameEdit->text().toStdString();

	try
	{
		this->admin_ctrl.removeDogFromRepo(breed, name);
		//refresh the list
		this->DogsInRepoList = this->admin_ctrl.getRepo().getDogs();
		this->populateRepoList();
	}
	catch (DuplicateDogException &e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void DogsQT::updateDog()
{
	std::string breed = this->breedEdit->text().toStdString();
	std::string name = this->nameEdit->text().toStdString();
	std::string age = this->ageEdit->text().toStdString();
	std::string photo = this->photographEdit->text().toStdString();

	try
	{
		this->admin_ctrl.updateDogInRepo(breed, name, stoi(age), photo);
		//refresh the list
		this->DogsInRepoList = this->admin_ctrl.getRepo().getDogs();
		this->populateRepoList();
	}
	catch (DogException &e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (DuplicateDogException &e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void DogsQT::moveAllDogsToWatchlist()
{
	QInputDialog* inputDialog = new QInputDialog();
	inputDialog->setOptions(QInputDialog::NoButtons);
	bool ok;
	ok = 1;
	if (ok)
	{
		AdoptSortRepo dogsByBreed;
		dogsByBreed.setDogs(this->admin_ctrl.getRepo().getDogs());
		while (true)
			{
				char message[1024];
				char tab2[1024];
				strcpy(tab2, dogsByBreed.returnCurrentDog2().getName().c_str());
				std::sprintf(message, "What would you like to do with the dog: %s?", tab2);
				QMessageBox mbox;
				mbox.setText(message);
				QAbstractButton* pButtonAdd = mbox.addButton(tr("Adopt"), QMessageBox::YesRole);
				QAbstractButton* pButtonSkip = mbox.addButton(tr("Skip"), QMessageBox::NoRole);
				QAbstractButton* pButtonPlay = mbox.addButton(tr("See Photo"), QMessageBox::YesRole);
				QAbstractButton* pButtonStop = mbox.addButton(tr("Stop"), QMessageBox::NoRole);

				mbox.exec();

				if (mbox.clickedButton() == pButtonAdd)
				{
					try
					{
						this->user_ctrl.addAdoptDog(dogsByBreed.returnCurrentDog2());
						this->admin_ctrl.removeDogFromRepo(dogsByBreed.returnCurrentDog2().getBreed(), dogsByBreed.returnCurrentDog2().getName());
						this->DogsInRepoList = this->admin_ctrl.getRepo().getDogs();
						this->populateRepoList();
					}
					catch (DuplicateDogException &e)
					{
						QMessageBox messageBox;
						messageBox.critical(0, "Error", e.what());
						dogsByBreed.nextDog2();
						continue;
					}
					QMessageBox messageBox;
					messageBox.information(0, "Adopt", "Dog adopted!");
					dogsByBreed.nextDog2();
				}
				else if (mbox.clickedButton() == pButtonSkip)
				{
					dogsByBreed.nextDog2();
				}
				else if (mbox.clickedButton() == pButtonPlay)
				{
					dogsByBreed.showDog2();
				}
				else if (mbox.clickedButton() == pButtonStop)
				{
					break;
				}
			}
		}
		this->DogsInWatchlist = this->user_ctrl.getSortRepo().getSortAdopt();
		this->populateWatchlist();
}

void DogsQT::moveAllDogsByBreedToWatchlist()
{
	QInputDialog* inputDialog = new QInputDialog();
	inputDialog->setOptions(QInputDialog::NoButtons);
	bool ok;

	QString text = inputDialog->getText(NULL, "Breed Select", "Input a breed you'd like to go through:", QLineEdit::Normal, QDir::home().dirName(), &ok);
	QString text2 = inputDialog->getText(NULL, "Age Select", "Input a age you'd like to go through:", QLineEdit::Normal, QDir::home().dirName(), &ok);

	if (ok)
	{
		std::string breed = text.toStdString();
		std::string age = text2.toStdString();
		AdoptSortRepo dogsByBreed;
		dogsByBreed.setDogs(this->user_ctrl.sortDogs(breed,stoi(age)));
		if (dogsByBreed.getSortAdopt().size() == 0)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", "There are no dogs with that particular breed.");
		}
		else
		{
			while (true)
			{
				char message[1024];
				char tab2[1024];
				strcpy(tab2, dogsByBreed.returnCurrentDog2().getName().c_str());
				std::sprintf(message, "What would you like to do with the dog: %s?", tab2);
				QMessageBox mbox;
				mbox.setText(message);
				QAbstractButton* pButtonAdd = mbox.addButton(tr("Adopt"), QMessageBox::YesRole);
				QAbstractButton* pButtonSkip = mbox.addButton(tr("Skip"), QMessageBox::NoRole);
				QAbstractButton* pButtonPlay = mbox.addButton(tr("See Photo"), QMessageBox::YesRole);
				QAbstractButton* pButtonStop = mbox.addButton(tr("Stop"), QMessageBox::NoRole);

				mbox.exec();

				if (mbox.clickedButton() == pButtonAdd)
				{
					try
					{
						this->user_ctrl.addAdoptDog(dogsByBreed.returnCurrentDog2());
						this->admin_ctrl.removeDogFromRepo(breed, dogsByBreed.returnCurrentDog2().getName());
						this->DogsInRepoList = this->admin_ctrl.getRepo().getDogs();
						this->populateRepoList();
					}
					catch (DuplicateDogException &e)
					{
						QMessageBox messageBox;
						messageBox.critical(0, "Error", e.what());
						dogsByBreed.nextDog2();
						continue;
					}
					QMessageBox messageBox;
					messageBox.information(0, "Adopt", "Dog adopted!");
					dogsByBreed.nextDog2();
				}
				else if (mbox.clickedButton() == pButtonSkip)
				{
					dogsByBreed.nextDog2();
				}
				else if (mbox.clickedButton() == pButtonPlay)
				{
					dogsByBreed.showDog2();
				}
				else if (mbox.clickedButton() == pButtonStop)
				{
					break;
				}
			}
		}
		this->DogsInWatchlist = this->user_ctrl.getSortRepo().getSortAdopt();
		this->populateWatchlist();
	}
}

void DogsQT::openWatchlistFile()
{
	this->user_ctrl.openWatch();
}
