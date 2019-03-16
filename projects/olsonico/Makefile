rngs.o:
	gcc -c ../../dominion/rngs.c -g -o ../../dominion/rngs.o -Wall -fpic -coverage -lm -std=c99

dominion.o: rngs.o
	gcc -c ../../dominion/dominion.c -g -o ../../dominion/dominion.o -Wall -fpic -coverage -lm -std=c99

unittestresults_assignment_3: dominion.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest1 -g unittest1.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest2 -g unittest2.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest3 -g unittest3.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o unittest4 -g unittest4.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest1 -g cardtest1.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest2 -g cardtest2.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest3 -g cardtest3.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o cardtest4 -g cardtest4.c ../../dominion/dominion.o ../../dominion/rngs.o
	./unittest1 &> unittestresult_assignment_3.out
	./unittest2 >> unittestresult_assignment_3.out
	./unittest3 >> unittestresult_assignment_3.out
	./unittest4 >> unittestresult_assignment_3.out
	./cardtest1 >> unittestresult_assignment_3.out
	./cardtest2 >> unittestresult_assignment_3.out
	./cardtest3 >> unittestresult_assignment_3.out
	./cardtest4 >> unittestresult_assignment_3.out
	gcov -b ../../dominion/dominion.c >> unittestresult_assignment_3.out
	cat dominion.c.gcov >> unittestresult_assignment_3.out

unittestresults: dominion.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o randomtest1 -g randomtest1.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o randomtest2 -g randomtest2.c ../../dominion/dominion.o ../../dominion/rngs.o
	gcc -fprofile-arcs -ftest-coverage -Wall -lm -std=c99 -o randomtestadventurer -g randomtestadventurer.c ../../dominion/dominion.o ../../dominion/rngs.o
	./randomtest1 &> unittestresult.out
	./randomtest2 >> unittestresult.out
	./randomtestadventurer >> unittestresult.out
	gcov -b ../../dominion/dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

clean:
	rm *.o
	rm *.g*
	rm *.out
	rm ../../dominion/*.o
	rm ../../dominion/*.g*