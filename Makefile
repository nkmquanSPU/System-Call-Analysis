all:
	gcc -o measure_0-byte measure_0-byte.c
	gcc -o measure_1-byte measure_1-byte.c
clean:
	rm -rf measure_0-byte measure_1-byte
