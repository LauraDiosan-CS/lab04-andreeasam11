#pragma once
#include "Project.h"
#include "Repository.h"

void filterProjects(Project projects[], int n, int k, int l, Project result[], int& resultLen);
void filterProjectsWithRepository(Repository Repository, int n, int k, int l, Project result[], int& resultLen);
void elimProjects(Project projects[], int n, Project result[], int& resultLen);
void elimProjectsWithRepository(Repository Repository, int n, Project result[], int& resultLen);