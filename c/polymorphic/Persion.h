#ifndef __PERSION_H_
#define __PERSION_H_

typedef struct _Persion Persion;

typedef void (*fptrDisplayInfo)(Persion *);
typedef void (*fptrWriteToFile)(Persion *, const char *);
typedef void (*fptrDelete)(Persion *);

typedef struct _Persion {
	void *pDerivedObj;
	char *pFirstName;
	char *pLastName;
	fptrDisplayInfo Display;
	fptrWriteToFile WriteToFile;
	fptrDelete Delete;
} Persion;

Persion *new_Persion(const char *pFirstName, const char *pLastName);
void delete_Persion(Persion *);

void Persion_DisplayInfo(Persion *this);
void Persion_WriteToFile(Persion *this, const char *file);

#endif /*__PERSION_H_*/
