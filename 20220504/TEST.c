#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <vld.h>

typedef struct student
{
	int id;//�й�
	char name[20];//�̸�
	double kor;//���� ����
	double eng;//���� ����
	double mat;//���� ����
	double avg;// ���

}student;

void menu();//�޴� ���� �Լ�
void input(student* ps);//1.�Է� �Լ�
void output(student* ps);//2.��� �Լ�
void search(student* ps);//3.�˻� �Լ�

int count = 0;

void menu()
{
	int n = 0;

	student* list = (student*)calloc(1, sizeof(student));

	while (n != 4)
	{
		printf("���ϴ� �޴��� �����ϼ��� :\n1.�Է�\t2.���\t3.�˻�\t4.����\n");
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

	printf("�й� : ");
	scanf("%d", &(ps + count - 1)->id);
	printf("�̸� : ");
	scanf("%s", &(ps + count - 1)->name);
	printf("����(����,����,����) : ");
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
		printf("�й�=%d\t�̸�=%s\t���=%.1lf\n", (ps + i)->id, (ps + i)->name, (ps + i)->avg);
	}
}

void search(student* ps)
{
	char chSo[20];

	printf("�̸��� �Է����ּ��� : ");
	scanf("%s", chSo);

	for (int i = 0; i < count; ++i)
	{
		if (strcmp(chSo, (ps + i)->name) == 0)
		{
			printf("�й� : %d\t���� : %.1lf  %.1lf  %.1lf\n", (ps + i)->id, (ps + i)->kor, (ps + i)->eng, (ps + i)->mat);
		}
	}
}

int main(void)
{
	menu();

	return 0;
}