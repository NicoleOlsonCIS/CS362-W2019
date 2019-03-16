//
//  cardtest4.c
//
//  This unit test tests the great_hall card
//  of the dominion.c.
//
//  THIS COMPONENT WAS NOT MODIFIED TO HAVE A BUG IN MY ASSIGNMENT 2 SUBMISSION
//
//
//  Testing Strategy:
//  -put a "great_hall" card in handposition 1 of player's hand
//  -count the cards in the hand, and print the location of great_hall
//  -count and display the number of actions of player 1
//  -call cardEffect(great_hall, x, y, z, 0 (position 1), b)
//  -count the cards in the hand, and check if great_hall card is pressent (should be +1 adjusted for discard)
//  -count and display the number of actions of player 1 (should be +1)
//  -In order to pass, must be +1 actions, and card hand count must be the same.
//
//
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int passflag = 1;  // any failures set to 0
    
    printf("Dominion Card Test 4: Great_Hall\n");
    printf("\n");
    printf("Testing -> cardEffect(Great_Hall, x, y, z, 0, b) \n");
    printf("\n");
    printf("Test that player hand++, action + 1, and proper discard of great_hall card\n");
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

    
    // overwrite the first card in player 1's hand with the "village" card
    G.hand[0][0] = great_hall;
    
    int card;
    char *type;
    
    printf("Player number of Actions prior to call: ");
    
    int actions = G.numActions;
    
    printf("%d", actions);
    printf("\n");
    
    printf("Player hand prior to call: \n");
    printf("\n");

    int h;
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(card == great_hall)
        {
            type = "great_hall";
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    int handsize = G.handCount[0];
    
    printf("\n");
    printf("Calling cardEffect(Great_Hall, ...) \n");
    printf("\n");
    
    int bonus = 0;
    // call to cardEffect
    int ret = cardEffect(great_hall, -1, -1, -1, &G, 0, &bonus);
    
    int handsize2 = G.handCount[0];
    
    int pos1 = 1;
    
    // test 1
    printf("Player number of Actions post call: ");
  
    int actions2 = G.numActions;
    
    printf("%d", actions2);
    printf(" ");
    
    if(actions2 - actions == 1)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        passflag = 0;
    }
    
    printf("\n");

    // test 2
    printf("Testing that great_hall was discarded from position 1 in hand: \n");
    printf("Printing current hand: \n");
    printf("\n");

    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(card == great_hall)
        {
            type = "great_hall";
            
            // if great_hall found in position 1, then we failed to remove it
            if(h == 0)
                pos1 = 0;
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    if(pos1)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        passflag = 0;
    }
    
    printf("\n");
    printf("\n");
    
    // test 2
    printf("Testing that handsize increased by 0 (or 1 if great_hall not discarded): \n");
    printf("\n");
    int diff = handsize2 - handsize;
    
    if(pos1)
    {
        // if great_hall was removed, expect handsize increase of 0
        if(diff == 0)
            printf("PASS\n");
        else
        {
            printf("FAIL\n");
            passflag = 0;
        }
    }
    else
    {
        // if great_hall was not removed, expext handsize increase of 1
        if(diff == 1)
            printf("PASS\n");
        else
        {
            printf("FAIL\n");
            passflag = 0;
        }
    }
    
    char* summary;
    if(passflag)
        summary = "PASS";
    else
    {
        summary = "FAIL";
    }
    
    printf("\n");
    printf("\n");
    printf("UNIT TEST SUMMARY: %s \n", summary);
    printf("\n");
    printf("\n");
    printf("Great_Hall united test completed without crashing\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    return 0;
}
