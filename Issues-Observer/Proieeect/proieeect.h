#ifndef PROIEEECT_H
#define PROIEEECT_H

#include <QtWidgets/QMainWindow>
#include "ui_proieeect.h"
#include "Observer.h"
#include "Controller.h"

class Proieeect : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	Proieeect(User u, Controller &ctrl, QWidget *parent = 0);
	~Proieeect();
	void populateList();
	void update() override { this->populateList(); }

private:
	Ui::ProieeectClass ui;
	User u;
	Controller &ctrl;
	int getSelectedIndex();
	void connections();
	private slots:
	void listItemChanged();
	void addIssue();
	void removeIssue();
	void updateIssue();

};

#endif // PROIEEECT_H
