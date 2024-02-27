/**
* @file Control.cpp
* @description Organizmanın mutasyona uğrayıp uğramadığı kontrol edilir
* @course 2.Öğretim A grubu
* @assignment 2. Ödev
* @date 09.12.2022
* @author Enes Kartancı enes.kartanci@ogr.sakarya.edu.tr
*/

#include "Control.hpp"

Control::Control() {}

void Control::mutasyonlu(BinarySearchTree *&bts)
{
    bts = bts->mutasyonlumu(bts->rootbul());   
}

Control::~Control() {}