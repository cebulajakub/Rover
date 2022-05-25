#ifndef LAZIK_HH
#define LAZIK_HH
#include "ObiektGeom.hh"

class lazik: public ObiektGeom{
    double OdlegloscDoPrzejechania;
    double Orientacja;
public:
void Przesun_lazik();
void Obroc_lazik();

};
















#endif