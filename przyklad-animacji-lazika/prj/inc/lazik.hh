#ifndef LAZIK_HH
#define LAZIK_HH
#include "ObiektGeom.hh"
#include <memory>


class lazik: public ObiektGeom{
    double OdlegloscDoPrzejechania;
    float KatwStopniach;
public:
lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID,double s1,double s2,double s3, double p1, double p2, double p3,float orientacja);
bool Przesun_lazik(PzG::LaczeDoGNUPlota &Lacze,std::list<std::shared_ptr<ObiektGeom>> Wszystkie_Obiekty);
void Obroc_lazik(PzG::LaczeDoGNUPlota &Lacze);
bool mozliwy_lazik() override;
bool Kolizja(std::list<std::shared_ptr<ObiektGeom>> Wszystkie_Obiekty);
bool Przelicz_i_Zapisz_Wierzcholki() override;

};
















#endif