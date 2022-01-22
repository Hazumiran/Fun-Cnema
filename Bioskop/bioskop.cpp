#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include "bioskop.h"

 
int getBioskop(){
FILE *Tickets;
	Nonton dt;
	Show sh;

time_t now;
    time(&now);

 struct tm *local = localtime(&now);
 
    sh.day = local->tm_mday;           
    sh.month = local->tm_mon + 1;      
    sh.year = local->tm_year + 1900;   

 for (;;){
 
	kembali:
		DaftarFilm();
	
	
		
		
//pilihan film]
		filminput:
		fflush(stdin);
		printf("Pilih Film(1-4) : ");
		//VALIDASI HANYA ANGKA
				int status,temp;
				status = scanf("%d",&sh.film);
				while(status!=1){
					while((temp=getchar()) != EOF && temp != '\n');
					printf("Invalid input.. Masukkan angka: ");
					status = scanf("%d",&sh.film);
				}
				if(4<sh.film ||sh.film<1){
				printf("Invalid..! Hanya tersedia 4 list film \n");
				goto filminput;
			}
			
			
			
//pilihan jam tayang
		jaminput:
		fflush(stdin);
		printf("Pilih Jam ke(1-6) : ");
		//VALIDASI HANYA ANGKA
				int status1,temp1;
				status1 = scanf("%d",&sh.jam);
				while(status1!=1){
					while((temp1=getchar()) != EOF && temp1 != '\n');
					printf("Invalid input.. Masukkan angka: ");
					status1 = scanf("%d",&sh.jam);
				}
			if(6<sh.jam||sh.jam<1){
				printf("Masukkan pilihan yang valid\n");
				goto jaminput;
			}
			
			
		
//tampilkan film dan jam tayang yang dipilih
		printf("Film %s\n",sh.jud[sh.film]);			
			if(sh.film==1|sh.film==4){
				printf("Jam %.2f\n",sh.jamx[sh.jam]);
			}
			else if(sh.film==2|sh.film==3){
				printf("Jam %.2f\n",sh.jamy[sh.jam]);
			}
			
			
			
//pilihan jumlah tiket
		fflush(stdin);
		printf("Jumlah tiket yang akan dibeli : ");
		//VALIDASI HANYA ANGKA
				int status2,temp2;
				status2 = scanf("%d",&dt.tiket);
				while(status2!=1){
					while((temp2=getchar()) != EOF && temp2 != '\n');
					printf("Invalid input.. Masukkan angka: ");
					status2 = scanf("%d",&dt.tiket);
				}
				
				
				
//pilihan tempat duduk
		kursi:
		int h;
			for(h=0;h<dt.tiket;h++){
				fflush(stdin);
				printf("Pilih seat(A-J) : ");
				scanf("%s",&sh.hurufkursi[h]);				
				printf("Pilih Nomor Kursi(1-50) : ");
			//VALIDASI HANYA ANGKA
					int status3,temp3;
					status3 = scanf("%d",&sh.angkakursi[h]);
					while(status3!=1){
						while((temp3=getchar()) != EOF && temp3 != '\n');
						printf("Invalid input.. Masukkan angka: ");
						status3 = scanf("%d",&sh.angkakursi[h]);
					}				
						if(50<sh.angkakursi[h]||sh.angkakursi[h]<1){
						printf("Pilihan tidak valid, silahkan Ulangi ! \n\n");
						goto kursi;
				}
				
					
			}
			
			
//Tampilan Checkout			
		inptiket:	
		int i;
		fflush(stdin);
		printf("Jumlah Pesanan : %d\n",dt.tiket);
		printf("-----------------------------------------\n");
		printf("| No |\tFilm\t| Kursi | Harga |\n");
		printf("-----------------------------------------\n");
			for(i=0;i<dt.tiket;i++){
				printf("|   %d  |%s\t|  %s%d  | %.3f |\n",i+1,sh.jud[sh.film],sh.hurufkursi[i],sh.angkakursi[i],dt.hargatiket,dt.tiket);			
			}
		printf("-----------------------------------------\n");
		dt.totalharga=dt.hargatiket*dt.tiket;
		 



//Transaksi pembayaran		
		balik:
		fflush(stdin);
		printf("Total harga\t\tRp %.3f\n",dt.totalharga);
		printf("Bayar\t\t\tRp. ");
			//VALIDASI HANYA ANGKA
				int status4,temp4;
				status4 = scanf("%f",&dt.bayar);
				while(status4!=1){
					while((temp4=getchar()) != EOF && temp4 != '\n');
					printf("Invalid input.. Masukkan biaya: ");
					status4 = scanf("%f",&dt.bayar);
				}
			
		if(dt.bayar<dt.totalharga){
			printf("Uang gak cukup, yakin mau jadi nonton ? (Y/N)\n\n");
			scanf("%s",&dt.nonton);
				if(dt.nonton=='Y'|dt.nonton=='y'){
					goto balik;		
				}
				else{
					printf("Good Bye :) ");
					return 0;
				}											
		}
		else{
			dt.kembalian2=dt.bayar-dt.totalharga;
		}
		
		printf("\t\t\t__\n\n");
		printf("Kembalian\t\tRp %.3f\n",dt.kembalian2);
		
		
		
		printf("Cetak tiket (Y/N) ? ");
		scanf("%s",&dt.cetak);
		system("cls");
			if(dt.cetak=='y'|dt.cetak=='Y'){
				Tickets=fopen("Report.txt", "a+");
				for(i=0;i<dt.tiket;i++){
					printf("------------------------------------\n");
					printf("|\tFunCinema\t\t|\n");
					printf("------------------------------------\n");
					printf("| %s\t\t\t|\n",sh.jud[sh.film]);
					printf("|Tanggal : %d-%d-%d \t\t|\n", sh.day,sh.month,sh.year);
						if(sh.film==1|sh.film==4){
							printf("|Time : %.2f\t\t\t|\n",sh.jamx[sh.jam]);
						}
						else if(sh.film==2|sh.film==3){
							printf("|Time : %.2f\t\t\t|\n",sh.jamy[sh.jam]);
						}		
					printf("|Row  : %s Seat : %d \t\t|\n",sh.hurufkursi,sh.angkakursi[i]);
//					printf("harga")
					printf("------------------------------------\n\n");
					if(sh.film==1|sh.film==4){
							fprintf(Tickets,"%s %02d/%02d/%02d %.2f %s  %d \n ",sh.jud[sh.film],sh.day,sh.month,sh.year,sh.jamx[sh.jam],sh.hurufkursi[i],sh.angkakursi[i]);
						}
						else if(sh.film==2|sh.film==3){
							fprintf(Tickets,"%s %02d/%02d/%02d %.2f %s  %d \n ",sh.jud[sh.film],sh.day,sh.month,sh.year,sh.jamy[sh.jam],sh.hurufkursi[i],sh.angkakursi[i]);
						}
					


				} fclose(Tickets);
				
				buyagain:
				printf("Ingin membeli tiket lagi (Y/N) ?");
				
				scanf("%s",&dt.pesan);
					if(dt.pesan=='y'|dt.pesan=='Y'){
						goto kembali;
					}
					else if(dt.pesan=='n'|dt.pesan=='N'){
						goto selesai;
					}else{
						printf("Masukkan Pilihan yang valid");
						goto buyagain;
					}
			}exit(1);

	selesai:
		system("cls");
		printf("Terimakasih telah membeli tiket bioskop kami\n Selamat Menonton :)\n\n ");
		printf("Kembali Ke Menu Utama ? ");
		scanf("%s",&dt.menu);
			if(dt.menu=='y'|dt.menu=='Y'){
				system("cls");
				menu();
//				Tampil_Lihat();
			}else{
			exit(1);}
		}
		
}
