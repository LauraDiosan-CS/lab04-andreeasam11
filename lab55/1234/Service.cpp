#include "Service.h"

Service::Service() {
	Project l1("aaa", 3, 5), l2("bbb", 7, 10), l3("ccc", 6, 12);
	rep.addElem(l1);
	rep.addElem(l2);
	rep.addElem(l3);
}

Service::Service(const Repository& r) {
	rep = r;
	Project l1("aaa", 3, 5), l2("bbb", 7, 2), l3("ccc", 6, 3);
	rep.addElem(l1);
	rep.addElem(l2);
	rep.addElem(l3);
}

int Service::getDim() {
	return rep.getDim();
}
void Service::addElem(char* gitPath, int noOfBranches, int totalNoOfCommits) {
	rep.addUndo();
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	rep.addElem(p);
}

void Service::delProject(char* gitPath, int noOfBranches, int totalNoOfCommits) {
	rep.addUndo();
	Project p(gitPath, noOfBranches, totalNoOfCommits);
	rep.delElem(p);
}

void Service::filterProjects(int minimumNoOfBranches, int minimumNoOfCommits, Project resultList[], int& resultN) {
	resultN = 0;
	int dim = getDim();
	for (int i = 0;i < dim;i++)
		if (getAll()[i].getNoOfBranches() >= minimumNoOfBranches and getAll()[i].getTotalNoOfCommits() >= minimumNoOfCommits)
			resultList[resultN++] = getAll()[i];
}

Project* Service::getAll() {
	return rep.getAll();
}

void Service::updateProject(char* gitPathOld, int noOfBranchesOld, int totalNoOfCommitsOld, char* gitPathNew, int noOfBranchesNew, int totalNoOfCommitsNew) {
	rep.addUndo();
	Project p(gitPathOld, noOfBranchesOld, totalNoOfCommitsOld);
	rep.updateElem(p, gitPathNew, noOfBranchesNew, totalNoOfCommitsNew);
}

void Service::elimProjects() {
	rep.addUndo();
	int n = getDim();
	for (int i = 1;i < n;i++)
	{
		if (getAll()[i].getNoOfBranches() * getAll()[i].getTotalNoOfCommits() == 0)
			rep.delElem(getAll()[i]);
	}
}

void Service::undo() {
	rep.undoFunction();
}

Service::~Service() {
}