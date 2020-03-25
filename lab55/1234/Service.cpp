#include "Service.h"
#include<iostream>
using namespace std;

Service::Service() {
	this->r;
}
Service::~Service() {

}
Project* Service::getAll() {
	return r.getAll();
}

int Service::gasireElement(const Project& p) {
	return r.findElem(p);
}

void Service::addProject(Project p)
{

	r.addProject(p);
}
Project* Service::showProjects()
{

	return r.getAll();
}
void Service::deleteProject(int i) {
	r.delElem1(i);

}
int Service::dim()																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
{
	return r.getSize();
}
void Service::updateProject(int i, char* gitPath, int noOfBranches, int totalNoOfCommits) {

	r.updateElem1(i, gitPath, noOfBranches, totalNoOfCommits);
}
Project Service::getItemFromPos(int i) {
	return r.getItemFromPos(i);
}
void Service::filterProjects( int k, int l,Project result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < r.getSize(); i++)
	{
		Project project = r.getItemFromPos(i);
		if (project.getNoOfBranches() >= k && project.getTotalNoOfCommits() >= l)
		{
			result[resultLen++] = project;
		}
	}
}
void Service::delProject(Project p) {
	r.delProject(p);

}

void Service::elimProjects()
{
	for (int i = 0; i < r.getSize(); i++) {
		Project project = r.getItemFromPos(i);
		if ((project.getNoOfBranches() * project.getTotalNoOfCommits()) ==0)
			r.delElem1(i);
	}

}






