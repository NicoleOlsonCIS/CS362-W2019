//
//  unittest1.c
//  unittest1_dominion
//
//  This unit test tests the "isGameOver()" function.
//  If the stack of Province cards is empty, the game must end.
//  If three supply piles are at 0, the game must end.
//  Otherwise, if there are province cards and no 3 piles are empty, game must continue
//
//  3 Tests:
//
//  1. Test that game does not end when #of supply piles that are zero is < 3
//     - Province pile must not be zero in order to test the 3 pile exit from function
//     - Strategy: set all pile values to 1
//     - NOTE: passing this test also verifies that when province is not zero, game will not end. Failing
//             this test however does not indicate that province != 0 exit has failed.
//
//  2. Test that game does end when there are 3 supply piles that are empty
//     - Province pile must not be zero in order to test the 3 pile exit from function
//     - Stategy: set all pile values to 1 except duchy, estate and curse.
//
//  3. Test that game does end when province pile is zero
//     - Strategy: set province pile to zero (given ordering in function, doesn't matter what other cards are)
//
//  4. Test that province pile != 0 does not end the game (when no 3 piles are zero)
//     - Stategy: set all piles to 1

#include <stdio.h>
#include "../../dominion/dominion.h"
#include "../../dominion/dominion_helpers.h"
#include "../../dominion/rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char** argv)
{
    int t;
    int failFlag = 0;
    
    printf("Dominion Unit Test 1\n");
    printf("\n");
    printf("Testing of function: isGameOver()\n");
    printf("\n");
    
    // PART 1: Test that game does not end when there are < 3 supply piles = zero
    printf("\n");
    printf("Part 1: Test that game DOES NOT end when < 3 supply piles with zero. \n");
    printf("Commencing test ... \n");
    printf("\n");
    
    struct gameState G;                         // create a gameState struct
    int j;
    for(j = 0; j < 25; j++)
    {
        G.supplyCount[j] = 1;                  // set all supply of cards to 1
    }
    
    t = isGameOver(&G);
    
    if(t == 0)
    {
        printf("Test 1 PASSED: gameState DOES NOT return 'end' when < 3 supply piles are zero. \n");
        printf("\n");
    }
    else
    {
        printf("Test 1 FAILED: gameState returns 'end' when there are < 3 supply piles at zero.\n");
        printf("\n");
        failFlag = 1;
    }
    
    // PART 2: Test that game ends when there are 3 supply piles = zero
    printf("\n");
    printf("Part 2: Test that game DOES END when (exactly) 3 supply piles are zero. \n");
    printf("Commencing test ... \n");
    printf("\n");
    
    // set three supply cards to 0
    G.supplyCount[curse] = 0;
    G.supplyCount[estate] = 0;
    G.supplyCount[duchy] = 0;
    
    t = isGameOver(&G);
    
    if(t == 1)
    {
        printf("Test 2 PASSED: gameState returns 'end' when 3 supply piles are zero. \n");
        printf("\n");
    }
    else
    {
        printf("Test 2 FAILED: gameState does not return 'end' when there are 3 supply piles at zero.\n");
        printf("\n");
        failFlag = 1;
    }
    
    // PART 3: Test that game ends when there are zero province cards
    printf("\n");
    printf("Part 3: Test that game DOES END when there are ZERO PROVINCE CARDS. \n");
    printf("Commencing test ... \n");
    printf("\n");
    
    for(j = 0; j < 25; j++)
    {
        G.supplyCount[j] = 1;                                      // set all supply of cards to 1
    }
    
    G.supplyCount[province] = 0;                                   // set province cards to zero
    
    t = isGameOver(&G);
    
    if(t == 1)
    {
        printf("Test 3 PASSED: gameState returns 'end' when there are zero province cards. \n");
        printf("\n");
    }
    else
    {
        printf("Test 3 FAILED: gameState does not return 'end' when there are zero province cards.\n");
        printf("\n");
        failFlag = 0;

    }
    
    // PART 4: Test that game DOES NOT END when there are province cards > 0
    printf("\n");
    printf("Part 4: Test that game DOES NOT END when PROVINCE CARDS > 0. \n");
    printf("Commencing test ... \n");
    printf("\n");
    
    for(j = 0; j < 25; j++)
    {
        G.supplyCount[j] = 1;
    }
    
    t = isGameOver(&G);
    
    if(t == 0)
    {
        printf("Test 4 PASSED: gameState does not return 'end' when there >0 province cards. \n");
        printf("\n");
    }
    else
    {
        printf("Test 4 FAILED: gameState does not return 'end' when there are >0 province cards.\n");
        printf("\n");
        failFlag = 0;
    }

    char* summary;

    if (failFlag)
        summary = "FAIL";
    else
        summary = "PASS";


    printf("\n");
    printf("\n");
    printf("UNIT TEST SUMMAARY (must pass all tests for summary of PASS): %s", summary);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    return 0;
}
