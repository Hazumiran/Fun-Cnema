#ifndef bioskop_H
#define bioskop_H


struct Nonton {	
	int tiket;	
	float kembalian2,bayar,totalharga,hargatiket=25.000; 
	char cetak,pesan,nonton,menu,kursi;
	} ;

	
struct Show{		
	char jud[5][50]={"Error","SEPIDERMAN","BOLANG","FROZEN 2","MY WAR"};
	int film;
	int day, month, year;
	float jamx[7]={ 0,11.30, 12.55, 14.20, 16.10, 19.10, 20.45};
	int jam; 
	char hurufkursi[20][50]; 
	int angkakursi[50];
	float jamy[7]={0,11.45,13.00,15.30,17.20,19.15,21.00};	
};


void DaftarFilm();
int getBioskop();
int main();
int Delete();
int Tampil_Lihat();
void getLogin();
void getLoading();
void menu();
void Logout();



#endif
