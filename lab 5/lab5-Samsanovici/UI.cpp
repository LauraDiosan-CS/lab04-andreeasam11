#include "UI.h"
#include<iostream>


void UI::display() {
	std::cout << "\n";
	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "Alegeti o optiune: " << std::endl;
	std::cout << "(1): Adaugare proiect." << std::endl;
	std::cout << "(2): Afisare proiecte." << std::endl;
	std::cout << "(3): Stergere proiect." << std::endl;
	std::cout << "(4): Modificare proiect." << std::endl;
	std::cout << "(5): Identificarea proiectelor care  au noOfBranches >=k si totalNoOfCommits>=l." << std::endl;
	std::cout << "(6): Eliminarea exercitiilor care au noOfBranches * totalNoOfCommits==0" << std::endl;
	std::cout << "(7):  UNDO." << std::endl;
	std::cout << "(8):  REDO." << std::endl;
	std::cout << "(9):  Exit." << std::endl;
}
void UI::PrintMenu()
{
	int ok = 1;
	char gitPath[10];
	int noOfBranches = {}, totalNoOfCommits = {}, k, l, resultLen = 0;
	int opt;
	do {
		display();
		while (true) {

			cin >> opt;
			if (opt == 1) {
				cout << "\n Introduceti gitPath: ";
				cin >> gitPath;
				cout << " Introduceti nr.de branches: ";
				cin >> noOfBranches;
				cout << " Introduceti nr. total de commits:  ";
				cin >> totalNoOfCommits;
				cout << endl;
				Project p(gitPath, noOfBranches, totalNoOfCommits);
				s.addProject(p);
				break;
			}
			if (opt == 2) {
				for (int i = 0; i < s.dim(); i++)
				{
					cout << "GitPath: " << s.showProjects()[i].getGitPath() << endl;
					cout << "Nr.de branches: " << s.showProjects()[i].getNoOfBranches() << endl;
					cout << "Nr. total de commits: " << s.showProjects()[i].getTotalNoOfCommits() << endl;
					cout << "-------------------------------" << endl;
				}

				break;

			}
			if (opt == 3)
			{
				int elem;
				cout << "Dati pozitia elementului pe care doriti sa-l stergeti: ";
				cin >> elem;
				if (elem < s.dim()) {

					s.deleteProject(elem);
				}
				else cout << "Elementul dat nu exista.";
				break;
			}
			if (opt == 4)
			{
				int elem;
				cout << "Dati pozitia elementului pe care doriti sa-l modificati:  ";
				cin >> elem;
				if (elem < s.dim()) {
					cout << "\n Update proiect: ";
					cout << "\n Introduceti GitPath: ";
					cin >> gitPath;
					cout << " Introduceti nr.de branches: ";
					cin >> noOfBranches;
					cout << " Introduceti nr. total de commits:  ";
					cin >> totalNoOfCommits;
					cout << endl;

					s.updateProject(elem, gitPath, noOfBranches, totalNoOfCommits);
				}
				else cout << "Elemenul dat nu exista";
				break;
			}

			if (opt == 5) {
				Project result[20];
				cout << "k= "; cin >> k;
				cout << "l= ";cin >> l;
				s.filterProjects(k, l, result, resultLen);
				for (int i = 0; i < resultLen; i++) {
					cout << "GitPath: " << result[i].getGitPath() << endl;
					cout << "Nr.de branches: " << result[i].getNoOfBranches() << endl;
					cout << "Nr.total de commits: " << result[i].getTotalNoOfCommits() << endl;
					cout << "-------------------------------" << endl;
				}
				break;
			}
			if (opt == 6)
			{

				s.elimProjects();
				break;

			}
			if (opt == 7) {
				//UNDO
			}
			if (opt == 8) {
				//REDO
			}
			if (opt == 9) {
				cout << "Exit.";
				exit(0);
			}

			if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5 && opt != 6 && opt != 7 && opt != 8 && opt != 9) {
				cout << "ERROR!You have selected an invalid choice.";
				break;

			}


		}

	} while (opt != 9);
}



