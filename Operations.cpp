#include "Operations.h"
#include "Repository.h"

void filterProjects(Project projects[], int n, int k, int l, Project result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (projects[i].getNoOfBranches() >= k && projects[i].getTotalNoOfCommits() >= l)
		{
			result[resultLen++] = projects[i];
		}
	}
}

void filterProjectsWithRepository(Repository Repository, int n, int k, int l, Project result[], int& resultLen)
{
	resultLen = 0;
	Project* initialProjects = Repository.getAll();
	return filterProjects(initialProjects, n, k, l, result, resultLen);
}

void elimProjects(Project projects[], int n, Project result[], int& resultLen)
{
	resultLen = 0;
	for (int i = 0; i < n; i++)
	{
		if (projects[i].getNoOfBranches() * projects[i].getTotalNoOfCommits() != 0)
		{
			result[resultLen++] = projects[i];
		}
	}
}

void elimProjectsWithRepository(Repository Repository, int n, Project result[], int& resultLen)
{
	resultLen = 0;
	Project* initialProjects = Repository.getAll();
	return elimProjects(initialProjects, n, result, resultLen);
}