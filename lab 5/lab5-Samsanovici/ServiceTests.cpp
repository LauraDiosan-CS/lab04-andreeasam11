#include "ServiceTests.h"
#include "Service.h"
#include<iostream>
#include<assert.h>
Service s;
void testAddProject() {

	assert(s.dim() == 0);
	Project p1((char*)"aaa", 2, 3);
	s.addProject(p1);
	assert(s.dim() == 1);
	assert(*s.showProjects() == p1);

}
void testDeleteProject() {
	assert(s.dim() == 1);
	s.deleteProject(0);
	assert(s.dim() == 0);
}

void testUpdateProject() {
	assert(s.dim() == 0);
	Project p1((char*)"aaa", 2, 3);
	s.addProject(p1);
	s.updateProject(0, (char*)"bbb", 2, 3);
	Project p2((char*)"bbb", 2, 3);
	assert(*s.showProjects() == p2);

}

void testFilterProjects() {
	Project result[20];
	int resultLen = 0;
	Project p1((char*)"aaa", 2, 3);
	Project p2((char*)"bbb", 5, 7);
	Project p3((char*)"ccc", 8, 9);
	s.addProject(p1);
	s.addProject(p2);
	s.addProject(p3);
	s.filterProjects(5, 7, result, resultLen);
	assert((resultLen == 2) && (result[0] == p2) && (result[1] == p3));
}

void testElimProjects() {
	Project p1((char*)"sss", 5, 8);
	Project p2((char*)"bbb", 5, 0);
	Project p3((char*)"ccc", 8, 0);
	Service s;
	s.addProject(p1);
	s.addProject(p2);
	s.addProject(p3);
	s.elimProjects();
	assert(*s.showProjects() == p1);

}
