#include "TesteEntitate.h"
#include "Project.h"
#include<iostream>
using namespace std;
void teste() {
	Project p1;	 //implicit constructor
	p1.setGitPath((char*)"aaa");
	p1.setNoOfBranches(3);
	p1.setTotalNoOfCommits(4);
	Project p2 = p1;  //copy constructor
	Project p3;			//implicit constructor
	p3 = p2;			//assign op or implicit assign op beacuse memebr data are of elementary type => a new ob
	p1 = p1;			//(implicit) assign op => self assign
	cout << "Test passed \n";

}
