#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "bioskop.h"


Tampil_Lihat(){		
  Nonton dt;
  Show sh;
 int voice;
 char jawab;
 int i=0;

 FILE *Tickets=fopen("Report.txt", "r");
 	if (!Tickets)
 	{
 	printf ("File tidak dapat dibuka\n");
 	printf("kembali ke menu utama ? ");
	scanf("%s", &jawab);
		if(jawab == 'y'|jawab == 'Y'){
			menu();
		}else{
			return 0;
		}

 }
 	printf("-------------------------\n");
 	printf("|\tBioskop Keren\t\t|\n");
 	printf("-------------------------\n");
 	printf("| Film\t \t | Tanggal\t | Jam\t | Row\t | Seat\t | \n\n");
	 	fscanf(Tickets,"%s", sh.jud[sh.film]);
	 		printf("%s %s\n", sh.jud[sh.film]);
			  
 fclose(Tickets);
 printf("Kembali ke menu ? (Y/N)");
 scanf("%s",&voice);
 		if(voice=='y'|voice=='Y'){
				system("cls");
				menu();
			}else{
			exit(1);
	 }
}



 
