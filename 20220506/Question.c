#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vld.h>

//   Q1. p554 ������������
/*/
#define FILENULLCHECK(t) if(t == NULL){printf("�Է� ������ ���� ���߽��ϴ�.\n");return 1;}

int main()
{
    FILE* afp;
    FILE* bfp;
    FILE* cfp;

    char ExistName[20];
    char InputName[20];

    int iRes = 0;
    int iCnt = 0;

    afp = fopen("a.txt", "r");
    FILENULLCHECK(afp);

    bfp = fopen("b.txt", "w");
    FILENULLCHECK(bfp);

    cfp = fopen("c.txt", "w");
    FILENULLCHECK(cfp);

    while (10 > iCnt++)
    {
        int iCheckName = 0;
        scanf("%s", InputName);

        if (!strcmp(InputName, "end"))
            break;

        fprintf(bfp, "%s\n", InputName);

        fseek(afp, 0, SEEK_SET);

        while (1)
        {
            iRes = fscanf(afp, "%s", ExistName);

            if (iRes == EOF)
                break;

            if (!strcmp(ExistName, InputName))
            {
                iCheckName = 1;
                break;
            }
        }

        if(iCheckName)
        {
            continue;   // �����ϹǷ� �Է� �ʿ� ����
        }

        fprintf(cfp, "%s\n", InputName);
    }

    fclose(afp);
    fclose(bfp);
    fclose(cfp);

    return 0;
}
//*/


//   Q2. ������ �Է�
/*/

#define FILENULLCHECK(t) if(t == NULL){printf("�Է� ������ ���� ���߽��ϴ�.\n");return 1;}

int main()
{
    FILE* afp;
    char GUGUDAN[20];

    afp = fopen("99.txt", "w+");
    FILENULLCHECK(afp);

    for (int i = 2; i < 10; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            fprintf(afp, "%2d X %2d = %2d\n", i, j, i * j);
        }
    }

    int iSel = 0;
    void* temp = NULL;

    while (1)
    {
        fseek(afp, 0, SEEK_SET);
        printf("���ϴ� ������ : ");
        scanf("%d", &iSel)
        if(EOF == (scanf("%d", &iSel)))
            break;

        if (!iSel)
            break;

        if (iSel < 2 || iSel > 9)
        {
            printf("������ ��� �ٽ��Է�\n");
            continue;
        }



        fseek(afp, 14 * (9 * (iSel - 2)), SEEK_SET);

        for(int i  = 0; i < 9; ++i)
        {
            temp = fgets(GUGUDAN, sizeof(GUGUDAN), afp);

            if (!temp)
                break;

            printf("%s", GUGUDAN);
        }
    }

    fclose(afp);

    return 0;
}

//*/

//   Q3. ���� ���� ���α׷� �����.
//      ������ ���ϸ�� ���� �� �����Ǵ� ���ϸ��� �Է¹޾Ƽ�
//      ������ ������ �����ϴ� ���α׷� �ۼ�
//      ��, ��� Ȯ���ڿ� ����Ǿ�� �Ѵ�.
//      ���� ��������� ������� ȭ�鿡 ǥ�����ְ�, �ѹ��� 4����Ʈ�� �����ϵ��� �Ѵ�.

//*/
#define FILENULLCHECK(t) if(t == NULL){printf("�Է� ������ ���� ���߽��ϴ�.\n");return 1;}
#define MAXCOPYBYTE 2

int main()
{
    FILE* sourfp = NULL;
    FILE* destfp = NULL;
    char chSourName[20];
    char chDestName[20];

    int iFileSize = 0;
    char chDefault[5] = ".txt";
    char chBuffer[MAXCOPYBYTE];
    char chExtension[20];

    while (1)
    {
        // ������ ����
        printf("���� ����!!\n\n\t���� �� ������ �̸� ( Ȯ���� default : .txt ) : ");
        scanf("%s", chSourName);

        if (!strcmp(chSourName, "end"))
            break;

        // Ȯ���� Ȯ�� 
        char* extension = strstr(chSourName, ".");

        if (!extension)
        {   // ������ default
            strcat(chSourName, chDefault);
            strcpy(chExtension, chDefault);
        }
        else
            strcpy(chExtension, extension);

        sourfp = fopen(chSourName, "rb");
        FILENULLCHECK(sourfp);

        // ������ ������ ũ��
        fseek(sourfp, 0, SEEK_END);     // �����͸� ������ ������ �̵���Ŵ
        iFileSize = ftell(sourfp);      // �������� ���� ��ġ�� ����
        fseek(sourfp, 0, SEEK_SET);     // �ٽ� ������ ó������ �̵���Ŵ

        // ������ ����
        printf("\t���� �� ������ �̸� : ");
        scanf("%s", chDestName);

        strcat(chDestName, chExtension);

        destfp = fopen(chDestName, "wb");
        FILENULLCHECK(destfp);

        // ���� ����
        int iEOF = 0;

        printf("\n���� ��...\n");

        int iMaxSize = iFileSize;
        int iCnt = 0;

        while (1)
        {
            if(iMaxSize < MAXCOPYBYTE)
                printf("���� ��...%.d%%\n", 100);
            if (iFileSize < MAXCOPYBYTE)
            {
                iEOF = fread((void*)chBuffer, iFileSize, 1, sourfp);
            }
            else
            {
                iEOF = fread((void*)chBuffer, sizeof(chBuffer), 1, sourfp);
                iFileSize -= MAXCOPYBYTE;
            }

            fwrite((void*)chBuffer, sizeof(chBuffer), 1, destfp);

            if (!iEOF)
                break;

            ++iCnt;
            if (!(iCnt % 4))
            {
                Sleep(50);
                system("cls");
                printf("���� ����!!\n");
                printf("���� ��...%.2lf%%\n", (((MAXCOPYBYTE * (double)iCnt) / (double)iMaxSize) * 100.0));
            }
        }
    }

    if(sourfp)
        fclose(sourfp);
    if(destfp)
        fclose(destfp);

    return 0;
}
//*/