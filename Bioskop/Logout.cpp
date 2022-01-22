#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include "bioskop.h"

void gotoxyy(int z,int w){
	COORD coord;
	coord.X=z;
		coord.Y=w;
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		
}

void Logout(){
	system("color 8");	
	int r,q;
	gotoxyy(5,6);
	printf("Log outing ...");
	gotoxyy(5,8);
	for(r=1;r<=20;r++){
		for(q=0;q<10000000;q++);
		printf("%c",177);
	}
}
