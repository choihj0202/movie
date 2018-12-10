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
	
	fp = fopen("movie.dat", "r");
	
	if (fp == NULL)
		printf("[ERROR] cannot open!\n");

	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while (fscanf(fp, "%s %s %d %f", name, country, &runTime, &score) != EOF) /* read name, country, runtime and score*/
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		mvInfo = mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);
	}
	printf("Read done! %d items are read\n\n\n\n", list_len(list));
	
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
		
		printf("-- select an option : ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("\nprinting all the movies in the list.....\n\n\n");
				printf("----------------------------------------\n");
				
				repFunc = mv_printAll;
				arg = NULL;
				
				break;
				
			case 2: //print movies of specific country
				printf("select a country : ");
				scanf("%s", country);
				printf("----------------------------------------\n");
				
				repFunc = mv_printCountry;
				arg = NULL;
				
				break;
				
			case 3: //print movies with long runtime
				printf("select a minimal runtime : ");
				scanf("%d", &runTime);
				
				repFunc = mv_printRunTime;
				arg = NULL;
				
				break;
				
			case 4: //print movies with high score
				printf("select a minimal score : ");
				scanf("%f", &score);
				
				repFunc = mv_printScore;
				arg = NULL;
				
				break;
				
			case 5:
				printf("\n\nBye!\n\n");
				exit_flag = 1;
				
				break;
				
			default:
				printf("wrong command! input again\n\n");
				break;
		}
		
		//2.2 printing operation by function pointer (list_repeatFunc() is called here)
		if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5)
		{
			list_repeatFunc(repFunc, arg, list);
			
			//2.3 print number of movies
			printf("\n    - totally %d movies are listed!\n\n\n\n", cnt);
		}
			
		
	}
	
	return 0;
}

