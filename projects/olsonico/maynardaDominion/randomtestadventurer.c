#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int assertEquals(int a, int b);
int assertDiff(int a, int b, int c);
int getDiff(int a, int b);

int main(int argc, char** argv)
{
	int kingdom[10] =
	{
		smithy,
		adventurer,
		salvager,
		cutpurse,
		village,
		mine,
		minion,
		sea_hag,
		tribute,
		gardens
	};

	int includedKingdom[10] = { 13, 7, 24, 21, 14, 11, 17, 25, 19, 10 };

	struct gameValues
	{
		struct gameState pre;
		struct gameState post;
		int curPlayer;
	};

	int playersArr[10];
	int currPlayerArr[10];
	struct gameState gameArr[10];
	struct gameValues games[10];
	srand(time(0));
	struct gameState G;
	int a, b, c, d, e, f, g, h, i, j, k, l, m, p;

	// fill playerArr array
	for (a = 0; a < 10; a++)
	{
		b = (rand() % (4 - 2 + 1)) + 2;
		playersArr[a] = b;
		int bl = (rand() % (b - 2 + 1)) + 2;
		currPlayerArr[a] = bl;
	}

	// fill gameArr (array of initialized games)
	for (c = 0; c < 10; c++)
	{
		int skdjf = initializeGame(playersArr[c], kingdom, 3, &G);
		gameArr[c] = G;
	}

	// create hand for all players putting Adventurer in position 0
	int xx;
	int yy;
	int zz;
	int aa;
	int bb;

	// for each game
	for (xx = 0; xx < 10; xx++)
	{
		for (d = 0; d < gameArr[xx].numPlayers; d++)
		{
			// make Adventurer the first card in the hand
			gameArr[xx].hand[d][0] = 7;
			gameArr[xx].handCount[d] = 5;
			gameArr[xx].deckCount[d] = 10;

			// create a hand of 5 for each player
			for (yy = 1; yy < 5; yy++)
			{
				zz = 0;
				while (!zz)
				{
					aa = rand() % (27 - 1) + 1;

					// if it is a coin card
					if (aa == copper || aa == silver || aa == gold)
					{
						gameArr[xx].hand[d][yy] = aa;
						zz = 1;
						break;
					}

					// Or if bb is a kingdom card that is included in the game
					for (bb = 0; bb < 10; bb++)
					{
						// if it is
						if (aa == includedKingdom[bb])
						{
							// put it in the hand
							gameArr[xx].hand[d][yy] = aa;
							zz = 1;
							break;
						}
					}
				}
			}
		}
	}

	// initialize the gameValues structs and randomly select a currentPlayer
	for (p = 0; p < 10; p++)
	{
		struct gameValues gV;
		//gV.cardCount = 500;
		gV.pre = gameArr[p];
		gV.post = gameArr[p];
		gV.pre.handCount[0] = 5;
		gV.curPlayer = 1;

		// add game struct to array
		games[p] = gV;
	}

	int temp[500];
	int* temphand = temp;
	// call Adventurer
	for (f = 0; f < 10; f++)
	{
		games[f].post.whoseTurn = 1;
		int ta = adventurerCard(&games[f].post);
	}

	// 1 TEST
	int gg;
	int t1 = 0; // test that there are 2 extra treasures in hand
	int differences[10];

	for (gg = 0; gg < 10; gg++)
	{
		int idx = 0;
		int count = 0;
		int count2 = 0;
		int player = 1;

		// count the coins in the pre call state
		for (idx = 0; idx < games[gg].pre.handCount[player]; idx++)
		{
			int val = games[gg].pre.hand[player][idx];
			if (val == copper)
				count += 1;
			else if (val == silver)
				count += 1;
			else if (val == gold)
				count += 1;
		}

		for (idx = 0; idx < games[gg].post.handCount[player]; idx++)
		{
			int val = games[gg].post.hand[player][idx];
			if (val == copper)
				count2 += 1;
			else if (val == silver)
				count2 += 1;
			else if (val == gold)
				count2 += 1;
		}
			
			// TEST t1: testing that coins increased properly
			// ** will fail with bug introduced in a1
			// returns 1 for pass, 0 for fail
			int r1 = assertDiff(count2, count, 2);
			differences[gg] = getDiff(count2, count);


			// if pass
			if (r1) { t1 = t1 | 0; }
			else { t1 = t1 | 1; }
	}

	// REVIEW AND PRINT RESULTS: check for errors, print errors
	int err = t1;

	printf("ADVENTURER ACTION Random Input Unit Test \n");
	printf("\n");
	printf("\n");

	// if there were any errors
	if (err)
	{
		printf("SUMMARY: FAIL \n \n");

		if (t1)
		{
			printf("FAILED TO ADD 2 TREASURE CARDS TO HAND \n");
			int results;
			printf("Number of coin cards added for each game: \n");
			for (results = 0; results < 10; results++)
			{
				printf("%d", differences[results]);
				printf(" ");
			}
			printf("\n\n");
		}
	}
	else
	{
		printf("SUMMARY: PASS \n\n\n");
	}

	return 0;
}

// if equal, return 1
int assertEquals(int a, int b)
{
	// check two things are equal
	if (a == b)
		return 1;
	else
		return 0;
}

// if the correct difference exists, return 1
int assertDiff(int a, int b, int c)
{
	// check that thing a is different from thing b by a factor of thing c
	if ((a - b) == c)
		return 1;
	else
		return 0;
}

int getDiff(int a, int b)
{
	return a - b; 
}