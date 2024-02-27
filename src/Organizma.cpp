/**
* @file Organizma.cpp
* @description Sistemleri tutan organizma yapısı oluşturulur
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "Organizma.hpp"

Organizma::Organizma(int sistemsayisi)
{
    sistemler = new Sistem *[sistemsayisi];
    length = 0;
}

void Organizma::Add(Sistem *sistem)
{
	sistemler[length] = new Sistem();
    sistemler[length] = sistem;
    length++;
}

int Organizma::size()
{
	return length;
}

void Organizma::yaz()
{
	for(int i = 0; i < length; i++)
	{
        sistemler[i]->yaz();
	}	
}


void Organizma::mutasyonYaz()
{
	controller = new Control();
	for(int i = 0; i < length; i++)
	{
		for(int j = 0; j < sistemler[i]->size(); j++)
		{
			controller->mutasyonlu(sistemler[i]->Organlar[j]->BTS);
		}			
	}
	yaz();
}

Organizma::~Organizma()
{
    if(sistemler!=0)
	{
		for (int i = 0; i < length; i++)
		{
			if(sistemler[i]!=0) delete sistemler[i];
		}
		delete[] sistemler;
	}
	delete controller;
}