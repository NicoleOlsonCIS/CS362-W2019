CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc  -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc  -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc  -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc  -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc  -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc  -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc  -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc  -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtest1: randomtest1.c dominion.o rngs.o
	gcc  -o randomtest1 -g  randomtest1.c dominion.o rngs.o $(CFLAGS)

randomtest2: randomtest2.c dominion.o rngs.o
	gcc  -o randomtest2 -g  randomtest2.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc  -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtest1 randomtest2 randomtestadventurer
	./unittest1 &> unittestresult.out
	./unittest2 &>> unittestresult.out
	./unittest3 &>> unittestresult.out
	./unittest4 &>> unittestresult.out
	./cardtest1 &>> unittestresult.out
	./cardtest2 &>> unittestresult.out
	./cardtest3 &>> unittestresult.out
	./cardtest4 &>> unittestresult.out
	./randomtest1 &>> unittestresult.out
	./randomtest2 &>> unittestresult.out
	./randomtestadventurer &>> unittestresult.out

codecoverageass5: dominion.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest1 -g unittest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest2 -g unittest2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest3 -g unittest3.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest4 -g unittest4.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest1 -g cardtest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest2 -g cardtest2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest3 -g cardtest3.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest4 -g cardtest4.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o randomtest1 -g randomtest1.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o randomtest2 -g randomtest2.c dominion.o rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o
	./unittest1 &> codecoverageass5.out
	./unittest2 >> codecoverageass5.out
	./unittest3 >> codecoverageass5.out
	./unittest4 >> codecoverageass5.out
	./cardtest1 >> codecoverageass5.out
	./cardtest2 >> codecoverageass5.out
	./cardtest3 >> codecoverageass5.out
	./cardtest4 >> codecoverageass5.out
	./randomtest1 >> codecoverageass5.out
	./randomtest2 >> codecoverageass5.out
	./randomtestadventurer >> codecoverageass5.out
	gcov -b dominion.c >> codecoverageass5.out
	cat dominion.c.gcov >> codecoverageass5.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out unittest1 unittest1.exe
