ajamsr2proj4: ajamsr2proj4_1.o ajamsr2proj4_2.o ajamsr2proj4_3.o
	gcc -o ajamsr2proj4 ajamsr2proj4_1.o ajamsr2proj4_2.o ajamsr2proj4_3.o

ajamsr2proj4_1.o: ajamsr2proj4_1.c ajamsr2proj4.h
	gcc -c ajamsr2proj4_1.c

ajamsr2proj4_2.o: ajamsr2proj4_2.c ajamsr2proj4.h
	gcc -c ajamsr2proj4_2.c

ajamsr2proj4_3.o: ajamsr2proj4_3.c ajamsr2proj4.h
	gcc -c ajamsr2proj4_3.c

clean:
	rm ajamsr2proj4_1.o ajamsr2proj4_2.o ajamsr2proj4_3.o ajamsr2proj4