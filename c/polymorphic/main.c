#include <stdio.h>
#include "Persion.h"
#include "Employee.h"

int main(int argc, char **argv)
{
	Persion *pObj = new_Persion("Fred", "Cui");
	if (!pObj) {
		return -1;
	}

	Persion *pEmpObj = new_Employee("swust", "wang", "MIB", "sony", 100);
	if (!pEmpObj) {
		return -1;
	}

	pObj->Display(pObj);
	pObj->WriteToFile(pObj, "test.txt");
	pObj->Delete(pObj);
	
	pEmpObj->Display(pEmpObj);
	pEmpObj->WriteToFile(pEmpObj, "aa.txt");
	pEmpObj->Delete(pEmpObj);

	return 0;
}
