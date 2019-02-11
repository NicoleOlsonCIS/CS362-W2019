//
//  cardtest3.c
//
//  This unit test tests the Village function
//  of the dominion.c.
//
//  THIS COMPONENT WAS NOT MODIFIED TO HAVE A BUG IN MY ASSIGNMENT 2 SUBMISSION
//
//
//  Testing Strategy:
//  -put a "Village" card in handposition 1 of player's hand
//  -count the cards in the hand, and print the location of Village
//  -count and display the number of actions of player 1
//  -call cardEffect(Village, x, y, z, 0 (position 1), b)
//  -count the cards in the hand, and check if Village card is pressent (should be +1 adjusted for discard)
//  -count and display the number of actions of player 1 (should be +2)
//  -In order to pass, must be +2 actions, and card hand count must be the same.
//
//
#include <stdio.h>
#include "..\..\dominion\dominion.h"
#include "..\..\dominion\dominion_helpers.h"
#include "..\..\dominion\rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int passflag = 1;  // any failures set to 0
    
    printf("Dominion Card Test 3: Village\n");
    printf("\n");
    printf("Testing -> cardEffect(Village, x, y, z, 0, b) \n");
    printf("\n");
    printf("Test that player hand++, action + 2, and proper discard of Village card\n");
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
    G.hand[0][0] = village;
    
    int card;
    char *type;
    
    printf("\n");
    printf("Player number of Actions prior to call: ");
    
    int actions = G.numActions;
    
    printf("%d", actions);
    printf("\n");
    printf("\n");

    printf("Player hand prior to call: \n");
    
    int h;
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(card == village)
        {
            type = "village";
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    printf("\n");
    int handsize = G.handCount[0];
    
    printf("Calling cardEffect(Village, x, y, z, 0, b) \n");
    printf("\n");
    printf("\n");

    int bonus = 0;
    // call to cardEffect
    int ret = cardEffect(village, -1, -1, -1, &G, 0, &bonus);
    
    int handsize2 = G.handCount[0];
    
    int pos1 = 1;
    // test 1
    printf("Player number of Actions post call: ");
    printf("\n");
    int actions2 = G.numActions;
    
    printf("%d", actions2);
    printf(" ");
    
    if(actions2 - actions == 2)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
        passflag = 0;
    }
    
    // test 2
    printf("Testing that village was discarded from position 1 in hand: \n");
    printf("Printing current hand: \n");
    printf("\n");
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(card == village)
        {
            type = "village";
            
            // if village found in position 1, then we failed to remove it
            if(h == 0)
                pos1 = 0;
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    printf("\n");
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
    printf("Testing that handsize increased by 1 (or 0 if village properly discarded): \n");
    printf("\n");
    int diff = handsize2 - handsize;
    
    if(pos1)
    {
        // if village was removed, expect handsize increase of 0
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
        // if village was not removed, expext handsize increase of 1
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
    printf("UNIT TEST SUMMARY: %s \n", summary);
    printf("\n");
    printf("\n");
    printf("Village united test completed without crashing\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    
    return 0;
}
