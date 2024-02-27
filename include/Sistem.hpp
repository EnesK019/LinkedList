#ifndef SISTEM_HPP
#define SISTEM_HPP

#include "Organ.hpp"

class Sistem
{
    private:        
        int length;

    public:
        Organ **Organlar;
        
        Sistem();
        void add(Organ *organ);
        void yaz();
        int size();
        ~Sistem();
};

#endif