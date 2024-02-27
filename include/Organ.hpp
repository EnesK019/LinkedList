#ifndef ORGAN_HPP
#define ORGAN_HPP

#include "BinarySearchTree.hpp"

class Organ
{
	public:
		int dokuIndex;
		int length;
		BinarySearchTree *BTS;

		Organ();
		int size();
		void Add(Doku *doku);	
		bool dengeKontrol();
		void yaz();	
		~Organ();
};

#endif