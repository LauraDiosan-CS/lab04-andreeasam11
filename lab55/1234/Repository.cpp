#include "Repository.h"
#include <iostream>

using namespace std;

Repository::Repository() {
	size = 0;
	undo_size = 0;
}

void Repository::addElem(Project p) {
	projects[size++] = p;
}

int Repository::findElem(Project p) {
	for (int i = 0;i < size;i++)
		if (projects[i] == p)
			return i;
	return -1;
}

void Repository::addUndo()
{
	for (int i = 0;i < size;i++)
		undo[undo_size][i] = projects[i];
	undo_sizes[undo_size] = size;
	undo_size++;
}

void Repository::deleteUndo()
{
	undo_sizes[undo_size - 1] = 0;
	undo_size--;
}

void Repository::undoFunction() {

	for (int i = 0;i < undo_sizes[undo_size - 1];i++)
		projects[i] = undo[undo_size - 1][i];
	size = undo_sizes[undo_size - 1];
	deleteUndo();
}

Project Repository::getItemFromPos(int poz) {
	return projects[poz];
}

void Repository::delElem(Project p) {
	int i = findElem(p);
	if (i != -1)
		projects[i] = projects[size - 1];
	size--;
}

void Repository::updateElem(Project p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	int i = findElem(p);
	projects[i].setGitPath(gitPath);
	projects[i].setNoOfBranches(noOfBranches);
	projects[i].setTotalNoOfCommits(totalNoOfCommits);
}


Repository& Repository::operator=(const Repository& re) {
	int dim = re.size;
	size = re.size;
	undo_size = re.undo_size;
	for (int i = 0;i < dim;i++)
		projects[i] = re.projects[i];
	for (int i = 0;i < undo_size;i++)
	{
		int dime = sizeof(undo[i]) / sizeof(undo[i][0]);
		for (int j = 0;j < dime;j++)
			undo[i][j] = re.undo[i][j];
	}
	return *this;
}

Project* Repository::getAll() {
	return projects;
}

int Repository::getDim() {
	return size;
}

Repository::~Repository() {
}