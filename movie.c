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

// 영봐 정보를 생성하는 함수
void* mv_genMvInfo(char* name, float score, int runTime, char* country)	  
{
	movInfo_t* mvPtr; // 구조체를 가리키는 포인터 변수 선언  
	
	//allocate memory and set the member variables
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	if (mvPtr == NULL)	// 정상적인 메모리를 가리키고 있는지의 여부 확인  
	{
		printf("[ERROR] abnormal memory!\n");
		return NULL;	// 가리키지 않으면 NULL 값 반환  
	}
	
	strcpy(mvPtr->name, name);	// 저장된 제목 배열을 구조체의 제목 배열에 복사  
	strcpy(mvPtr->madeIn, country);	// 저장된 제작 국가 배열을 구조체의 제작 국가 배열에 복사 
	mvPtr->runTime = runTime;	// 저장된 runtime을 구조체의 runtime에 대입 
	mvPtr->score = score;	// 저장된 평점을 구조체의 평점에 대입  
	
	return (void*)mvPtr;	// 구조체 포인터 반환 
}

// 영화 정보를 출력하는 함수
void printMv(void* obj)	
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// 저장된 영화 정보 포인터를 mvPtr에 대입  
	if (mvPtr == NULL)	// 만약 저장된 영화 정보가 없으면 에러 문구 출력  
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);	// 영화 정보 출력 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	printf("----------------------------------------\n");
	
	return;
}

// 모든 영화를 출력하는 함수  
int mv_printAll(void* obj, void* arg)	  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// 저장된 영화 정보 포인터를 mvPtr에 대입
	
	printMv(mvPtr);	// printMv() 함수를 이용해 출력  
	
	return 1;	// main() 함수에서 출력된 영화 개수를 세기 편하도록 1 반환  
}

// 특정 평점의 영화를 출력하는 함수
int mv_printScore(void* obj, void* arg)	  
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// 저장된 영화 정보 포인터를 mvPtr에 대입 
	
	if ((mvPtr->score) >= *(float*)arg)	// 내가 입력한 평점보다 큰 평점의 영화만을 출력하도록 함  
	{
		printMv(mvPtr);
		return 1;	// main() 함수에서 출력된 영화 개수를 세기 편하도록 1 반환
	}

	return 0;
}

// 특정 runtime의 영화를 출력하는 함수
int mv_printRunTime(void* obj, void* arg)	 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// 저장된 영화 정보 포인터를 mvPtr에 대입
	
	if ((mvPtr->runTime) >= *(int*)arg)	// 내가 입력한 runtime보다 큰 runtime의 영화만을 출력하도록 함  
	{
		printMv(mvPtr);
		return 1;	// main() 함수에서 출력된 영화 개수를 세기 편하도록 1 반환
	}
	
	return 0;
}

// 특정 제작 국가의 영화를 출력하는 함수
int mv_printCountry(void* obj, void* arg)	 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;	// 저장된 영화 정보 포인터를 mvPtr에 대입
	
	if (strcmp(mvPtr->madeIn, (char*)arg) == 0)	// 저장된 제작 국가와 내가 입력한 제작 국가가 일치하는 영화만을 출력하도록 함  
	{
		printMv(mvPtr);
		return 1;	// main() 함수에서 출력된 영화 개수를 세기 편하도록 1 반환
	}	
	
	return 0;
}

