#include <stdio.h>
#include <time.h>
#include "bioskop.h"

void DaftarFilm(){
	FILE *Tickets;
	Nonton dt;
	Show sh;
			
 time_t now;
    time(&now);

 struct tm *local = localtime(&now);
 
    sh.day = local->tm_mday;           
    sh.month = local->tm_mon + 1;      
    sh.year = local->tm_year + 1900;   
    
printf("=========================================================================\n");
		printf("\t\t\t FunCinema \n");
		printf("=========================================================================\n\n");
		printf("\t\t\t DAFTAR FILM\n");
		printf("-------------------------------------------------------------------------\n");
		printf(" |\t  |\t\t|\t\t\tJam\t\t\t|\n");
		printf(" | Studio |    Film\t|------------------------------------------------\n");
		printf(" |\t  | \t\t|   1   |   2   |   3   |   4   |   5   |   6   |\n");
		printf(" |----------------------|------------------------------------------------\n");
		printf(" |   1   | Sepiderman\t| 11.30 | 12.55 | 14.20 | 16.10 | 19.10 | 20.45 |\n");
		printf(" |   2   | BOLANG\t| 11.45 | 13.00 | 15.30 | 17.20 | 19.15 | 21.00 |\n");
		printf(" |   3   | Frozen 2\t| 11.45 | 13.00 | 15.30 | 17.20 | 19.15 | 21.00 |\n");
		printf(" |   4   | My War\t| 11.30 | 12.55 | 14.20 | 16.10 | 19.10 | 20.45 |\n");
		printf(" |----------------------|------------------------------------------------\n\n");
		printf("=========================================================================\n");
		printf("Harga Tiket : Rp. %.3f\n", dt.hargatiket);		
		 printf("Today is %s\n\n", ctime(&now));
	
}
