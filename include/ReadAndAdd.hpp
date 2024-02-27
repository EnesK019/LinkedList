#ifndef READANDADD_HPP
#define READANDADD_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Organizma.hpp" 

class ReadAndAdd
{
	private:
		string fileName;
		Doku **Dokular;		
		int lineCount();
		void readLine();
	public:
		Organizma *organizma;
		ReadAndAdd(string fileName);	
		int size();
		~ReadAndAdd();
};

#endif