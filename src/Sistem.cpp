/**
* @file Sistem.cpp
* @description Organları tutan yapıyı oluşturur
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "Sistem.hpp"

Sistem::Sistem()
{
    this->Organlar = new Organ *[100];
	length = 0;
}

void Sistem::add(Organ *organ)
{	
	Organlar[length] = new Organ();    
	Organlar[length] = organ;
	length++;
}

int Sistem::size()
{
	return length;
}

void Sistem::yaz()
{
	for(int i = 0; i < length; i++)
	{	
		Organlar[i]->yaz();
	}
	cout<<endl;
}

Sistem::~Sistem()
{
    if(Organlar!=0)
	{
		for (int i = 0; i < length; i++)
		{
			if(Organlar[i]!=0) delete Organlar[i];
		}
		delete [] Organlar;
	}
}