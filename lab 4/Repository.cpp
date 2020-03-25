#include "Repository.h"

Repository::Repository() { size = 0; }

void Repository::addProject(Project p) {
	projects[size++] = p;
}

int Repository::findProject(Project p) {
	int i = 0;

	while (i < size) {
		if (projects[i] == p) return i;
	}
	return -1;
}

void Repository::deleteProject(Project p) {
	int i = findProject(p);
	if (i != -1)
		projects[i] = projects[size - 1];
	size--;
}

void Repository::updateProject(Project p, char* gitPath, int noOfBranches, int totalNoOfCommits) {
	int i = findProject(p);
	projects[i].setGitPath(gitPath);
	projects[i].setNoOfBranches(noOfBranches);
	projects[i].setTotalNoOfCommits(totalNoOfCommits);

}

Project* Repository::getAll() {
	return projects;
}
int Repository::dim() {
	return size;
}
Repository::~Repository() {
}

Project Repository::getItemFromPos(int i) {
	return projects[i];
}