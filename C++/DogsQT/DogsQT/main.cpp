#include "dogsqt.h"
#include <QtWidgets/QApplication>
#include <qmessagebox.h>
#include "DogRepo.h"
#include "DogCSV.h"
#include "DogHtml.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo_admin( "Dogs.txt" );
	AdoptRepo repo2();
	AdoptSortRepo repo3{};
	std::vector<Dog> vec;
	Controller ctrl_admin( repo_admin );
	//ControlUser user_ctrl( repo_admin, repo2, repo3);
	QMessageBox mbox;
	mbox.setText("With what type of file would you like to operate?");
	QAbstractButton* pButtonHTML = mbox.addButton(QString::fromStdString("HTML"), QMessageBox::YesRole);
	QAbstractButton* pButtonCSV = mbox.addButton(QString::fromStdString("CSV"), QMessageBox::NoRole);

	mbox.exec();
	if (mbox.clickedButton() == pButtonHTML)
	{
		//DogHtml watchlist;
		AdoptRepo* repo2 = new DogHtml(vec, "htmlfile.html");
		ControlUser user_ctrl{ repo_admin, repo2, repo3 };
		DogsQT w{ ctrl_admin, user_ctrl };
		w.show();
		return a.exec();
	}
	else if (mbox.clickedButton() == pButtonCSV)
	{
//		DogCSV watchlist;
		AdoptRepo* repo2 = new DogCSV(vec, "csvfile.txt");
		ControlUser user_ctrl{ repo_admin, repo2, repo3 };
		DogsQT w{ ctrl_admin, user_ctrl };
		w.show();
		return a.exec();
	}
	
	//DogsQT dogs{ ctrl_admin };
	//dogs.show();
	//return a.exec();
}
