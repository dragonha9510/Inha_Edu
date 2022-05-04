#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <vld.h>

typedef struct student
{
	int id;//학번
	char name[20];//이름
	double kor;//국어 성적
	double eng;//영어 성적
	double mat;//수학 성적
	double avg;// 평균

}student;

void menu();//메뉴 선택 함수
void input(student* ps);//1.입력 함수
void output(student* ps);//2.출력 함수
void search(student* ps);//3.검색 함수

int count = 0;

void menu()
{
	int n = 0;

	student* list = (student*)calloc(1, sizeof(student));

	while (n != 4)
	{
		printf("원하는 메뉴를 선택하세요 :\n1.입력\t2.출력\t3.검색\t4.종료\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			++count;
			student* pOld = list;
			list = (student*)realloc(list, sizeof(student) * count);

			if (list == NULL)
			{
				free(pOld);
				exit(1);
			}

			input(list);
			break;
		case 2:
			output(list);
			break;
		case 3:
			search(list);
			break;
		case 4:
			break;

		}
	}

	free(list);
}

void input(student* ps)
{
	int temp = 0;
	student sTemp;

	printf("학번 : ");
	scanf("%d", &(ps + count - 1)->id);
	printf("이름 : ");
	scanf("%s", &(ps + count - 1)->name);
	printf("성적(국어,영어,수학) : ");
	scanf("%lf%lf%lf", &(ps + count - 1)->kor, &(ps + count - 1)->eng, &(ps + count - 1)->mat);

	(ps + count - 1)->avg = ((ps + count - 1)->kor + (ps + count - 1)->eng + (ps + count - 1)->mat) / 3.0;

	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if ((ps + i)->avg < (ps + j)->avg)
			{
				sTemp = *(ps + i);
				*(ps + i) = *(ps + j);
				*(ps + j) = sTemp;

				i = 0;
			}
		}
	}
}

void output(student* ps)
{
	for (int i = 0; i < count; ++i)
	{
		printf("학번=%d\t이름=%s\t평균=%.1lf\n", (ps + i)->id, (ps + i)->name, (ps + i)->avg);
	}
}

void search(student* ps)
{
	char chSo[20];

	printf("이름을 입력해주세요 : ");
	scanf("%s", chSo);

	for (int i = 0; i < count; ++i)
	{
		if (strcmp(chSo, (ps + i)->name) == 0)
		{
			printf("학번 : %d\t성적 : %.1lf  %.1lf  %.1lf\n", (ps + i)->id, (ps + i)->kor, (ps + i)->eng, (ps + i)->mat);
		}
	}
}

int main(void)
{
	menu();

	return 0;
}