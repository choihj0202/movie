#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	int (*repFunc)(void* obj, void* arg); //function pointer for using list_repeatFunc() function
	void *arg; //a void pointer for passing argument to repFunc
	int cnt = 0; //integer variable
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	printf("Reading the data files...\n");
	
	fp = fopen("movie.dat", "r");	// "movie.dat" 파일 열어서 읽기  
	
	if (fp == NULL)	// 파일이 비어있으면 에러 문구 출력 및 실행 종료  
	{
		printf("[ERROR] cannot open!\n");
		return 0; 
	} 
		

	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fscanf(fp, "%s %s %d %f", name, country, &runTime, &score) != EOF)	// read name, country, runtime and score
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		mvInfo = mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);
	}
	printf("Read done! %d items are read\n\n\n\n", list_len(list));	// 파일에 들어있는 영화 정보의 개수를 세고 출력  
	
	//1.4 FILE close
	fclose(fp);
	
	//2. program start
	while(exit_flag == 0)
	{
		//2.1 print menu message and get input option
		printf("-------------------- Menu --------------------\n");
		printf("1. print all the movies\n");
		printf("2. search for specific country movies\n");
		printf("3. search for specific runtime movies\n");
		printf("4. search for specific score movies\n");
		printf("5. exit\n");
		printf("-------------------- Menu --------------------\n\n");
		
		printf("-- select an option : ");	// option 입력 받음  
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;	// list_repeatFunc() 함수가 mv_printAll() 함수에 대해 실행되도록 함   

				break;
				
			case 2: //print movies of specific country
				printf("select a country : ");
				scanf("%s", country);	// 제작 국가를 country 배열에 입력 받음  
				printf("----------------------------------------\n");
				
				repFunc = mv_printCountry;	// list_repeatFunc() 함수가 mv_printCountry() 함수에 대해 실행되도록 함
				arg = country;	// mv_printCountry() 함수 내부의 if 문을 충족시키기 위해 arg에 내가 입력한 제작 국가 대입  
				
				break;
				
			case 3: //print movies with long runtime
				printf("select a minimal runtime : ");
				scanf("%d", &runTime);	// runtime을 runTime 변수에 입력 받음  
				printf("----------------------------------------\n");
				
				repFunc = mv_printRunTime;	// list_repeatFunc() 함수가 mv_printRunTime() 함수에 대해 실행되도록 함
				arg = &runTime;	// mv_printRunTime() 함수 내부의 if 문을 충족시키기 위해 arg에 내가 입력한 runTime 대입
				
				break;
				
			case 4: //print movies with high score
				printf("select a minimal score : ");
				scanf("%f", &score);	// 평점을 score 변수에 입력 받음  
				printf("----------------------------------------\n");
				
				repFunc = mv_printScore;	// list_repeatFunc() 함수가 mv_printScore() 함수에 대해 실행되도록 함
				arg = &score;	// mv_printScore() 함수 내부의 if 문을 충족시키기 위해 arg에 내가 입력한 평점 대입
				
				break;
				
			case 5:	// 영화 정보 출력 종료  
				printf("\n\nBye!\n\n");
				exit_flag = 1;  
				
				break;
				
			default:	// 잘못된 수 입력 시 
				printf("wrong command! input again\n\n");
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		if (option == 1 || option == 2 || option == 3 || option == 4)
		{
			cnt = list_repeatFunc(repFunc, arg, list);	// option 1, 2, 3, 4에 대해서만 영화 정보를 출력하고 출력된 영화 개수를 셈
			
			//2.3 print number of movies
			printf("\n    - totally %d movies are listed!\n\n\n\n", cnt); 
		}
	}
	
	return 0;
}

