
#include "..\..\dominion\dominion.h"
#include "..\..\dominion\dominion_helpers.h"
#include "..\..\dominion\rngs.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int assertEquals(int a, int b);
int assertDiff(int a, int b, int c);

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
		int cardCount;
		int choice1;
		int choiceValue; 
	};

	int playersArr[10];
	int currPlayerArr[10];
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

	// fill gameArr (array of initialized games)
	for (j = 0; j < 10; j++)
	{
		int skdjf = initializeGame(playersArr[j], kingdom, 3, &G);
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
		// make Salvager the first card in the hand
		gameArr[xx].hand[currPlayerArr[xx]][0] = 24;

		// fill the rest of the hand with random numbers not including Salvager
		// or any of the kingdom cards not included in kingdom
		for (yy = 0; yy < 499; yy++)
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
					if ((aa == includedKingdom[bb]) && (aa != 24))
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
		gV.cardCount = 500;
		gV.pre = gameArr[p];
		gV.post = gameArr[p];
		int cur = currPlayerArr[p];

		gV.pre.handCount[cur] = 500;
		gV.post.handCount[cur] = 500;

		gV.pre.whoseTurn = cur;
		gV.post.whoseTurn = cur;

		// randomly select a choice1 that is not Salvager or money
		int x = 0;
		int cc;
		// hand[player][0] = Salvager, so we pick between 1 - 499
		while (!x)
		{
			cc = rand() % (499 - 1) + 1;
			if (gameArr[p].hand[cur][cc] == 4)
				continue;
			else if (gameArr[p].hand[cur][cc] == 5)
				continue;
			else if (gameArr[p].hand[cur][cc] == 6)
				continue;
			else
			{
				// choice is a hand position that gets resolved in Salvager  
				gV.choice1 = cc;
				int number = gameArr[p].hand[cur][cc];
				int valueOfSelction = getCost(number);

				// reference to the value of the choice for calculation later
				gV.choiceValue = valueOfSelction;
				x++;
			}
		}
		// add game struct to array
		games[p] = gV;
	}

	// call Salvager, where games[y].post is a "gameState", and gets modified in the function call
	for (y = 0; y < 10; y++)
	{
		// current player is 0 and hand position of salvager is 0
		int ta = SalvagerAction(&games[y].post, games[y].choice1, games[y].pre.whoseTurn, 0);
	}

	// 4 TESTS
	int gg;
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	int t4 = 0;

	for (gg = 0; gg < 10; gg++)
	{
		int idx = 0;
		int count = 0;
		int count2 = 0;
		int turnNum = games[gg].pre.whoseTurn;

		// count the coins in the pre call state
		for (idx = 0; idx < games[gg].pre.handCount[turnNum]; idx++)
		{
			int val = games[gg].pre.hand[turnNum][idx];
			if (val == copper)
				count += 1;
			else if (val == silver)
				count += 2;
			else if (val == gold)
				count += 3;
		}

		for (idx = 0; idx < games[gg].post.handCount[turnNum]; idx++)
		{
			int val = games[gg].pre.hand[turnNum][idx];
			if (val == copper)
				count2 += 1;
			else if (val == silver)
				count2 += 2;
			else if (val == gold)
				count2 += 3;
		}

		// if choice > 0, then coins increase
		if (games[gg].choice1 > 0)
		{
			// TEST t1: testing that coins increased properly
			// ** will fail with bug introduced in a1
			// returns 1 for pass, 0 for fail
			int r1 = assertDiff(count2, count, games[gg].choiceValue);

			// if pass
			if (r1) { t1 = t1 | 0; }
			else { t1 = t1 | 1; }
		}

		// TEST t2: testing that salvager card is removed
		// should be removed regardless of choice > 0 
		// go through hand of post and look for int 2
		int cardsPost = numHandCards(&games[gg].post);
		int ff;
		int r2 = 0;
		for (ff = 0; ff < cardsPost; ff++)
		{
			// if it is ever equal to 24, r4 will become "1"
			r2 = r2 | assertEquals(games[gg].post.hand[turnNum][ff], 24);
		}
		// update bitwise OR of t2 to reflect success or failure to remove card
		t2 = t2 | r2;

		// TEST t3: number of buys increased by 1
		int buysBef = games[gg].pre.numBuys;
		int buysAft = games[gg].post.numBuys;
		int c = 1;

		int r3 = assertDiff(buysAft, buysBef, c);
		if (r3) { t3 = t3 | 0; }
		else { t3 = t3 | 1; }

		// TEST t4: testing that playedCardPile does NOT increase by more than 1 when choice > 0
		int r4 = 0;
		if (games[gg].choice1 > 0)
		{
			int pcpPre = games[gg].pre.playedCardCount;
			int pcpPost = games[gg].post.playedCardCount;

			int r4 = assertDiff(pcpPost, pcpPre, 1);
		}
		if (r4) { t4 = t4 | 1; }
		else { t4 = t4 | 0; }
	}

	// REVIEW AND PRINT RESULTS: check for errors, print errors
	int err = t1 + t2 + t3 + t4;

	printf("Salvager Action Random Input Unit Test \n");
	printf("\n");
	printf("\n");

	// if there were any errors
	if (err)
	{
		printf("SUMMARY: FAIL -> 1 or more tests failed for at least 1 test. See details below: \n \n ");
		printf("Specific failsures (");
		printf("%d", err);
		printf(" tests failed on at least 1 game input) \n\n");

		if (t1)
		{
			printf("FAILURE IN ADDING COINS FOR DISCARDED CARD \n");
		}
		if (t2)
		{
			printf("FAILURE TO REMOVE SALVAGER CARD FROM HAND \n");
		}
		if (t3)
		{
			printf("FAILURE TO INCREASE BUYS (+1) \n");
		}
		if (t4)
		{
			printf("FAILURE IN TRASHCARD WHEN CHOICE > 0 \n");
		}

		printf("\n");

		if(err < 4)
		{
			printf("OTHER TESTS PASSED\n");
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

