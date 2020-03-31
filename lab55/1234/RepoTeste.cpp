#include"RepoTeste.h"
#include"Repository.h"
#include"Project.h"
#include<assert.h>
#include<iostream>
using namespace std;
/*Repository rep;
void testAdd()
{
	assert(rep.getDim() == 0);
	Project p((char*)"aaa", 3, 3);
	rep.addElem(p);
	assert(rep.getDim()== 1);
	cout << "Test passed \n";
}
void testGetAll()
{
	Project* projects;
	Project p1((char*)"aaa", 3, 3);
	Project p2((char*)"bbb", 4, 2);
	rep.addElem(p2);
	rep.addElem(p1);
	projects = rep.getAll();
	assert(rep.getDim() == 3);
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
	Repository list;
	Project* projects;
	Project p1((char*)"aaa", 3, 3);
	Project p2((char*)"bbb", 4, 2);
	list.addElem(p1);
	list.addElem(p2);
	assert(list.getDim() == 2);
	list.delProject(p2);
	assert(list.getDim() == 1);
	projects = list.getAll();
	assert(projects[0] == p1);
	cout << "Test passed \n";
}
void testUpdate()
{
	Project* projects;
	projects = rep.getAll();
	Project p2((char*)"ccc", 3, 3);
	Project p1((char*)"aaa", 3, 3);
	assert(projects[0] == p1);
	rep.updateElem(p2, (char*)"ccc", 3, 3);
	assert(projects[0] == p2);
	cout << "Test passed \n";


}*/


void testRepository() {
	Repository list;
	Project p1("aaa", 3, 5), p2("bbb", 7, 10), p3("ccc", 6, 12);
	Project* test_list;
	list.addElem(p1);
	list.addElem(p2);
	list.addElem(p3);
	assert(list.getDim() == 3);
	assert(list.getItemFromPos(0) == p1);
	assert(list.findElem(p2) == 1);
	list.delElem(p2);
	assert(list.getDim() == 2);
	test_list = list.getAll();
	assert(test_list[0] == p1 and test_list[1] == p3);
	cout << "Repository tests done!" << endl;
}