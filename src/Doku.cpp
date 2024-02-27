/**
* @file Doku.cpp
* @description Hücreleri tutan doku yapısı oluşturulur
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "Doku.hpp"

void Doku::reserve(int newCapacity)
{
	Hucre **tmp = new Hucre *[newCapacity];
	for(int index = 0; index < length; index++)
		tmp[index] = Hucreler[index];
	
	delete [] Hucreler;
	Hucreler = tmp;
	capacity = newCapacity;
}

Doku::Doku()
{
	length = 0;
	capacity = 25;
	Hucreler = new Hucre *[capacity];
}

int Doku::size()
{
	return length;
}

bool Doku::isEmpty()
{
	return length == 0;
}

int Doku::elementAt(int i)
{
	if(i < 0 || i >= length) throw "No Such Element";
	return Hucreler[i]->DNA;
}

int Doku::NumberMax()
{
	int max = 0;
	for(int i = 0; i < length; i++)
	{
		if((Hucreler[i]->DNA) > max) max = Hucreler[i]->DNA;
	}
	return max;
}

int Doku::centerNumber()  
{
	return Hucreler[length / 2]->DNA;
} 

void Doku::add(const int& DNA)
{
	Hucreler[length] = new Hucre(DNA);   
	length++;
}

void Doku::yaz()
{
	cout<<"dizi uzunluğu: "<<length<<endl;
	
	for(int i = 0; i < length; i++)
	{
		cout<<Hucreler[i]->DNA<<" ";
	}
}

void Doku::yariyaIndir(int length)
{
	Hucreler[length]->DNA /= 2;
}

void Doku::clear()
{
	if(Hucreler!=0)
	{
		for (int i = 0; i < capacity; i++)
		{
			if(Hucreler[i]!=0) delete Hucreler[i];
		}
	}
}

Doku::~Doku()
{
	clear();
	delete [] Hucreler;
}