//
//  unittest4.c
//
//  This unit test tests part of the endTurn() function
//  of the dominion.c. We test that this this
//  function successfully moves the turn to the next player.
//  Function must account for the fact that in a 2 player game,
//  the end of Player 2 is not Player 3 but back to Player 1
//
//   Test 1:
//   Player 1's turn, after function, it is Player 2's turn
//
//   Test 2:
//   Player 2's turn, after function, it is Player 1's turn
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
    printf("Dominion Unit Test 4\n");
    printf("\n");
    printf("Testing of function: endTurn()\n");
    printf("\n");
    printf("Test that player is different after call to function\n");
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
    
    char* summary = "PASS";
    
    printf("Test 1: Call to endTurn on Player 1 yeilds Player 2 turn \n");
    printf("\n");
    int who = whoseTurn(&G);
    printf("Who before call: %d", who+1);
    printf("\n");
    int ret = endTurn(&G);
    int who2 = whoseTurn(&G);
    printf("Who after call: %d", who2+1);
    printf("\n");
    
    if (who2 == 1)
        printf("PASS \n");
    else
    {
        printf("FAIL \n");
        summary = "FAIL";
    }
    
    printf("\n");
    printf("Test 2: Call to endTurn on Player 2 (in a two player game) yeilds Player 1's turn\n");
    printf("\n");
    
    int who3 = whoseTurn(&G);
    printf("Who before call: %d", who3+1);
    printf("\n");
    int ret2 = endTurn(&G);
    int who4 = whoseTurn(&G);
    printf("Who after call: %d", who4+1);
    printf("\n");
    
    if(who4 == 0)
        printf("PASS \n");
    else
    {
        printf("FAIL \n");
        summary = "FAIL";
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
