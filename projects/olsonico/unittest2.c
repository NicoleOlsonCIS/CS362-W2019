//
//  unittest2.c
//
//  This unit test tests the getCost() function
//  of the dominion.c. Each card has a value.
//  This test determins that the getCost()
//  function returns the correct value based on
//  the card input into the function.
//
//  There are 28 calls made to the getCost()
//  function, testing for 27 card inputs and
//  also that the function returns -1 when the card
//  input is not a valid card.

#include <stdio.h>
#include "../../dominion\dominion.h"
#include "../../dominion\dominion_helpers.h"
#include "../../dominion\rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
    
    int t;
    char* summary = "PASS";
    
    
    printf("Dominion Unit Test 2\n");
    printf("\n");
    printf("Testing of function: getCost()\n");
    printf("\n");
    printf("Test each card input for correct value returned\n");
    printf("\n");
    printf("Commencing test ...\n");
    printf("\n");
    
    printf("\n");
    // CURSE
    printf("Testing curse card: \n");
    t = getCost(curse);
    printf("Card cost is 0, function returns: %d", t);
    printf("\n");
    if(t == 0)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
        
    printf("\n");
    // ESTATE
    printf("Testing estate card: \n");
    t = getCost(estate);
    printf("Card cost is 2, function returns: %d", t);
    printf("\n");
    if(t == 2)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // DUCHY
    printf("Testing duchy card: \n");
    t = getCost(duchy);
    printf("Card cost is 5, function returns: %d", t);
    printf("\n");
    if(t == 5)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // PROVINCE
    printf("Testing province card: \n");
    t = getCost(province);
    printf("Card cost is 8, function returns: %d", t);
    printf("\n");
    if(t == 8)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // COPPER
    printf("Testing copper card: \n");
    t = getCost(copper);
    printf("Card cost is 0, function returns: %d", t);
    printf("\n");
    if(t == 0)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // SILVER
    printf("Testing silver card: \n");
    t = getCost(silver);
    printf("Card cost is 3, function returns: %d", t);
    printf("\n");
    if(t == 3)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // GOLD
    printf("Testing gold card: \n");
    t = getCost(gold);
    printf("Card cost is 6, function returns: %d", t);
    printf("\n");
    if(t == 6)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // ADVENTURER
    printf("Testing adventurer card: \n");
    t = getCost(adventurer);
    printf("Card cost is 6, function returns: %d", t);
    printf("\n");
    if(t == 6)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // COUNCIL_ROOM
    printf("Testing council_room card: \n");
    t = getCost(council_room);
    printf("Card cost is 5, function returns: %d", t);
    printf("\n");
    if(t == 5)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // FEAST
    printf("Testing feast card: \n");
    t = getCost(feast);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // GARDENS
    printf("Testing gardens card: \n");
    t = getCost(gardens);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // MINE
    printf("Testing mine card: \n");
    t = getCost(mine);
    printf("Card cost is 5, function returns: %d", t);
    printf("\n");
    if(t == 5)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // REMODEL
    printf("Testing remodel card: \n");
    t = getCost(remodel);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // SMITHY
    printf("Testing smithy card: \n");
    t = getCost(smithy);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    };
    
    printf("\n");
    // VILLAGE
    printf("Testing village card: \n");
    t = getCost(village);
    printf("Card cost is 3, function returns: %d", t);
    printf("\n");
    if(t == 3)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // BARON
    printf("Testing baron card: \n");
    t = getCost(baron);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // GREAT_HALL
    printf("Testing great_hall card: \n");
    t = getCost(great_hall);
    printf("Card cost is 3, function returns: %d", t);
    printf("\n");
    if(t == 3)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // MINION
    printf("Testing minion card: \n");
    t = getCost(minion);
    printf("Card cost is 5, function returns: %d", t);
    printf("\n");
    if(t == 5)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // STEWARD
    printf("Testing steward card: \n");
    t = getCost(steward);
    printf("Card cost is 3, function returns: %d", t);
    printf("\n");
    if(t == 3)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    };
    
    printf("\n");
    // TRIBUTE
    printf("Testing tribute card: \n");
    t = getCost(tribute);
    printf("Card cost is 5, function returns: %d", t);
    printf("\n");
    if(t == 5)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // AMBASSADOR
    printf("Testing ambassador card: \n");
    t = getCost(ambassador);
    printf("Card cost is 3, function returns: %d", t);
    printf("\n");
    if(t == 3)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // CUTPURSE
    printf("Testing cutpurse card: \n");
    t = getCost(cutpurse);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // EMBARGO
    printf("Testing embargo card: \n");
    t = getCost(embargo);
    printf("Card cost is 2, function returns: %d", t);
    printf("\n");
    if(t == 2)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // OUTPOST
    printf("Testing outpost card: \n");
    t = getCost(outpost);
    printf("Card cost is 5, function returns: %d", t);
    printf("\n");
    if(t == 5)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // SALVAGER
    printf("Testing salvager card: \n");
    t = getCost(salvager);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // SEA_HAG
    printf("Testing sea_hag card: \n");
    t = getCost(sea_hag);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // TREASURE_MAP
    printf("Testing treasure_map card: \n");
    t = getCost(treasure_map);
    printf("Card cost is 4, function returns: %d", t);
    printf("\n");
    if(t == 4)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
        summary = "FAIL";
    }
    
    printf("\n");
    // SMITHY
    printf("Testing INVALID card name input: \n");
    t = getCost("invalidname");
    printf("Function should return -1, function returns: %d", t);
    printf("\n");
    if(t == -1)
        printf("PASS\n");
    else
    {
        printf("FAIL\n");
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
