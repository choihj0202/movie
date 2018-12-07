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
	
	char ROW[200];
	char c;
	int i;
	int cnt = 0;
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	
	
	//1. reading the movie.dat-----------------------------
	//1.1 FILE open
	printf("Reading the data files...\n");
	
	fp = fopen("movie.dat", "r");
	
	if (fp == NULL)
		printf("[ERROR] cannot open!\n");
	else	
	{
		while (1)
		{
			fgets(ROW, 200, fp);
			cnt++;
			
			if ((c=fgetc(fp)) == EOF)
				break;
		}
	}
	
	printf("Read done! %d items are read\n\n\n\n", cnt);
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while ((c=fgetc(fp)) != EOF)/* read name, country, runtime and score*/
	{	
		//generate a movie info instance(mvInfo) with function mv_genMvInfo()
		mvInfo = mv_genMvInfo(name, score, runTime, country);
		list_addTail(mvInfo, list);
	}

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
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				
				// repeat until the ndPtr points to the end node
				while (list_getNextNd(ndPtr) != NULL)
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					
					//get object of ndPtr to mvInfo void pointer
					for (i=0; i<=cnt; i++)
					{
						name[i] = mv_getName(mvInfo);
					}
					
					//print the contents of the mvInfo
					mv_print(mvInfo);
				}
				
				break;
				
			case 2: //print movies of specific country
				
				//2.3.1 get country name to search for
				printf("select a country : ");
				scanf("%s", country);
				
				ndPtr = list;
				
				// repeat until the ndPtr points to the end node
				while (list_getNextNd(ndPtr) != NULL)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					
					//get object of ndPtr to mvInfo void pointer
					
					//if the input country matches to the country of the movie,
					if ( strnmp(country, mvInfo->(void*)country, strlen(country)) == 0 ) 
					//then print the contents of the mvInfo
					mv_print(mvInfo);
					
				}
				
				break;
				
			case 3:
				//2.4.1 get minimal runtime value to search for
				printf("select a minimal runtime : ");
				scanf("%d", &runTime);
				
				ndPtr = list;
				
				// repeat until the ndPtr points to the end node
				while (list_getNextNd(ndPtr) != NULL)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					
					//get object of ndPtr to mvInfo void pointer
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
					mv_print(mvInfo);
				}
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("select a minimal score : ");
				scanf("%d", &score);
				
				ndPtr = list;
				
				// repeat until the ndPtr points to the end node
				while (list_getNextNd(ndPtr) != NULL)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					ndPtr = list_getNextNd(ndPtr);
					
					//get object of ndPtr to mvInfo void pointer
					//if the input score is lower than the score of the movie,
					if (score < mvInfo->(void*)score )
					//then print the contents of the mvInfo
					mv_print(mvInfo);
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;
}
