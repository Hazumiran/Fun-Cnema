#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "bioskop.h"


FILE *file;

int usernamebenar,passwordbenar,i = 0;
char pass[20], password[20],user[20],username[20],ch;

void ambil();
void selesai();
void login();

void getLogin(){
	login();
	
}

void login(){
	system("color 7");	
	ambil();
	printf("\n\n\n\n\t\t\t--------------------------\n");
	printf("\t\t\t| Aplikasi FunCinema |\n");
	printf("\t\t\t--------------------------\n\n");
	printf("\t\t\t Menu Login\n");
	printf("\t\t\t Username : ");
	scanf("%s", &user);
	printf("\t\t\t Password : ");
	
scanf("%s", &pass);	
		
	usernamebenar=strcmp(user,username);
	passwordbenar=strcmp(pass,password);
	if(usernamebenar !=0){
		
		printf("\nusername/password yang anda masukkan salah!");
		getch();
		system("cls");
		login();
	}else if(passwordbenar !=0){
		
		printf("\nusername/password yang anda masukkan salah!");
		getch();
		system("cls");
		login();
	
	}
	else{
		selesai(); //void selesai dapat kalian ubah ke void menu
	}
}



void ambil(){
	FILE *file;
	file=fopen("password.txt", "r");
	fscanf(file, "%s %s", username,password);
	fclose(file);
}

void selesai(){
	
	printf("\n\n\n\t\t\t Login Sukses, Selamat datang %s",username);
	getLoading();
	system("cls");
	system("color 7");
	printf("=========================================================================\n");
		printf("\t\t\t FunCinema \n");
		printf("=========================================================================\n\n");
		menu();
		
	
}
