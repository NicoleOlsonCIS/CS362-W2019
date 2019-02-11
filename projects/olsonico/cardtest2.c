//
//  cardtest2.c
//
//  This unit test tests Smithy function
//  of the dominion.c.
//
//  IN ASSIGNMENT 2 I MODIFIED THIS FUNCTION BY REMOVING THE CALL TO "discardCard"
//
//
//  Testing Strategy:
//  -put a "Smithy" card in handposition 1 of player's hand
//  -count the cards in the hand, and print the location of Smithy
//  -call cardEffect(Smithy, x, y, z, 0 (position 1), b)
//  -count the cards in the hand, and check if Smithy card is pressent
//  -In order to pass, must be +3 cards, and Smithy card removed from hand (position 1).
//  -TEST WILL FAIL BECAUSE CALL TO DISCARD does not occur
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
    
    printf("Dominion Card Test 2: Smithy\n");
    printf("\n");
    printf("NOTE: test expected to fail due to intentional bug introduced in assignment 2\n");
    printf("\n");
    printf("Testing -> cardEffect(Smithy, x, y, z, 0, b) \n");
    printf("\n");
    printf("Test that player hand + 3 cards - discard after call\n");
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
    
    // overwrite the first card in player 1's hand with the "Smithy" card
    G.hand[0][0] = smithy;
    
    // print hand prior to function call, indicating location of smithy card
    printf("Hand prior to call to cardEffect(Smithy, ...)\n");
    
    int card;
    char *type;
    
    int h;
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(card == smithy)
        {
            type = "smithy";
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    int handsize = G.handCount[0];
    int bonus = 0;
    // call to cardEffect
    int ret = cardEffect(smithy, -1, -1, -1, &G, 0, &bonus);
    
    int handsize2 = G.handCount[0];
    
    int pos1 = 1;
    
    // test 1
    printf("Testing that smithy was discarded from position 1 in hand: \n");
    printf("Printing current hand: \n");
    
    for(h = 0; h < G.handCount[0]; h++)
    {
        card = G.hand[0][h];
        
        if(card == smithy)
        {
            type = "smithy";
            
            if(h == 0)
                pos1 = 0;
        }
        else
            type = "other";
        
        printf("Card %d : ", h + 1);
        printf("%s", type);
        printf("\n");
    }
    
    if(!pos1)
    {
        printf("FAIL\n");
        passflag = 0;
    }
    else
    {
        printf("PASS\n");
    }
    
    printf("\n");
    printf("\n");
    
    // test 2
    printf("Testing that handsize increased by 3 (or 2 total if smithy discarded): \n");
    int diff = handsize2 - handsize;
    
    if(!pos1)
    {
        // if smithy was not removed, expect handsize increase of 3
        if(diff == 3)
            printf("PASS\n");
        else
        {
            printf("FAIL\n");
            passflag = 0;
        }
    }
    else
    {
        // if smithy was removed, expext handsize increase of 2
        if(diff == 2)
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
    printf("Smithy united test completed without crashing\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    return 0;
}
