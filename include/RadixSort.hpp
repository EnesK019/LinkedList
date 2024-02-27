#ifndef RADIXSORT_HPP
#define RADIXSORT_HPP

#include "Doku.hpp"
#include "Queue.hpp"
#include <cmath>

class RadixSort{
	private:	
		Doku* numbers;
		int length;
		Queue **queues;
		int maxStep;
		
		int MaxStepNumber();
		int power(int);
		int StepCount(int);
		int* QueueCurrentLengths();
	public:
		RadixSort(Doku* numbers, int length);
		Doku* Sort();
		~RadixSort();
};

#endif