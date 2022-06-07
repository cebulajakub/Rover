#ifndef LAZIK_HH
#define LAZIK_HH
#include "ObiektGeom.hh"


class lazik: public ObiektGeom{
    double OdlegloscDoPrzejechania;
    float KatwStopniach;
public:
lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID,double s1,double s2,double s3, double p1, double p2, double p3,float orientacja);
void Przesun_lazik(PzG::LaczeDoGNUPlota &Lacze);
void Obroc_lazik(PzG::LaczeDoGNUPlota &Lacze);
bool mozliwy_lazik();

};
















#endif