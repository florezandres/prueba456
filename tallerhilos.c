#include <unistd.h> 
#include <pthread.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <iostream>
#include <string>

#define MAXLON 1000

void *cuenta (void *x) { 
int pos, cont= 0, leidos; 
char cadena[MAXLON]; 
char *nombre= (char*) x;
int fd; 

fd= open (nombre, O_RDONLY); 
while ((leidos= read (fd, cadena, MAXLON))!= 0) 
	for (pos= 0; pos< leidos; pos++) 
		if ((cadena[pos]== 'a') || (cadena[pos]== 'A')) 
		cont++; 
	printf ("Fichero %s:%d caracteres 'a' o 'A' encontrados\n", nombre, cont); 
	close (fd); 
	pthread_t exit(NULL);
} 
int main (int argc, char *argv[]) { 

pthread_t hilo;

if (argc!= 2) { 
printf ("Indica el nombre de un fichero.\n"); 
exit(0); 
}

pthread_create(&hilo, NULL, cuenta, (void*)argv[1]); 
pthread_join (hilo, NULL);
//cuenta (argv[1]); 
return 0; 
} 
