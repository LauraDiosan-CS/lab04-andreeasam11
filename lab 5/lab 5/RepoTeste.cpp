#include "RepoTeste.h"
#include "Repository.h"
#include<assert.h>
#include<iostream>
Repository r;
void testAdd()
{
	assert(r.getSize() == 0);
	Project p((char*)"aaa", 3, 3);
	r.addProject(p);
	assert(r.getSize() == 1);
	cout << "Test passed \n";
}
void testGetAll()
{
	Project* projects;
	Project p1((char*)"aaa", 3, 3);
	Project p2((char*)"bbb", 4, 2);
	r.addProject(p2);
	r.addProject(p1);
	projects = r.getAll();
	assert(r.getSize() == 3);
	Project p3;
	Project p4;
	p3 = p1;
	p4 = p2;
	assert(projects[0] == p3);
	assert(projects[1] == p4);
	cout << "Test passed \n";

}
void testeConstructor()
{
	Project p1((char*)"bbb", 4, 2);
	Project p2 = p1;		//copy constructor
	Project p3;			//implicit constructor
	p3 = p2;			//assign op or implicit assign op beacuse memebr data are of elementary type => a new ob
	p1 = p1;
	cout << "Test passed \n";
}
void testDelete()
{
	Project* projects;
	Project p1((char*)"aaa", 3, 3);
	Project p2((char*)"bbb", 4, 2);
	r.delElem1(2);
	assert(r.getSize() == 2);
	projects = r.getAll();
	assert(projects[0] == p1);
	assert(projects[1] == p2);
	cout << "Test passed \n";
}
void testUpdate()
{
	Project* projects;
	projects = r.getAll();
	Project p2((char*)"ccc", 3, 3);
	Project p1((char*)"aaa", 3, 3);
	assert(projects[0] == p1);
	r.updateElem1(0, (char*)"ccc", 3, 3);
	assert(projects[0] == p2);
	cout << "Test passed \n";


}
