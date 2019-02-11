rngs.o: rngs.h rngs.c
	gcc -c ../../dominion/rngs.c -g  -Wall -fpic -coverage -lm

dominion.o: dominion.h dominion.c rngs.o
	gcc -c ../../dominion/dominion.c -g  -Wall -fpic -coverage -lm

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest1 -g unittest1.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest2 -g unittest2.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest3 -g unittest3.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest4 -g unittest4.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest1 -g cardtest1.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest2 -g cardtest2.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest3 -g cardtest3.c dominion.o rngs.o
    gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest4 -g cardtest4.c dominion.o rngs.o
    ./unittest1 &> unittestresult.out
    ./unittest2 >> unittestresult.out
    ./unittest3 >> unittestresult.out
    ./unittest4 >> unittestresult.out
    ./cardtest1 >> unittestresult.out
    ./cardtest2 >> unittestresult.out
    ./cardtest3 >> unittestresult.out
    ./cardtest4 >> unittestresult.out
    gcov -b dominion.c >> unittestresult.out
    cat dominion.c.gcov >> unittestresult.out