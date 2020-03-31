#include "ServiceTests.h"
#include "Service.h"
#include"Project.h"
#include<iostream>
#include<assert.h>
using namespace std;
/*Service s;
void testAddProject() {

	assert(s.getDim() == 0);
	Project p1("aaa", 2, 3);
	s.addElem((char*)"aaa",2,3);
	assert(s.getDim() == 1);
	assert(s.getAll()[0] == p1);

}
void testDeleteProject() {
	assert(s.getDim() == 1);
	s.delProject((char*)"aaa",2,3);
	assert(s.getDim() == 0);
}

void testUpdateProject() {
	assert(s.getDim() == 0);
	Project p1((char*)"aaa", 2, 3);
	s.addElem((char*)"aaa",2,3);
	s.updateProject((char*)"aaa",2,3, (char*)"bbb", 3, 5);
	Project p2((char*)"bbb", 3,5);
	assert(s.getAll()[0] == p2);

}

void testFilterProjects() {
	Project result[20];
	int resultLen = 0;
	Project p1((char*)"aaa", 2, 3);
	Project p2((char*)"bbb", 3, 5);
	Project p3((char*)"ccc", 8, 9);
	s.addElem((char*)"aaa", 2, 3);
	s.addElem((char*)"bbb", 3, 5);
	s.addElem((char*)"ccc",8,9);
	s.filterProjects(5, 7, result, resultLen);
	assert((resultLen == 1) && (result[0] == p3));
}

void testElimProjects() {
	Project p1((char*)"sss", 5, 8);
	Project p2((char*)"bbb", 5, 0);
	Project p3((char*)"ccc", 8, 0);
	Service s;
	s.addElem((char*)"sss",5,8);
	s.addElem((char*)"bbb",5,0);
	s.addElem((char*)"ccc",8,0);
	s.elimProjects();
	assert(s.getAll()[0]==p1);

}*/

void testService() {
	Service service;
	Project p1("aaa", 3, 5), p2("bbb", 7, 10), p3("ccc", 6, 12), p5("eee", 0, 3);
	char* gitPath1, * gitPath2, * gitPath3, * gitPath5;
	gitPath1 = new char[15];
	strcpy_s(gitPath1, 11, "aaa");
	gitPath2 = new char[15];
	strcpy_s(gitPath2, 11, "bbb");
	gitPath3 = new char[15];
	strcpy_s(gitPath3, 11, "ccc");
	service.updateProject(gitPath1, 3, 5, gitPath2, 2, 3);
	Project p4(gitPath2, 2, 3);
	assert(service.getAll()[0] == p4);
	delete[] gitPath1;
	gitPath1 = NULL;
	delete[] gitPath2;
	gitPath2 = NULL;
	assert(service.getAll()[0] == p4 and service.getAll()[1] == p2 and service.getAll()[2] == p3);
	service.delProject(gitPath3, 6, 12);
	delete[] gitPath3;
	gitPath3 = NULL;
	assert(service.getAll()[0] == p4 and service.getAll()[1] == p2);
	Project testList[10];
	int resultN = 0;
	service.filterProjects(5, 4, testList, resultN);
	assert(resultN == 1);
	assert(testList[0] == p2);
	gitPath5 = new char[15];
	strcpy_s(gitPath5, 11, "eee");
	service.addElem(gitPath5, 0, 3);
	service.undo();
	assert(service.getAll()[0] == p4 and service.getAll()[1] == p2);
	service.addElem(gitPath5, 0, 3);
	service.elimProjects();
	assert(service.getAll()[0] == p4 and service.getAll()[1] == p2);
	cout << "Service tests done!" << endl;
}

/*void testAdd() {
	Service s;
	Project p1((char*)"aaa", 3, 5);
	s.addElem((char*)"aaa", 3, 5);
	assert(s.getAll()[0]== p1);
}
void testDelete() {
	Service s;
	Project p1((char*)"aaa", 2, 3);
	Project p2((char*)"bbb", 5, 8);
	s.addElem((char*)"aaa", 3, 5);
	s.addElem((char*)"bbb", 5, 8);
	s.delProject((char*)"bbb", 5, 8);
	assert(s.getAll()[0] == p1);
}
void testUpdate() {
	Service s;
	
	Project p1((char*)"aaa", 2, 3);
	s.addElem((char*)"aaa", 2, 3);
	s.updateProject((char*)"aaa", 2, 3, (char*)"bbb", 3, 5);
	Project p2((char*)"bbb", 3, 5);
	assert(s.getAll()[0] == p2);

}

void testFilterProjects() {
	Service s;
	Project result[20];
	int resultLen = 0;
	Project p1((char*)"aaa", 2, 3);
	Project p2((char*)"bbb", 3, 5);
	Project p3((char*)"ccc", 8, 9);
	s.addElem((char*)"aaa", 2, 3);
	s.addElem((char*)"bbb", 3, 5);
	s.addElem((char*)"ccc", 8, 9);
	s.filterProjects(5, 7, result, resultLen);
	assert((resultLen == 1) && (result[0] == p3));
}
void testElimProjects() {
	Project p1((char*)"sss", 5, 8);
	Project p2((char*)"bbb", 5, 0);
	Project p3((char*)"ccc", 8, 0);
	Service s;
	s.addElem((char*)"sss", 5, 8);
	s.addElem((char*)"bbb", 5, 0);
	s.addElem((char*)"ccc", 8, 0);
	s.elimProjects();
	assert(s.getAll()[0] == p1);
}
*/
