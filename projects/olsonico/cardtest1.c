//
//  cardtest1.c
//
//  This unit test tests Adventurer function
//  of the dominion.c. IN ASSIGNMENT 2 I MODIFIED THIS FUNCTION TO HAVE A BUG
//
//  NORMALLY, this function would add 2 coin cards from the deck to the hand.
//  The bug I introduced meant adding 5 coin cards into the hand.
//
//
//  Testing Strategy:
//  -Call to cardEffect selecting for the AdventurerAction
//  -i.e. cardEffect(cardEffect(Adventurer, int choice1, int choice2, int choice3, gamestate, handpos, bonus)
//  -print hand before call, print hand after call
//  -hand after should reflect +2 coin cards
//  -PASS if true, FAIL if false
//
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
    int passflag = 1;  // any failures set to 0
    
    printf("Dominion Card Test 1: Adventurer\n");
    printf("\n");
    printf("NOTE: test expected to fail due to intentional bug introduced in assignment 2\n");
    printf("\n");
    printf("Testing -> cardEffect(Adventurer, x, y, z, a, b) \n");
    printf("\n");
    printf("Test that player hand + 2 treasure cards after call\n");
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
    
    int card;
    char *type;
    printf("Player hand prior to call: \n");
    
    int h;
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(
            (card == copper)||
            (card == silver)||
            (card == gold)
           )
        {
            type = "treasure";
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    int handsize = G.handCount[0];
    
    printf("Calling cardEffect(Adventurer, ...) \n");
    
    int bonus = 0;
    
    int ret = cardEffect(adventurer, -1, -1, -1, &G, 0, &bonus);
    
    printf("Player hand post function: \n");
    
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(
           (card == copper)||
           (card == silver)||
           (card == gold)
           )
        {
            type = "treasure";
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    printf("Check: Hand size + 2? \n");
    
    int handsize2 = G.handCount[0];
    
    if(handsize2 - handsize == 2)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n"); // will fail due to introduced bug
        passflag = 0;
    }
    
    
    printf("Check: Additional cards ALL TREASURE? \n");
    
    int handsizeDiff = handsize2 - handsize;
    int fail = 0;
    
    if(handsizeDiff < 1)
    {
        printf("CANNOT DO SECOND TEST, HANDSIZE NOT INCREASED.\n");
    }
    else
    {
        int k;
        for(k = handsize - 1; k < handsize2; k++) // look at added cards and check if they are all treasure
        {
            card = G.hand[0][k];
            
            if(
               (card == copper)||
               (card == silver)||
               (card == gold)
               )
            {
                continue;
            }
            else
            {
                fail = 1;
                break;
            }
        }
        
        if(fail)
        {
            printf("FAIL\n");
            passflag = 0;
        }
        else
            printf("PASS\n");
    }
    
    char* summary;
    if(passflag)
        summary = "PASS";
    else
    {
        summary = "FAIL";
    }
    
    printf("UNIT TEST SUMMARY: %s \n", summary);
    printf("\n");
    printf("\n");
    printf("Adventurer united test completed without crashing\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    return 0;
}
