#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arrStudent[][4][2] =
	{	{{10, 30}, {25, 27}, {70, 21}, {50, 14}},
		{{100, 1}, {100, 1}, {100, 1}, {100, 1}},
		{{50, 11}, {60, 10}, {99, 3},  {50, 14}} };

	for (int i = 0; i < 3; ++i)
	{
		// �л� ��.
		printf("%d �� �л�\n", i + 1);

		for (int j = 0; j < 4; ++j)
		{
			printf("\t%d ����\n", j + 1);

			printf("���� : %d \t ���� : %d\n", arrStudent[i][j][0], arrStudent[i][j][1]);
		}

		printf("\n\n");
	}
}