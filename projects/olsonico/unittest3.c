//
//  unittest3.c
//
//  This unit test tests the updateCoins() function
//  of the dominion.c. We test that this this function updates the
//  "state->coins" value to match the coins in the player's hand. We start with
//  the hand as initialized, and change copper, silver or gold in the player's hand.
//
//  Strategy:
//  Create and initialize a game
//  Print the coins in a player's hand
//  Change the coins in the player's hand
//  Calculate the state->coins value based on the change
//  Call the updateCoins() function
//  Print the state->coins value, determine if it matches
//
//
#include <stdio.h>
#include "../../dominion/dominion.h"
#include "../../dominion/dominion_helpers.h"
#include "../../dominion/rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
    char* summary = "PASS";
    int p1_copper = 0;
    int p1_silver = 0;
    int p1_gold = 0;
    
    int p1_copper2;
    int p1_silver2;
    int p1_gold2;
    
    printf("Dominion Unit Test 3\n");
    printf("\n");
    printf("Testing of function: updateCoins()\n");
    printf("\n");
    printf("Test that change in coins in hand reflected in 'state->coins' game state\n");
    printf("\n");
    printf("Commencing test ...\n");
    printf("\n");
    
    struct gameState G;
    int kingdom[10] = { smithy,
                        adventurer,
                        embargo,
                        cutpurse,
                        village,
                        mine,
                        minion,
                        sea_hag,
                        tribute,
                        gardens
        
    };
    
    int g = initializeGame(2, kingdom, 3, &G);
    
    printf("Player 1: pre-function coins: \n");
    printf("\n");
    
    int richness = 0;
    int c;
    for(c = 0; c < G.handCount[0]; c++)
    {
        if (G.hand[0][c] == copper)
        {
            p1_copper++;
            richness++;
        }
            
    }
    
    int s;
    for(s = 0; s < G.handCount[0]; s++)
    {
        if (G.hand[0][s] == silver)
        {
            p1_silver++;
            richness = richness + 2;
        }
    }
    
    int gd;
    for(gd = 0; gd < G.handCount[0]; gd++)
    {
        if (G.hand[0][gd] == gold)
        {
            p1_gold++;
            richness = richness + 3;
        }
    }
    
    printf("Copper: %d \n", p1_copper);
    printf("Silver: %d \n", p1_silver);
    printf("Gold: %d \n", p1_gold);
    printf("\n");
    printf("\n");
    printf("Total richness: %d", richness);
    printf("\n");
    printf("\n");

    if(p1_copper > 1)
    {
        int richenssExpect = richness + 2;
        
        printf("Now change player hand by copper--, gold++, expected richness %d: ", richenssExpect);
        printf("\n");
        printf("\n");

        int cg;
        for(cg = 0; cg < G.handCount[0]; cg++)
        {
            if(G.hand[0][cg] == copper)
            {
                G.hand[0][cg] = gold;
                break;
            }
        }
        
        int retGoldChnage = updateCoins(0, &G, 0);

        // count again
        p1_copper = 0;
        p1_silver = 0;
        p1_gold = 0;
        richness = 0;
        for (c = 0; c < G.handCount[0]; c++)
        {
            if (G.hand[0][c] == copper)
            {
                p1_copper++;
                richness++;
            }

        }

        int s;
        for (s = 0; s < G.handCount[0]; s++)
        {
            if (G.hand[0][s] == silver)
            {
                p1_silver++;
                richness = richness + 2;
            }
        }

        int gd;
        for (gd = 0; gd < G.handCount[0]; gd++)
        {
            if (G.hand[0][gd] == gold)
            {
                p1_gold++;
                richness = richness + 3;
            }
        }

        printf("Copper: %d \n", p1_copper);
        printf("Silver: %d \n", p1_silver);
        printf("Gold: %d \n", p1_gold);
        printf("\n");
        printf("Total richness: %d", richness);
        printf("\n");
        printf("EXPECTED: %d", richenssExpect);
        printf("\n");
        

        if(richness == richenssExpect)
            printf("PASS \n");
        else
        {
            printf("FAIL \n");
            summary = "FAIL";
        }

        printf("\n");
         
        printf("Now change player hand by copper--, silver++, expected richness %d: ", richenssExpect + 1);
        printf("\n");

        int cs;
        for(cs = 0; cs < G.handCount[0]; cs++)
        {
            if(G.hand[0][cs] == copper)
            {
                G.hand[0][cs] = silver;
                break;
            }
        }
        
        int retSilverChage = updateCoins(0, &G, 0);

        // count again
        richenssExpect = richness + 1;
        richness = 0;
        p1_copper = 0;
        p1_silver = 0;
        p1_gold = 0;

        for (c = 0; c < G.handCount[0]; c++)
        {
            if (G.hand[0][c] == copper)
            {
                p1_copper++;
                richness++;
            }

        }

        for (s = 0; s < G.handCount[0]; s++)
        {
            if (G.hand[0][s] == silver)
            {
                p1_silver++;
                richness = richness + 2;
            }
        }

        for (gd = 0; gd < G.handCount[0]; gd++)
        {
            if (G.hand[0][gd] == gold)
            {
                p1_gold++;
                richness = richness + 3;
            }
        }

        printf("Copper: %d \n", p1_copper);
        printf("Silver: %d \n", p1_silver);
        printf("Gold: %d \n", p1_gold);
        printf("\n");
        printf("Total richness: %d", richness);
        printf("\n");
        printf("EXPECTED: %d", richenssExpect);
        printf("\n");

        if (richness == richenssExpect)
            printf("PASS \n");
        else
        {
            printf("FAIL \n");
            summary = "FAIL";
        }

        printf("\n");
        printf("\n");
        printf("Now testing total coin count increase through bonus addition ...  \n");
        int cur = G.coins; 
        printf("Player's current coin count: %d", cur);
        printf("\n");
        printf("Adding bonus of 8, expected count after function: %d", cur + 8);
        printf("\n");
        
        int ret4 = updateCoins(0, &G, 8);
        
        /*richenssExpect = richness + 8;
        richness = 0; 
        p1_copper = 0;
        p1_silver = 0;
        p1_gold = 0;

        for (c = 0; c < G.handCount[0]; c++)
        {
            if (G.hand[0][c] == copper)
            {
                p1_copper++;
                richness++;
            }

        }

        for (s = 0; s < G.handCount[0]; s++)
        {
            if (G.hand[0][s] == silver)
            {
                p1_silver++;
                richness = richness + 2;
            }
        }

        for (gd = 0; gd < G.handCount[0]; gd++)
        {
            if (G.hand[0][gd] == gold)
            {
                p1_gold++;
                richness = richness + 3;
            }
        }

        printf("Copper: %d \n", p1_copper);
        printf("Silver: %d \n", p1_silver);
        printf("Gold: %d \n", p1_gold);
        printf("\n");
        printf("Total richness: %d", richness);
        printf("EXPECTED: %d", richenssExpect);
        printf("\n");
        */

        int cur2 = G.coins;

        if (cur2 == cur+8)
            printf("PASS \n");
        else
        {
            printf("FAIL \n");
            summary = "FAIL";
        }

        printf("\n");
        printf("\n");

    }
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("UNIT TEST SUMMAARY (must pass all tests for summary of PASS): %s", summary);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    return 0;
}
