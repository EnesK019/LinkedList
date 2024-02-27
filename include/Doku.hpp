#ifndef DOKU_HPP
#define DOKU_HPP

#include "Hucre.hpp"

class Doku
{
	private:
			Hucre **Hucreler;
			int length;
			int capacity;
			void reserve(int newCapacity);
	public:	
			Doku();
			bool isEmpty();
			int size();
			int elementAt(int i);
			int NumberMax();
			int centerNumber();
			void add(const int& DNA);
			void yaz();
			void yariyaIndir(int length);
			void clear();
			~Doku();
};

#endif