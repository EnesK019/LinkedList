/**
* @file main.cpp
* @description Programın çalıştığı kaynak kodlar
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "ReadAndAdd.hpp"
#include <cstdlib>

int main()
{
	ReadAndAdd *readFile = new ReadAndAdd("Veri.txt");
	getchar();
	system("cls");
	readFile->organizma->mutasyonYaz();
	
	return 0;
}