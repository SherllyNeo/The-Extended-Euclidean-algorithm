CC=gcc
euclid_alg: euclid_alg.c
	$(CC) euclid_alg.c -o euclid_alg
install:
	cp -f euclid_alg /usr/local/bin
clean:
	$(CC) euclid_alg.c -g -std=gnu11 -o euclid_alg -lm && rm vg*
