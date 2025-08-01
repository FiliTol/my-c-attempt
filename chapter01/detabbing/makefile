detab: src/detab.c src/detab_core.c
	gcc -o detab src/detab.c src/detab_core.c

test: tests/test_detab.c src/detab_core.c
	gcc -o test_detab tests/test_detab.c src/detab_core.c
	./test_detab

clean:
	rm -f detab test_detab

