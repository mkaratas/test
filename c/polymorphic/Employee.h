#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "Persion.h"

typedef struct _Employee Employee;

typedef struct _Employee {
	Persion *pBaseObj;
	char *pDepartment;
	char *pCompany;
	int nSalary;
} Employee;

Employee *new_Employee(const char* const pFirstName, const char* const pLastName,
                       const char* const pDepartment, 
                       const char* const pCompany, int nSalary);

void delete_Employee(Persion *);

void Employee_DisplayInfo(Persion *);
void Employee_WriteToFile(Persion *, const char *);

#endif /*__EMPLOYEE_H__*/
