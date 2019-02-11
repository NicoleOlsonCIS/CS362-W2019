rngs.o:
	gcc -c ../../dominion/rngs.c -o ./rngs.o -g -Wall -fpic -coverage -lm -std=c99

dominion.o: rngs.o
	gcc -c ../../dominion/dominion.c -o ./dominion.o -g -Wall -fpic -coverage -lm -std=c99

unittestresults: dominion.o
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
	gcov -b ../../domionion/dominion.c >> unittestresult.out
	copy ../../*.gcov ./
	cat dominion.c.gcov >> unittestresult.out

clean:
	rm *.o
	rm *.g*
	rm ../../dominion/*.o
	rm ../../dominion/*.g*
	rm *.out