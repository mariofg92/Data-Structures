all: ordenacion_v1 ordenacion_v2

ordenacion_v1: ordenacion_v1.o
	g++ -o ordenacion_v1 ordenacion_v1.o


ordenacion_v2: ordenacion_v2.o
	g++ -o ordenacion_v2 ordenacion_v2.o

ordenacion_v1.o: ordenacion.cpp priority_queue.h priority_queue_v1.hxx
	g++ -DPQ_V1 -c -o ordenacion_v1.o ordenacion.cpp

ordenacion_v2.o: ordenacion.cpp priority_queue.h priority_queue_v2.hxx
	g++ -DPQ_V2 -c -o ordenacion_v2.o ordenacion.cpp

clean:
	rm *.o ordenacion_v1 ordenacion_v2
