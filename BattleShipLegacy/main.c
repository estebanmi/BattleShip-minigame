#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "functions.h"


// Esteban Marin Illana

// BATTLESHIP LEGACY

/*Expand the Battleship assignment (follow the suggested order):
	1. The user should be able to enter a the size of the map. Use malloc to 
	   allocate the map and pointers read/write on it.
	2. The ships should be placed randomly in the map. Be careful no ships gets 
	   out of the boundaries and not on top of each other!
	3. Make so the ship could be horizontal or in vertical direction.
	4. Add one change of yours (e.g. 3 limited big bombs with radius, moving 
	   ships, AI opponent, torpedos that can “bomb” a straight line, radar scan in 
	   a spot tells you how far is the closest ship, etc ...)*/



int main()
{

	int ans = 121;

	do
	{


		int wincondition = 0, shots = 0;
		int topx = 10, topy = 10, i, j;
		int **map;
		int *shipDpy, *shipDpx, *shipCpy, *shipCpx, *shipBpy, *shipBpx, *shipApy, *shipApx;

		shipDpy = (int*)malloc(sizeof(int) * 4);  //memory ship D
		shipDpx = (int*)malloc(sizeof(int) * 4);

		shipCpy = (int*)malloc(sizeof(int) * 3);  //memory ship C
		shipCpx = (int*)malloc(sizeof(int) * 3);

		shipBpy = (int*)malloc(sizeof(int) * 2);  //memory ship B		
		shipBpx = (int*)malloc(sizeof(int) * 2);

		shipApy = (int*)malloc(sizeof(int));      //memory ship A
		shipApx = (int*)malloc(sizeof(int));

		/// MAP SIZE & MEMORY RESERVE
		system("cls");
		printf("WELCOME TO ***BATTLESHIP LEGACY*** by ESTEBAN MARIN");
		getchar();
		printf("ENTER MAP SIZE (minimum 6)");
		getchar();
		do
		{
			printf("X: ");
			scanf_s("%i", &topx);
			getchar();
			if (topx < 6)
			{
				printf("MINIMUM OF 6!\n");
			}

		} while (topx < 6);

		do
		{
			printf("Y: ");
			scanf_s("%i", &topy);
			getchar();
			if (topy < 6)
			{
				printf("MINIMUM OF 6!\n");
			}

		} while (topy < 6);

		map = (int**)malloc(topy*sizeof(int));

		for (i = 0; i < topy; i++)
		{
			for (j = 0; j < topx; j++)
			{
				map[i] = (int*)malloc(topx*sizeof(int));
			}
		}

		if (map == 0)
		{
			exit(0);
		}

		mapfill(map, topy, topx);
		shipgenerator(shipDpy, shipDpx, shipCpy, shipCpx, shipBpy, shipBpx, shipApy, shipApx, topy, topx);

		//////////////////////////////////////////////////////////////////SECRET PRINTING FOR PROGRAMMERS
		//printing D
		/*printf("\nSHIP D\n");
		for (i = 0; i < 4; i++)
		{
		printf("%i %i\n", *(shipDpx + i),*(shipDpy + i));
		}

		//printing C
		printf("\n\nSHIP C\n");
		for (i = 0; i < 3; i++)
		{
		printf("%i %i\n", *(shipCpx + i), *(shipCpy + i));
		}

		//printing B
		printf("\n\nSHIP B\n");
		for (i = 0; i < 2; i++)
		{
		printf("%i %i\n", *(shipBpx + i), *(shipBpy + i));
		}

		//printing A
		printf("\n\nSHIP A\n");
		printf("%i %i\n", *(shipApx), *(shipApy));

		getchar();
		getchar();*/


		do
		{
			system("cls");
			mapprint(map, topy, topx);
			shooting(map, topy, topx, shipDpy, shipDpx, shipCpy, shipCpx, shipBpy, shipBpx, shipApy, shipApx);
			shots++;
			wincondition = wincheck(map, topy, topx);
		} while (wincondition == 0);

		system("cls");
		mapprint(map, topy, topx);
		printf("\n");
		for (j = 0; j < (topx / 2) - 12; j++)
		{
			printf(" ");
		}
		printf("***********************\n");
		
		for (j = 0; j < (topx / 2) - 12; j++)
		{
			printf(" ");
		}
		
		printf("****CONGRATULATIONS****\n");
		for (j = 0; j < (topx / 2) - 12; j++)
		{
			printf(" ");
		}
		printf("***********************\n\nYou finished a %ix%i map in %i shots!\n\nPlay again ? (s / n)", topx, topy, shots);
		
		scanf_s("%i", &ans);
		getchar();

		free(map);
		free(shipDpy);
		free(shipDpx);
		free(shipCpy);
		free(shipCpx);
		free(shipBpy);
		free(shipBpx);
		free(shipApy);
		free(shipApx);

	}while (ans==121);

	
	
	getchar();
	return 0;
}

