#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee *new_Employee(const char* const pFirstName, const char* const pLastName,
					   const char* const pDepartment,
                       const char* const pCompany, int nSalary)
{
	Employee *pEmpObj;

	Persion *pObj = new_Persion(pFirstName, pLastName);
	if (!pObj) {
		perror("malloc()");
		return NULL;
	}
	pEmpObj = (Employee*)malloc(sizeof(Employee));
	if (!pEmpObj) {
		perror("malloc()");
		return NULL;
	}

	//pEmpObj->pBaseObj = pObj;
	pObj->pDerivedObj = pEmpObj;
	pEmpObj->pDepartment = malloc(sizeof(char)*strlen(pDepartment)+1);
	if (!pEmpObj->pDepartment) {
		perror("malloc()");
		return NULL;
	}
	pEmpObj->pCompany = malloc(sizeof(char)*strlen(pCompany)+1);
	if (!pEmpObj->pCompany) {
		perror("malloc()");
		return NULL;
	}
	pEmpObj->nSalary = nSalary;
	
	pObj->Display = Employee_DisplayInfo;
	pObj->WriteToFile = Employee_WriteToFile;
	pObj->Delete = delete_Employee;
}

void Employee_DisplayInfo(Persion *this)
{
	printf("Employee_DisplayInfo\n");
}

void Employee_WriteToFile(Persion *this, const char *file)
{
	printf("Employee_WriteToFile\n");
}

void delete_Employee(Persion *this)
{
	printf("delete_Employee\n");
	//free(this->pDerivedObj->pDepartment);
	//free(this->pDerivedObj->pCompany);
	//free(this->pDerivedObj);
	
	//this->De
}
