#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "functions.h"


void mapfill(int **map, int topy, int topx)
{
	/// map filling
	int i, j;
	for (i = 0; i < topy; i++)
	{
		for (j = 0; j < topx; j++)
		{
			*(*(map + i) + j) = 32;
		}
	}
}

void mapprint(int **map, int topy, int topx)
{
	// print map
	int i, j;

	printf("\n");

	for (j = 0; j < (topx / 2) - 12; j++)
	{
		printf(" ");
	}
	printf("***BATTLESHIP LEGACY***\n");

	for (j = 0; j < topx; j++)
	{
		printf("_");
	}

	printf("\n\n");

	for (i = 0; i < topy; i++)
	{
		for (j = 0; j < topx; j++)
		{
			printf("%c", map[i][j]); // FORCE TO CHAR
		}
		printf("\n");
	}
	for (j = 0; j < topx; j++)
	{
		printf("_");
	}
}

void shooting(int **map, int topy, int topx, int *shipDpy, int *shipDpx, int *shipCpy, int *shipCpx, int *shipBpy, int *shipBpx, int *shipApy, int *shipApx)
{
	int shotx, shoty, i;
	do
	{
		printf("\n\nFIRE TO:\nX: ");
		fflush(stdin);
		scanf_s("%i", &shotx);
		getchar();
		if (shotx > topx-1 || shotx < 0)
		{
			printf("Must be a number between 0-%i",topx-1);
		}
	} while (shotx>topx-1 || shotx < 0);

	do
	{
		printf("\nY: ");
		fflush(stdin);
		scanf_s("%i", &shoty);
		getchar();
		if (shoty>topy-1 || shoty<0)
		{
			printf("Must be a number between 0-%i", topy-1);
		}
	} while (shoty > topy-1 || shoty < 0);

	*(*(map + shoty) + shotx) = 126;

	/// HITS ///////////////////////////

	//////////// SHIP D ////////////////

	for (i = 0; i < 4; i++)
	{
		if (*(shipDpy + i) == shoty && (*(shipDpx + i) == shotx))
		{
			*(*(map + shoty) + shotx) = 68;
		}
	}

	//////////// SHIP C ////////////////

	for (i = 0; i < 3; i++)
	{
		if (*(shipCpy + i) == shoty && (*(shipCpx + i) == shotx))
		{
			*(*(map + shoty) + shotx) = 67;
		}
	}

	//////////// SHIP B ////////////////

	for (i = 0; i < 2; i++)
	{
		if (*(shipBpy + i) == shoty && (*(shipBpx + i) == shotx))
		{
			*(*(map + shoty) + shotx) = 66;
		}
	}

	//////////// SHIP A ////////////////
	i = 0;
	if (*(shipApy + i) == shoty && (*(shipApx + i) == shotx))
	{
		*(*(map + shoty) + shotx) = 65;
	}
	
}

void shipgenerator(int *shipDpy, int *shipDpx, int *shipCpy, int *shipCpx, int *shipBpy, int *shipBpx,int *shipApy, int *shipApx, int topy, int topx)
{

	srand(time(NULL));
	int i, j;

	char confirmC = '0';
	char confirmB = '0';
	char confirmA = '0';

	/////////////////////////////////////    SHIP D    ////////////////
	// random point
	int shipDy, shipDx, shipDfacing;
	shipDy = rand() % topy;
	shipDx = rand() % topx;
	shipDfacing = rand() % 3;  // 0->North, 1->East, 2->South, 3->West

	// avoiding walls
	if (shipDy < 4 && shipDfacing == 0)
	{
		shipDfacing = 2;
	}
	if (shipDy > (topy - 4) && shipDfacing == 2)
	{
		shipDfacing = 0;
	}
	if (shipDx < 4 && shipDfacing == 3)
	{
		shipDfacing = 1;
	}
	if (shipDx > (topx - 4) && shipDfacing == 1)
	{
		shipDfacing = 3;
	}

	//ship growth in facing direction

	if (shipDfacing == 0)
	{
		for (i = 0; i < 4; i++)
		{
			*(shipDpy + i) = shipDy - i;
			*(shipDpx + i) = shipDx;
		}
	}

	if (shipDfacing == 1)
	{
		for (i = 0; i < 4; i++)
		{
			*(shipDpy + i) = shipDy;
			*(shipDpx + i) = shipDx + i;
		}
	}

	if (shipDfacing == 2)
	{
		for (i = 0; i < 4; i++)
		{
			*(shipDpy + i) = shipDy + i;
			*(shipDpx + i) = shipDx;
		}
	}

	if (shipDfacing == 3)
	{
		for (i = 0; i < 4; i++)
		{
			*(shipDpy + i) = shipDy;
			*(shipDpx + i) = shipDx - i;
		}
	}

	/////////////////////////////////////    SHIP C    ////////////////

	do
	{
		confirmC = '1';
		// random point
		int shipCy, shipCx, shipCfacing;
		shipCy = rand() % topy;
		shipCx = rand() % topx;
		shipCfacing = rand() % 3;  // 0->North, 1->East, 2->South, 3->West

		// avoiding walls
		if (shipCy < 3 && shipCfacing == 0)
		{
			shipCfacing = 2;
		}
		if (shipCy > (topy - 3) && shipCfacing == 2)
		{
			shipCfacing = 0;
		}
		if (shipCx < 3 && shipCfacing == 3)
		{
			shipCfacing = 1;
		}
		if (shipCx > (topx - 3) && shipCfacing == 1)
		{
			shipCfacing = 3;
		}

		//ship growth in facing direction

		if (shipCfacing == 0)
		{
			for (i = 0; i < 3; i++)
			{
				*(shipCpy + i) = shipCy - i;
				*(shipCpx + i) = shipCx;
			}
		}

		if (shipCfacing == 1)
		{
			for (i = 0; i < 3; i++)
			{
				*(shipCpy + i) = shipCy;
				*(shipCpx + i) = shipCx + i;
			}
		}

		if (shipCfacing == 2)
		{
			for (i = 0; i < 3; i++)
			{
				*(shipCpy + i) = shipCy + i;
				*(shipCpx + i) = shipCx;
			}
		}

		if (shipCfacing == 3)
		{
			for (i = 0; i < 3; i++)
			{
				*(shipCpy + i) = shipCy;
				*(shipCpx + i) = shipCx - i;
			}
		}

		///// avoiding collition with ship D

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (*(shipDpy + i) == *(shipCpy + j) && *(shipDpx + i) == *(shipCpx + j)) //<<<Checking if collides with D
				{
					printf("BOOOM-DC ");
					confirmC = '0';
				}
			}


		}
	} while (confirmC == '0');


	/////////////////////////////////////    SHIP B    ////////////////

	do
	{
		confirmB = '1';
		// random point
		int shipBy, shipBx, shipBfacing;
		shipBy = rand() % topy;
		shipBx = rand() % topx;
		shipBfacing = rand() % 3;  // 0->North, 1->East, 2->South, 3->West

		// avoiding walls
		if (shipBy < 2 && shipBfacing == 0)
		{
			shipBfacing = 2;
		}
		if (shipBy >(topy - 2) && shipBfacing == 2)
		{
			shipBfacing = 0;
		}
		if (shipBx < 2 && shipBfacing == 3)
		{
			shipBfacing = 1;
		}
		if (shipBx >(topx - 2) && shipBfacing == 1)
		{
			shipBfacing = 3;
		}

		//ship growth in facing direction

		if (shipBfacing == 0)
		{
			for (i = 0; i < 2; i++)
			{
				*(shipBpy + i) = shipBy - i;
				*(shipBpx + i) = shipBx;
			}
		}

		if (shipBfacing == 1)
		{
			for (i = 0; i < 2; i++)
			{
				*(shipBpy + i) = shipBy;
				*(shipBpx + i) = shipBx + i;
			}
		}

		if (shipBfacing == 2)
		{
			for (i = 0; i < 2; i++)
			{
				*(shipBpy + i) = shipBy + i;
				*(shipBpx + i) = shipBx ;
			}
		}

		if (shipBfacing == 3)
		{
			for (i = 0; i < 2; i++)
			{
				*(shipBpy + i) = shipBy ;
				*(shipBpx + i) = shipBx - i;
			}
		}

		///// avoiding collition with ship D

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 2; j++)
			{
				if (*(shipDpy + i) == *(shipBpy + j) && *(shipDpx + i) == *(shipBpx + j)) //<<<Checking if collides with D
				{
					printf("BOOOM-DB ");
					confirmB = '0';
				}
			}
		}

		///// avoiding collition with ship C

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 2; j++)
			{
				if (*(shipCpy + i) == *(shipBpy + j) && *(shipCpx + i) == *(shipBpx + j)) //<<<Checking if collides with C
				{
					printf("BOOOM-CB ");
					confirmB = '0';
				}
			}
		}

	} while (confirmB == '0');

	/////////////////////////////////////    SHIP A    ////////////////

	do
	{
		confirmA = '1';
		// random point
		int shipAy, shipAx;
		shipAy = rand() % topy;
		shipAx = rand() % topx;

		*(shipApy) = shipAy;
		*(shipApx) = shipAx;
		
		///// avoiding collition with ship D

		for (i = 0; i < 4; i++)
		{
			if (*(shipDpy + i) == *(shipApy) && *(shipDpx + i) == *(shipApx)) //<<<Checking if collides with D
			{
				printf("BOOOM-DA ");
				confirmA = '0';
			}	
		}

		///// avoiding collition with ship C

		for (i = 0; i < 3; i++)
		{
				if (*(shipCpy + i) == *(shipApy) && *(shipCpx + i) == *(shipApx)) //<<<Checking if collides with C
				{
					printf("BOOOM-CA ");
					confirmB = '0';
				}
		}

		///// avoiding collition with ship B

		for (i = 0; i < 2; i++)
		{
			if (*(shipBpy + i) == *(shipApy) && *(shipBpx + i) == *(shipApx)) //<<<Checking if collides with B
			{
				printf("BOOOM-BA ");
				confirmB = '0';
			}
		}

	} while (confirmA == '0');
}

int wincheck (int **map, int topy, int topx)
{
	int w = 0, i, j, a = 0, b = 0, c = 0, d = 0;

	for (i = 0; i < topy; i++)
	{
		for (j = 0; j < topx; j++)
		{
			if (*(*(map + i) + j) == 65)
			{
				a++;
			}

			if (*(*(map + i) + j) == 66)
			{
				b++;
			}
			if (*(*(map + i) + j) == 67)
			{
				c++;
			}
			if (*(*(map + i) + j) == 68)
			{
				d++;
			}
		}
	}

	if (a == 1 && b == 2 && c == 3 && d == 4)
	{
		w = 1;
	}
	return w;
}