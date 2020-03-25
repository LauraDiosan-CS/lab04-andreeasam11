#pragma once
#include "Project.h"
#include "Repository.h"
class Service {
private:
	Repository r;
public:
	Service();
	~Service();
	void filterProjects(int k, int l, Project result[], int& resultLen);
	void delProject(Project p);
	Project* getAll();
	void elimProjects();
	Project getItemFromPos(int i);
	int gasireElement(const Project& p);
	void addProject(Project p);
	Project* showProjects();
	void deleteProject(int i);
	void updateProject(int i, char*, int, int);
	int dim();
	//void undo();






};