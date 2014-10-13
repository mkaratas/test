#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Persion.h"

Persion *new_Persion(const char *pFirstName, const char *pLastName)
{
	Persion *pObj = (Persion *)malloc(sizeof(Persion));
	if (!pObj) {
		perror("malloc()");
		return NULL;
	}
	pObj->pDerivedObj = pObj;
	
	pObj->pFirstName = malloc(sizeof(char)*strlen(pFirstName) + 1);
	if (!pObj->pFirstName) {
		perror("malloc()");
		return NULL;
	}
	strncpy(pObj->pFirstName, pFirstName, sizeof(char)*strlen(pFirstName)+1);

	pObj->pLastName = malloc(sizeof(char)*strlen(pLastName)+1);
	if (!pObj->pLastName) {
		perror("malloc()");
		return NULL;
	}
	strncpy(pObj->pLastName, pLastName, sizeof(char)*strlen(pLastName)+1);
	
	pObj->Display = Persion_DisplayInfo;
	pObj->WriteToFile = Persion_WriteToFile;
	pObj->Delete = delete_Persion;
}

void Persion_DisplayInfo(Persion *this)
{
	printf("Persion_DisplayInfo\n");
}

void Persion_WriteToFile(Persion *this, const char *file)
{
	printf("Persion_WriteToFile\n");
}

void delete_Persion(Persion *this)
{
	printf("delete_Persion\n");
	free(this->pFirstName);
	free(this->pLastName);
	free(this);
}
