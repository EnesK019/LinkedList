/**
* @file ReadAndAdd.cpp
* @description Dosyadaki verileri okuyup birbirleriyle ilişki kurarak organizmanın oluşmasını sağlayan yapı oluşturulur
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "ReadAndAdd.hpp"

ReadAndAdd::ReadAndAdd(string fileName)
{
	this->fileName = fileName;
	
	int linenumber = lineCount();
	this->Dokular = new Doku* [linenumber];
	for(int i = 0; i < linenumber; i++)
	{
		this->Dokular[i] = new Doku();
	}
	readLine();
}

int ReadAndAdd::size()
{
	int length = lineCount();
	return length;
}

int ReadAndAdd::lineCount()
{
	int count = 0;
	ifstream file(this->fileName);
	string endline;
	while(getline(file,endline))
		count++;
		
	file.close();	
	return count;
}

void ReadAndAdd::readLine()
{
	ifstream file(this->fileName);
	string satir;
	int numbers;
	int index = 0;
	
	while(getline(file,satir))
	{
		stringstream ss;
		ss<<satir;
		while(ss>>numbers)
		{
			this->Dokular[index]->add(numbers);
		}
		
		RadixSort *sortDoku = new RadixSort(Dokular[index], Dokular[index]->size());	
		Dokular[index] = sortDoku->Sort();
		delete sortDoku;	
		index++;
	}
	file.close();
	
	int countLine = lineCount();
	int organIndex = countLine/20;
	if(countLine % 20 != 0) organIndex++;
	int OrganCount = 0;
	Organ **Organlar = new Organ *[organIndex];
	for(int i = 0; i < countLine;)
	{	
	 	Organlar[OrganCount] = new Organ();
	 	for(int j = 0; j < 20; j++)
	 	{
	 		Organlar[OrganCount]->BTS->Add(Dokular[i]);
	 		i++;
	 	} 
	 	OrganCount++;
	}
	
	int sistemIndex = organIndex / 100;
	if(organIndex % 100 != 0) sistemIndex++;
	int sistemCount = 0;
	OrganCount = 0;
	Sistem **sistemler = new Sistem *[sistemIndex];
	while(sistemCount < sistemIndex)
	{
		sistemler[sistemCount] = new Sistem();
		for(int index = 0; index < 100; index++)
		{
			sistemler[sistemCount]->add(Organlar[OrganCount]); 
			OrganCount++;
		}		
		sistemCount++;
	}

	sistemCount = 0;
	organizma = new Organizma(sistemIndex);
	while(sistemCount < sistemIndex)
	{
		organizma->Add(sistemler[sistemCount]);
		sistemCount++;
	}

	organizma->yaz();
}

ReadAndAdd::~ReadAndAdd()
{
	if(Dokular!=0)
	{
		int count =lineCount();
		for (int i = 0; i < count; i++)
		{
			if(Dokular[i]!=0) delete Dokular[i];
		}
		delete[] Dokular;
	}
	delete organizma;
}