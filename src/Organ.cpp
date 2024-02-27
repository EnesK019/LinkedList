/**
* @file Organ.cpp
* @description dokuların bulunduğu ağaçları tutan organ yapısı oluşturulur
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"

Organ::Organ()
{
    this->BTS = new BinarySearchTree();
    dokuIndex = 0;
    length = 0;
}

void Organ::Add(Doku* doku)
{
    if(length<20)
        BTS->Add(doku);
    
    length++;
}

int Organ::size()
{
    return length;
}

bool Organ::dengeKontrol()
{
    return BTS->isBalanced(BTS->rootbul());
}

void Organ::yaz()
{   
    if(dengeKontrol()) cout<<" ";
    else cout<<"#";
}

Organ::~Organ()
{
    delete BTS;
}