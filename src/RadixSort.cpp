/**
* @file RadixSort.cpp
* @description Dokuları sıralayan RadixSort yapısı oluşturulur
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "RadixSort.hpp"

int RadixSort::MaxStepNumber()
{
	int max = 0;
	max = StepCount(numbers->NumberMax());	
	return max;
}

int RadixSort::StepCount(int number)
{
	number = abs(number);
	int basamak = 0;
	while(number > 0)
    {
		basamak++;
		number /= 10;
	}
	return basamak;
}

RadixSort::RadixSort(Doku *numbers, int length)
{	
	this->numbers =numbers;
	this->length = length;
	queues = new Queue*[10];
	for(int j = 0; j < 10; j++)   { queues[j] = new Queue(); }
	maxStep = MaxStepNumber();
}

int* RadixSort::QueueCurrentLengths()
{
	int *lengths = new int[10];
	for(int i=0;i<10;i++){
		lengths[i] = queues[i]->count();
	}
	return lengths;
}

int RadixSort::power(int e)
{
	int result = 1;
	for(int i = 0; i  < e; i++) result *= 10;
	return result;
}

Doku* RadixSort::Sort()
{
	int numberIndex=0;
	for(;numberIndex<length;numberIndex++)
    {
		int stepValue = numbers->elementAt(numberIndex)%10;
		int num = numbers->elementAt(numberIndex);
		queues[stepValue]->enqueue(num);
	}
		
	for(int i = 1; i < maxStep; i++)
    {
		int *qlengths = QueueCurrentLengths();
		for(int index = 0; index < 10; index++)
        {
			int len = qlengths[index];
			for(; len > 0; len--)
            {
				int number = queues[index]->peek();
				queues[index]->dequeue();
				int stepValue = (number/power(i))%10;	
				queues[stepValue]->enqueue(number);				
			}
		}
		delete [] qlengths;
	}
	Doku* ordered = new Doku();
	numberIndex=0;
	for(int index = 0; index < 10; index++)
    {
		while(!queues[index]->isEmpty())
        {
			int number = queues[index]->peek();
			ordered->add(number);
			queues[index]->dequeue();
		}
	}		
	return ordered;
}
RadixSort::~RadixSort()
{	
	for(int i = 0; i < 10; i++) delete queues[i];
	delete [] queues;
}