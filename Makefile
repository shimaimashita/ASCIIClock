ASCIIClock: ASCIIClock.c ASCIIFun.o
	gcc -Wall -g $^ -lm -o $@ 

ASCIIFun.o: ASCIIFun.c
	gcc -Wall -g $^ -lm -c -o $@

clean:
	rm *.o
	rm ASCIIClock

