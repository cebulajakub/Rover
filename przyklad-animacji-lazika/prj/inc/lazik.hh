#ifndef LAZIK_HH
#define LAZIK_HH
#include "ObiektGeom.hh"

class lazik: public ObiektGeom{
    double OdlegloscDoPrzejechania;
    double Orientacja;
    double KatwStopniach;
public:
void Przesun_lazik();
void Obroc_lazik(const Wektor<double> &)const;

};
















#endif