#include "Tests.h"
#include "Operations.h"
#include "assert.h"
#include <iostream>
using namespace std;

void testFilterProjects()
{
    Project p1("asj", 1, 3);
    Project p2("sws", 3, 4);
    Project p3("jjissj", 7, 9);
    Project p4("jwi", 6, 8);
    Project projects[4] = { p1, p2, p3, p4 };
    Project results[4];
    int m = 0;
    filterProjects(projects, 4, 6, 8, results, m);
    assert((m == 2) && (results[0] == p3) && (results[1] == p4));
}

void testFilterProjectsWithRepository() {
    Project p1("asj", 1, 3);
    Project p2("sws", 3, 4);
    Project p3("jjissj", 7, 9);
    Project p4("jwi", 6, 8);
    Repository rep;
    rep.addProject(p1);
    rep.addProject(p2);
    rep.addProject(p3);
    rep.addProject(p4);
    Project results[4];
    int m = 0;
    filterProjectsWithRepository(rep, 4, 6, 8, results, m);
    assert((m == 2) && (results[0] == p3) && (results[1] == p4));
}

void testElimProjects() {
    Project p1("sss", 5, 0);
    Project p2("bbb", 0, 7);
    Project p3("ccc", 0, 0);
    Project p4("ddd", 2, 0);
    Project p5("eee", 8, 7);
    Project projects[5] = { p1, p2, p3, p4, p5 };
    Project results[5];
    int m = 0;
    elimProjects(projects, 5, results, m);
    assert((m == 1) && (results[0] == p5));
}

void testElimProjectsWithRepository() {
    Project p1("sss", 5, 0);
    Project p2("bbb", 0, 7);
    Project p3("ccc", 0, 0);
    Project p4("ddd", 2, 0);
    Project p5("eee", 8, 7);
    Repository rep;
    rep.addProject(p1);
    rep.addProject(p2);
    rep.addProject(p3);
    rep.addProject(p4);
    rep.addProject(p5);
    Project results[5];
    int m = 0;
    elimProjectsWithRepository(rep, 5, results, m);
    assert((m == 1) && (results[0] == p5));
}

void testEntity() {
    Project p("git", 7, 9);
    assert(p.getGitPath() == "git");
    assert(p.getNoOfBranches() ==7);
    assert(p.getTotalNoOfCommits() == 9);
    p.setGitPath("aaa");
    assert(p.getGitPath() == "aaa");
    p.setTotalNoOfCommits(7);
    assert(p.getTotalNoOfCommits() == 7);
    Project q("mno", 5, 3);
    assert((p == q) == 0);
}

void testRepository() {
    Project p1("sap", 7, 4);
    Project p2("okrp", 3, 0);
    Repository rep;
    assert(rep.dim() == 0);
    rep.addProject(p1);
    rep.addProject(p2);
    assert(rep.dim() == 2);
    assert(rep.getAll()[0] == p1);
    assert(rep.getAll()[1] == p2);
}
