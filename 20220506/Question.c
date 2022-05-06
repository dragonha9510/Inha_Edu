#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vld.h>

//   Q1. p554 도전실전예제
/*/
#define FILENULLCHECK(t) if(t == NULL){printf("입력 파일을 열지 못했습니다.\n");return 1;}

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
            continue;   // 존재하므로 입력 필요 없음
        }

        fprintf(cfp, "%s\n", InputName);
    }

    fclose(afp);
    fclose(bfp);
    fclose(cfp);

    return 0;
}
//*/


//   Q2. 구구단 입력
/*/

#define FILENULLCHECK(t) if(t == NULL){printf("입력 파일을 열지 못했습니다.\n");return 1;}

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
        printf("원하는 구구단 : ");
        scanf("%d", &iSel)
        if(EOF == (scanf("%d", &iSel)))
            break;

        if (!iSel)
            break;

        if (iSel < 2 || iSel > 9)
        {
            printf("범위를 벗어남 다시입력\n");
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

//   Q3. 파일 복사 프로그램 만들기.
//      복사할 파일명과 복사 후 생성되는 파일명을 입력받아서
//      파일의 내용을 복사하는 프로그램 작성
//      단, 모든 확장자에 적용되어야 한다.
//      복사 진행과정을 백분율로 화면에 표시해주고, 한번에 4바이트씩 복사하도록 한다.

//*/
#define FILENULLCHECK(t) if(t == NULL){printf("입력 파일을 열지 못했습니다.\n");return 1;}
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
        // 복사할 파일
        printf("파일 복사!!\n\n\t복사 할 파일의 이름 ( 확장자 default : .txt ) : ");
        scanf("%s", chSourName);

        if (!strcmp(chSourName, "end"))
            break;

        // 확장자 확인 
        char* extension = strstr(chSourName, ".");

        if (!extension)
        {   // 없으면 default
            strcat(chSourName, chDefault);
            strcpy(chExtension, chDefault);
        }
        else
            strcpy(chExtension, extension);

        sourfp = fopen(chSourName, "rb");
        FILENULLCHECK(sourfp);

        // 복사할 파일의 크기
        fseek(sourfp, 0, SEEK_END);     // 포인터를 파일의 끝으로 이동시킴
        iFileSize = ftell(sourfp);      // 포인터의 현재 위치를 얻음
        fseek(sourfp, 0, SEEK_SET);     // 다시 파일의 처음으로 이동시킴

        // 복사한 파일
        printf("\t복사 한 파일의 이름 : ");
        scanf("%s", chDestName);

        strcat(chDestName, chExtension);

        destfp = fopen(chDestName, "wb");
        FILENULLCHECK(destfp);

        // 복사 시작
        int iEOF = 0;

        printf("\n복사 중...\n");

        int iMaxSize = iFileSize;
        int iCnt = 0;

        while (1)
        {
            if(iMaxSize < MAXCOPYBYTE)
                printf("복사 중...%.d%%\n", 100);
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
                printf("파일 복사!!\n");
                printf("복사 중...%.2lf%%\n", (((MAXCOPYBYTE * (double)iCnt) / (double)iMaxSize) * 100.0));
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