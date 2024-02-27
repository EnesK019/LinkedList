#ifndef ORGANIZMA_HPP
#define ORGANIZMA_HPP

#include "Sistem.hpp"
#include "Control.hpp"

class Organizma
{
    private:       
        Control *controller;
        int length;
    public:
        Sistem **sistemler;
        Organizma(int sistemsayisi);
        void Add(Sistem *sistem);
        void yaz();
        void mutasyonYaz();
        int size();
        ~Organizma();

};
#endif