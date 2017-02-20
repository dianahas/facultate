#include "proieeect.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "filename","fileName" };
	Controller ctrl{ repo };
	User u;
	vector<User> users = ctrl.getRepo().getUsers();
	vector<Proieeect*> autos;
	u = users[0];
	for (auto u : users)
	{
		Proieeect *w=new Proieeect{ u,ctrl };
		autos.push_back(w);
	}
	for(auto w:autos)
		w->show();
	return a.exec();
}
