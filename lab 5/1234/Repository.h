#pragma once
#include "Project.h"

class Repository
{
private:
	Project projects[20];
	int size;

public:
	Repository();
	Repository(int size);
	Repository(const Repository& rep);
	void addProject(Project);
	int findElem(Project);
	Project getItemFromPos(int);
	int getSize();
	void delElem1(int);
	void delProject(Project p);
	void updateElem1(int i, char* n, int, int);
	Project* getAll();
	~Repository();

};