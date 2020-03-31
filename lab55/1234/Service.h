#pragma once
#include "Project.h"
#include "Repository.h"

class Service {
private:
	Repository rep;
public:
	Service();
	Service(const Repository&);
	int getDim();
	void addElem(char*, int, int);
	void delProject(char*, int, int);
	void updateProject(char*, int, int, char*, int, int);
	void elimProjects();
	void filterProjects(int, int, Project[], int&);
	void undo();
	Project* getAll();
	~Service();
};