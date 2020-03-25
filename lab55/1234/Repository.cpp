#include "Repository.h"
#include<iostream>
#include<cstddef>

Repository::Repository() { this->size = 0; }
Repository::Repository(int size) {
	this->size = size;
}

void Repository::addProject(Project p) {
	this->projects[this->size++] = p;
}

Repository::Repository(const Repository& rep) {

	this->size = rep.size;
}



int Repository::findElem(Project p) {
	int i = 0;

	while (i < this->size) {
		if (projects[i] == p) return i;
	}return -1;
}


Project* Repository::getAll() {
	return projects;
}

Repository::~Repository() {
}
void Repository::delElem1(int i) {
	projects[i] = projects[size - 1];
	size--;



}
void Repository::delProject(Project p) {
	int i = findElem(p);
	if (i != -1) {
		projects[i] = projects[size - 1];
		size--;
	}

}
void Repository::updateElem1(int i, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	projects[i].setGitPath(gitPath);
	projects[i].setNoOfBranches(noOfBranches);
	projects[i].setTotalNoOfCommits(totalNoOfCommits);


}
Project Repository::getItemFromPos(int i) {
	return projects[i];
}
int Repository::getSize() {
	return this->size;
}
