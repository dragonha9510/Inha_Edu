#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <vld.h>

//	 Q1. p474 ��������
/*/
#define FROMTWOBEFORSELF(t) t - 2

void PrintPrimeNum(int a);
int	 CheckPrimeNum(int a);
void SetNum(int** p, int a);

int main()
{
	PrintPrimeNum(30);
	return 0;
}

void SetNum(int** p, int a)
{
	for (int i = 2; i < a; ++i)
	{
		*((*p) + (i - 2)) = i;
	}
}

void PrintPrimeNum(int a)
{
	int* pPrime;
	int iEndLine = 0;

	pPrime = (int*)malloc((FROMTWOBEFORSELF(a)) * sizeof(int));
	if (pPrime == NULL)
		exit(0);
	ZeroMemory(pPrime, (FROMTWOBEFORSELF(a)) * sizeof(int));

	SetNum(&pPrime, a);

	int iCnt = 0;

	while (iCnt < FROMTWOBEFORSELF(a))
	{
		if (CheckPrimeNum(*(pPrime + iCnt)))
			printf("%d\t", *(pPrime + iCnt));
		else
			printf("X\t");

		++iCnt;

		if (!(iCnt % 5))
			printf("\n");
	}

	free(pPrime);
}

int CheckPrimeNum(int a)
{
	for (int i = 2; i <= (a / 2); ++i)
		if (a % i == 0)
			return 0;

	return 1;
}
//*/

//	 Q2. p512 ��������
//		�й�, �̸�, ���� �Է� ���� �� �ִ� ����ü�� �����
//		���� ���� �л��� ���� �����͸� �Է¹޾� ����ϴ� �ڵ� �ۼ�
//		1. �Է�
//		2. ���
//		3. �˻�
//		4. ����
// 
//		-> �̸� �˻�, ������ ���� ���� �� ���
/*/
#define NULLCHECK(T)\
if( T == NULL )\
exit(1);

#define NULLCHECKREALLOC(T, O)\
if(T == NULL)\
{\
free(O);\
exit(1);\
}

#define MAXSTUDENT 5
#define MAXBUFFER 255

enum Subject { KOR = 0, ENG, MAT, SUBEND };

typedef struct student
{
	char	chName[20];
	char	chGrade;
	int		iID;
	int		iScore[SUBEND];
	int		iTotal;
	double	dScoreEver;
}STUDENT;

int CheckID(STUDENT** pstu, int stunum, int iID);
void InputInfo(STUDENT** pstu, int stunum);
void MakeTotEver(STUDENT** pstu, int stunum);
void SortWithGrade(STUDENT** pstu, int stunum);
void SearchWithName(STUDENT** pstu, int stunum);
void PrintStudentGrade(STUDENT** pstu, int stunum);

int main()
{
	system("cls");

	STUDENT* pStudent;

	int iStudentCnt = 0;
	int iExit = 0;
	
	pStudent = (STUDENT*)malloc(sizeof(STUDENT) * MAXSTUDENT);
	NULLCHECK(pStudent);
	memset(pStudent, 0, sizeof(STUDENT) * MAXSTUDENT);

	while (iExit == 0)
	{
		int iCase = 0;

		printf("1. �Է�, 2. ���, 3. �˻�, 4. ����\n");
		rewind(stdin);
		scanf("%d", &iCase);

		switch (iCase)
		{
		case 1://�Է�
			STUDENT* pTemp = pStudent;
			pStudent = (STUDENT*)realloc(pStudent, sizeof(STUDENT) * (++iStudentCnt));

			NULLCHECKREALLOC(pStudent, pTemp);

			if(iStudentCnt > 1)
				memset(pStudent + (iStudentCnt - 1), 0, sizeof(STUDENT));

			InputInfo(&pStudent, iStudentCnt);
			MakeTotEver(&pStudent, iStudentCnt);
			SortWithGrade(&pStudent, iStudentCnt);
			break;
		case 2://���
			PrintStudentGrade(&pStudent, iStudentCnt);
			break;
		case 3://�˻�
			SearchWithName(&pStudent, iStudentCnt);
			break;
		case 4:
			iExit = 1;
			break;
		}

		if (iExit)
			continue;

		system("pause");
		system("cls");
	}

	free(pStudent);

	return 0;
}

int CheckID(STUDENT** pstu, int stunum, int iID)
{
	for (int i = 0; i < stunum - 1; ++i)
	{
		if ((*pstu + i)->iID == iID)
			return 1;
	}

	return 0;
}

void InputInfo(STUDENT** pstu, int stunum)
{
	for (int i = 0; i < stunum; ++i)
	{
		if (strcmp((*pstu + i)->chName, ""))
			continue;

		char chNameTemp[MAXBUFFER];
		printf("�й� : ");
		scanf("%d", &((*pstu + i)->iID));

		if (CheckID(pstu, stunum, ((*pstu + i)->iID)))
		{
			printf("\t!!!!!�ߺ� �й�!!!!!\n");
			printf("�ٽ� �Է� �ٶ��ϴ�.\n\n");
			system("pause");
			--i;
			continue;
		}

		printf("�̸� : ");
		scanf("%s", chNameTemp);
		strcpy((*pstu + i)->chName, chNameTemp);

		printf("����, ����, ���� ���� : ");
		for (int j = 0; j < SUBEND; ++j)
			scanf("%d", &((*pstu + i)->iScore[j]));
	}
}

void MakeTotEver(STUDENT** pstu, int stunum)
{
	for (int i = 0; i < stunum; ++i)
	{
		(*pstu + i)->iTotal = 
			(*pstu + i)->iScore[KOR] + (*pstu + i)->iScore[ENG] + (*pstu + i)->iScore[MAT];
		(*pstu + i)->dScoreEver = (double)((*pstu + i)->iTotal) / SUBEND;

		if ((*pstu + i)->dScoreEver >= 90.0)
			(*pstu + i)->chGrade = 'A';
		else if ((*pstu + i)->dScoreEver >= 80.0)
			(*pstu + i)->chGrade = 'B';
		else if ((*pstu + i)->dScoreEver >= 70.0)
			(*pstu + i)->chGrade = 'C';
		else
			(*pstu + i)->chGrade = 'F';
	}
}

void SortWithGrade(STUDENT** pstu, int stunum)
{
	for (int i = 0; i < stunum; ++i)
	{
		for (int j = i + 1; j < stunum; ++j)
		{
			if (j == stunum)
				break;

			if ((*pstu + i)->dScoreEver > (*pstu + j)->dScoreEver)
			{
				STUDENT Temp = *(*pstu + i);
				*(*pstu + i) = *(*pstu + j);
				*(*pstu + j) = Temp;

				i = 0;
			}
		}
	}
}

void PrintStudentGrade(STUDENT** pstu, int stunum)
{
	for (int i = 0; i < stunum; ++i)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\t%c\n", 
			(*pstu + i)->iID, (*pstu + i)->chName, 
			(*pstu + i)->iScore[KOR], (*pstu + i)->iScore[ENG], (*pstu + i)->iScore[MAT], 
			(*pstu + i)->iTotal, (*pstu + i)->dScoreEver, 
			(*pstu + i)->chGrade);
	}
}

void SearchWithName(STUDENT** pstu, int stunum)
{
	char TempSearch[MAXBUFFER];
	printf("ã�� �̸� �Է� : ");
	scanf("%s", TempSearch);
	printf("\n");
	for (int i = 0; i < stunum; ++i)
	{
		if (!strcmp((*pstu + i)->chName, TempSearch))
		{
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\t%c\n",
				(*pstu + i)->iID, (*pstu + i)->chName,
				(*pstu + i)->iScore[KOR], (*pstu + i)->iScore[ENG], (*pstu + i)->iScore[MAT],
				(*pstu + i)->iTotal, (*pstu + i)->dScoreEver,
				(*pstu + i)->chGrade);
		}
	}
}
//*/

//*/
#define NULLCHECK(T)\
if( T == NULL )\
exit(1);

#define MAXSTUDENT 5
#define MAXBUFFER 255

enum Subject { KOR = 0, ENG, MAT, SUBEND };

typedef struct student
{
	char	chName[20];
	char	chGrade;
	int		iID;
	int		iScore[SUBEND];
	int		iTotal;
	double	dScoreEver;

	struct student* next_node;
}STUDENT;

int CheckID(STUDENT* pstu, STUDENT* orig);
void InputInfo(STUDENT* pstu, STUDENT* orig);
void MakeTotEver(STUDENT* pstu);
void SortWithGrade(STUDENT* pstu);
void SearchWithName(STUDENT* pstu);
void PrintStudentGrade(STUDENT* pstu);

void FreeForList(STUDENT* pstu);

int main()
{
	system("cls");

	STUDENT* pStudent = NULL;
	STUDENT* pNode = NULL;

	int iStudentCnt = 0;
	int iExit = 0;

	while (iExit == 0)
	{
		int iCase = 0;

		printf("1. �Է�, 2. ���, 3. �˻�, 4. ����\n");
		rewind(stdin);
		scanf("%d", &iCase);

		switch (iCase)
		{
		case 1://�Է�
			++iStudentCnt;
			if (iStudentCnt == 1)
			{
				pStudent = (STUDENT*)malloc(sizeof(STUDENT));
				pNode = pStudent;
			}
			else
			{
				pNode->next_node = (STUDENT*)malloc(sizeof(STUDENT));
				pNode = pNode->next_node;
			}

			NULLCHECK(pNode);

			memset(pNode, 0, sizeof(STUDENT));

			InputInfo(pNode, pStudent);
			MakeTotEver(pNode);
			SortWithGrade(pStudent);
			break;
		case 2://���
			PrintStudentGrade(pStudent);
			break;
		case 3://�˻�
			SearchWithName(pStudent);
			break;
		case 4:
			iExit = 1;
			break;
		}

		if (iExit)
			continue;

		system("pause");
		system("cls");
	}

	FreeForList(pStudent);

	return 0;
}

void FreeForList(STUDENT* pstu)
{
	if (pstu == NULL)
		return;

	FreeForList(pstu->next_node);
	free(pstu);
}

int CheckID(STUDENT* pstu, STUDENT* orig)
{
	STUDENT* pTemp = orig;

	while (pTemp != pstu)
	{
		if (pTemp->iID == pstu->iID)
			return 1;

		pTemp = pTemp->next_node;
	}
	return 0;
}

void InputInfo(STUDENT* pstu, STUDENT* orig)
{
	while (1)
	{
		char chNameTemp[MAXBUFFER];
		printf("�й� : ");
		scanf("%d", &((pstu)->iID));

		if (CheckID(pstu, orig))
		{
			printf("\t!!!!!�ߺ� �й�!!!!!\n");
			printf("�ٽ� �Է� �ٶ��ϴ�.\n\n");
			system("pause");
			continue;
		}

		printf("�̸� : ");
		scanf("%s", chNameTemp);
		strcpy((pstu)->chName, chNameTemp);

		printf("����, ����, ���� ���� : ");
		for (int j = 0; j < SUBEND; ++j)
			scanf("%d", &((pstu)->iScore[j]));
		break;
	}
}

void MakeTotEver(STUDENT* pstu)
{
	(pstu)->iTotal =
		(pstu)->iScore[KOR] + (pstu)->iScore[ENG] + (pstu)->iScore[MAT];
	(pstu)->dScoreEver = (double)((pstu)->iTotal) / (double)SUBEND;
	
	if ((pstu)->dScoreEver >= 90.0)
		(pstu)->chGrade = 'A';
	else if ((pstu)->dScoreEver >= 80.0)
		(pstu)->chGrade = 'B';
	else if ((pstu)->dScoreEver >= 70.0)
		(pstu)->chGrade = 'C';
	else
		(pstu)->chGrade = 'F';
}

void SortWithGrade(STUDENT* pstu)
{
	STUDENT* pTemp = pstu;
	STUDENT sortTemp;

	while (pTemp->next_node != NULL)
	{
		if (pTemp->dScoreEver < pTemp->next_node->dScoreEver)
		{
			STUDENT* first = pTemp->next_node;
			STUDENT* second = pTemp->next_node->next_node;
			
			sortTemp = *pTemp;

			*pTemp = *(pTemp->next_node);
			pTemp->next_node = first;

			*(pTemp->next_node) = sortTemp;
			pTemp->next_node->next_node = second;

			pTemp = pstu;

			continue;
		}

		pTemp = pTemp->next_node;
	}
}

void PrintStudentGrade(STUDENT* pstu)
{
	STUDENT* pTemp = pstu;

	while (pTemp != NULL)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\t%c\n",
			pTemp->iID, pTemp->chName,
			pTemp->iScore[KOR], pTemp->iScore[ENG], pTemp->iScore[MAT],
			pTemp->iTotal, pTemp->dScoreEver,
			pTemp->chGrade);

		pTemp = pTemp->next_node;
	}
}

void SearchWithName(STUDENT* pstu)
{
	char TempSearch[MAXBUFFER];
	printf("ã�� �̸� �Է� : ");
	scanf("%s", TempSearch);
	printf("\n");

	STUDENT* pTemp = pstu;

	while(pTemp != NULL)
	{
		if (!strcmp(pTemp->chName, TempSearch))
		{
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\t%c\n",
				pTemp->iID, pTemp->chName,
				pTemp->iScore[KOR], pTemp->iScore[ENG], pTemp->iScore[MAT],
				pTemp->iTotal, pTemp->dScoreEver,
				pTemp->chGrade);
		}

		pTemp = pTemp->next_node;
	}
}
//*/