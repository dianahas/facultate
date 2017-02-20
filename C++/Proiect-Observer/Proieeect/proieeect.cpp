#include "proieeect.h"
#include "exe.h"
#include <qmessagebox.h>


Proieeect::Proieeect(User u,Controller &ctrl, QWidget *parent)
	:u{ u }, ctrl{ ctrl }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(u.getName()+'-'+u.getType()));
	this->populateList();
	this->connections();
	this->ctrl.addObserver(this);
}

Proieeect::~Proieeect()
{

}

void Proieeect::populateList()
{
	if (this->ui.issuesList->count() > 0)
		this->ui.issuesList->clear();

	vector<Issue> issues = ctrl.getRepo().getIssues();
	//Issue i;
	for (auto i : issues)
	{
		QString item = QString::fromStdString(i.getDescription() + ',' + i.getStatus() + ',' + i.getReporter() + ',' + i.getSolver());
		this->ui.issuesList->addItem(item);
	}
}

void Proieeect::addIssue()
{
		std::string descr = this->ui.nameEdit->text().toStdString();
		std::string status = "open";
		std::string reporter = this->u.getName();
		std::string solver = "-";
		this->ctrl.addIssue(descr, status, reporter, solver);
		this->populateList();
	  
}

void Proieeect::removeIssue()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;
	vector<Issue> iss = this->ctrl.getRepo().getIssues();
	Issue i = iss[idx];
	try {
		if (i.getStatus() != "closed")
			throw CustomException{ "The status is not closed" };
		this->ctrl.removeIssue(i.getDescription(), i.getStatus(), i.getReporter(), i.getSolver());
	}
	catch (CustomException &e)
	{
		QMessageBox::warning(NULL, "Error", e.what());
	}
	
}

void Proieeect::updateIssue()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;
	vector<Issue> iss = this->ctrl.getRepo().getIssues();
	Issue i = iss[idx];
	std::string name = this->u.getName();
	try {
		if (i.getStatus() != "open")
			throw CustomException{ "The status is not open" };
		this->ctrl.updateIssue(i.getDescription(), i.getStatus(), i.getReporter(), name);
	}
	catch (CustomException &e)
	{
		QMessageBox::warning(NULL, "Error", e.what());
	}
}

int Proieeect::getSelectedIndex()
{
	QModelIndexList index = ui.issuesList->selectionModel()->selectedIndexes();
	int idx = index.at(0).row();
	return idx;
}

void Proieeect::connections()
{
	if (this->u.getType() == "tester")
		QObject::connect(this->ui.addButton, SIGNAL(clicked()), this, SLOT(addIssue()));
	QObject::connect(this->ui.removeButton, SIGNAL(clicked()), this, SLOT(removeIssue()));
	
	if (this->u.getType() == "programmer")
			QObject::connect(this->ui.resolveButton, SIGNAL(clicked()), this, SLOT(updateIssue()));
	
	
}

void Proieeect::listItemChanged()
{
	int idx = this->getSelectedIndex();
	if (idx == -1)
		return;
	vector<Issue> iss = this->ctrl.getRepo().getIssues();
	Issue i = iss[idx];
	ui.nameEdit->setText(QString::fromStdString(i.getDescription()));
}