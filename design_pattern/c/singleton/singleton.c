#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static const char NAME[]="cjzswust";
static const char NAME2[]="fred";

typedef struct _DATA {
	char name[10];
	int age;
} DATA;

DATA* get()
{
	static DATA* pdata = NULL;
	
	if (pdata)
		return pdata;

	pdata = (DATA*)malloc(sizeof(DATA));
	assert(NULL!=pdata);
	return pdata;
}

int main(int argc, char **argv)
{
	DATA *pd = get();
	strncpy(pd->name, NAME, sizeof(NAME));
	pd->age = 10;
	
	printf("name: %s\n", pd->name);
	printf("age : %d\n", pd->age);

	DATA *pb = get();
	strncpy(pb->name, NAME2, sizeof(NAME2));
	pd->age = 30;
	printf("name: %s\n", pd->name);
	printf("age : %d\n", pd->age);
	
	return 0;
}
