#include "../../dominion/dominion.h"
#include "../../dominion/dominion_helpers.h"
#include "../../dominion/rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int assertEquals(int a, int b);
int assertDiff(int a, int b, int c);

int main(int argc, char** argv)
{
	//king arr choices
	int kingArr[20] = 
	{   adventurer, 
		council_room,
		feast, 
		gardens,
		mine,
		remodel,
		smithy,
		village,
		baron,
		great_hall,
		minion,
		steward,
		tribute,
		ambassador,
		cutpurse,
		embargo,
		outpost,
		salvager,
		sea_hag,
		treasure_map
	};
	
	struct gameValues
	{
		struct gameState pre;
		struct gameState post;
		int placeInHand; 
	};

	int playersArr[10];
	int currPlayerArr[10];
	int kingdom[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int kingdoms[10][10];
	struct gameState g;
	struct gameState gameArr[10];
	struct gameValues games[10];
	srand(time(0));
	struct gameState G;
	const int TEST_SIZE = 10;
	int num, handCount, handLoc, choice1, i, j, k, l, m, n, o, p, u, v, w, x, y, z = 0;
	char* summary = "PASS";

	// fill playerArr array
	for (i = 0; i < 10; i++)
	{
		num = (rand() % (4 - 2 + 1)) + 2;
		playersArr[i] = num;
	}

	// fill currPlayerArr array
	for (i = 0; i < 10; i++)
	{
		int w = playersArr[i];

		num = (rand() % (w - 2 + 1)) + 2;

		currPlayerArr[i] = num;
	}

	// create 10 kingdom arrays 
	for (i = 0; i < 10; i++)
	{
		kingdoms[i][0] = smithy; 

		for (j = 1; j < 10; j++)
		{
			o = 0;
			while (!o)
			{
				// select random number between 0 and 19
				num = (rand() % 19 - 0 + 0);
				int numVal = kingArr[num];

				int found = 0;
				// go through the ones that have already been added to make sure no duplicate
				for (k = 0; k < j; k++)
				{
					if (kingdoms[i][k] == numVal)
					{
						found = 1;
						continue;
					}
				}
				if (!found)
				{
					kingdoms[i][j] = numVal;
					o = 1;
				}
			}
			
		}
	}

	// fill gameArr (array of initialized games)
	for (j = 0; j < 10; j++)
	{
		int skdjf = initializeGame(playersArr[j], kingdoms[j], 3, &G);
		gameArr[j] = G;
	}

	// create hand for player 0 putting Salvager in position 0
	int xx;
	int yy;
	int zz;
	int aa;
	int bb;

	// for each game only create a hand for the randomly selected current player
	for (xx = 0; xx < 10; xx++)
	{
		// make smithy the first card in the hand
		gameArr[xx].hand[currPlayerArr[xx]][0] = smithy;

		// fill the rest of the hand with random numbers not including smithy
		// or any of the kingdom cards included in kingdom
		for (yy = 1; yy < 496; yy++)
		{
			zz = 0;
			while (!zz)
			{
				aa = rand() % (27 - 1) + 1;

				// if it is a coin card
				if (aa == copper || aa == silver || aa == gold)
				{
					gameArr[xx].hand[currPlayerArr[xx]][yy] = aa;
					zz = 1;
					break;
				}

				// Or if bb is a kingdom card that is included in the game
				for (bb = 0; bb < 10; bb++)
				{
					// if it is
					if ((aa == kingdoms[xx][bb]) && (aa != smithy))
					{
						// put it in the hand
						gameArr[xx].hand[currPlayerArr[xx]][yy] = aa;
						zz = 1;
						break;
					}
				}
			}
		}
	}

	// initialize the gameValues structs and randomly select a choice card
	for (p = 0; p < 10; p++)
	{
		struct gameValues gV;
		gV.pre = gameArr[p];
		gV.post = gameArr[p];
		gV.placeInHand = 0; 
		int cur = currPlayerArr[p];

		gV.pre.handCount[cur] = 497;
		gV.post.handCount[cur] = 497;
		gV.pre.deckCount[cur] = 10;
		gV.post.deckCount[cur] = 10;

		gV.pre.whoseTurn = cur;
		gV.post.whoseTurn = cur;

		// add game struct to array
		games[p] = gV;
	}

	// call Smithy, where games[y].post is a "gameState", and gets modified in the function call
	for (y = 0; y < 10; y++)
	{
		// current player is 0 and hand position of salvager is 0
		int ta = SmithyAction(games[y].pre.whoseTurn, &games[y].post, games[y].placeInHand);
	}

	// 2 TESTS
	int gg;
	int t1 = 0;
	int t2 = 0;

	for (gg = 0; gg < 10; gg++)
	{
		int idx = 0;
		int count = 0;
		int count2 = 0;
		int turnNum = games[gg].pre.whoseTurn;

		// TEST t1: test that smithy was discarded from position 0/1 from hand
		int val = games[gg].post.hand[turnNum][0];

		int r1 = assertEquals(val, smithy);

		// fail
		if (r1)
			t1 = t1 | r1;

		// TEST t2: test that 3 cards were added
		// if r1 == 1, then we test that 3 card increase
		// if r1 == 0, then we test that 2 card increase
		count = games[gg].pre.handCount[turnNum];
		count2 = games[gg].post.handCount[turnNum];

		if (r1)
		{
			int r2 = assertDiff(count2, count, 3);

			// if that's not the difference (return 0)
			if (!r2)
				t2 = t2 | r2;
		}
		if (!r1)
		{
			int r2 = assertDiff(count2, count, 2);

			// if that's not the difference (return 0)
			if (!r2)
				t2 = t2 | r2;
		}
	}

	// REVIEW AND PRINT RESULTS: check for errors, print errors
	int err = t1 + t2;

	printf("SMITHY ACTION Random Input Unit Test \n");
	printf("\n");
	printf("\n");

	// if there were any errors
	if (err)
	{
		printf("SUMMARY: FAIL See details below:\n\n");

		if (t1)
		{
			printf("FAILURE IN REMOVING SMITHY CARD FROM HAND \n");
		}
		if (t2)
		{
			printf("FAILURE TO ADD 3 CARDS TO HAND \n");
		}
		printf("\n");

		if (err < 2)
		{
			printf("OTHER TESTS PASSED\n");
		}
	}
	else
	{
		printf("SUMMARY: PASS \n\n\n");
	}

	printf("\n\n\n");
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