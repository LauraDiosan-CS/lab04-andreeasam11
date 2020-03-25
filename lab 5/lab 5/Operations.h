#pragma once
#include "Project.h"
#include "Repository.h"

void filterProjects(Project projects[], int n, int k, int l, Project result[], int& resultLen);
void filterProjectsWithRepository(Repository repo, int n, int k, int l, Project result[], int& resultLen);
void elimProjects(Project projects[], int n, Project result[], int& resultLen);
void elimProjectsWithRepository(Repository repo, int n, Project result[], int& resultLen);