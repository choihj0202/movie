#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

//structure definition
typedef struct movInfo {
	char name[100];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;

// ���� ������ �����ϴ� �Լ�
void* mv_genMvInfo(char* name, float score, int runTime, char* country)	  
{
	movInfo_t* mvPtr; // ����ü�� ����Ű�� ������ ���� ����  
	
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	if (mvPtr == NULL)	// �������� �޸𸮸� ����Ű�� �ִ����� ���� Ȯ��  
	{
		printf("[ERROR] abnormal memory!\n");
		return NULL;	// ����Ű�� ������ NULL �� ��ȯ  
	}
	
	strcpy(mvPtr->name, name);	// ����� ���� �迭�� ����ü�� ���� �迭�� ����  
	strcpy(mvPtr->madeIn, country);	// ����� ���� ���� �迭�� ����ü�� ���� ���� �迭�� ���� 
	mvPtr->runTime = runTime;	// ����� runtime�� ����ü�� runtime�� ���� 
	mvPtr->score = score;	// ����� ������ ����ü�� ������ ����  
	
	return (void*)mvPtr;	// ����ü ������ ��ȯ 
}

// ��ȭ ������ ����ϴ� �Լ�
void printMv(void* obj)	
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// ����� ��ȭ ���� �����͸� mvPtr�� ����  
	if (mvPtr == NULL)	// ���� ����� ��ȭ ������ ������ ���� ���� ���  
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);	// ��ȭ ���� ��� 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	printf("----------------------------------------\n");
	
	return;
}

// ��� ��ȭ�� ����ϴ� �Լ�  
int mv_printAll(void* obj, void* arg)	  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// ����� ��ȭ ���� �����͸� mvPtr�� ����
	
	printMv(mvPtr);	// printMv() �Լ��� �̿��� ���  
	
	return 1;	// main() �Լ����� ��µ� ��ȭ ������ ���� ���ϵ��� 1 ��ȯ  
}

// Ư�� ������ ��ȭ�� ����ϴ� �Լ�
int mv_printScore(void* obj, void* arg)	  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// ����� ��ȭ ���� �����͸� mvPtr�� ���� 
	
	if ((mvPtr->score) >= *(float*)arg)	// ���� �Է��� �������� ū ������ ��ȭ���� ����ϵ��� ��  
	{
		printMv(mvPtr);
		return 1;	// main() �Լ����� ��µ� ��ȭ ������ ���� ���ϵ��� 1 ��ȯ
	}

	return 0;
}

// Ư�� runtime�� ��ȭ�� ����ϴ� �Լ�
int mv_printRunTime(void* obj, void* arg)	 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// ����� ��ȭ ���� �����͸� mvPtr�� ����
	
	if ((mvPtr->runTime) >= *(int*)arg)	// ���� �Է��� runtime���� ū runtime�� ��ȭ���� ����ϵ��� ��  
	{
		printMv(mvPtr);
		return 1;	// main() �Լ����� ��µ� ��ȭ ������ ���� ���ϵ��� 1 ��ȯ
	}
	
	return 0;
}

// Ư�� ���� ������ ��ȭ�� ����ϴ� �Լ�
int mv_printCountry(void* obj, void* arg)	 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// ����� ��ȭ ���� �����͸� mvPtr�� ����
	
	if (strcmp(mvPtr->madeIn, (char*)arg) == 0)	// ����� ���� ������ ���� �Է��� ���� ������ ��ġ�ϴ� ��ȭ���� ����ϵ��� ��  
	{
		printMv(mvPtr);
		return 1;	// main() �Լ����� ��µ� ��ȭ ������ ���� ���ϵ��� 1 ��ȯ
	}	
	
	return 0;
}

