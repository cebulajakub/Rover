#ifndef SCENA_HH
#define SCENA_HH
#include <list>
#include <memory>
#include "lazik.hh"
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"




class Scena {
private:
PzG::LaczeDoGNUPlota &Lacze;
std::shared_ptr<lazik> Aktywny_Lazik=nullptr;
std::list<std::shared_ptr<ObiektGeom>> Wszystkie_Obiekty;

public:
Scena(PzG::LaczeDoGNUPlota &Lacze);
void dodaj_do_listy(std::shared_ptr<ObiektGeom> OB);
void wybeierz_lazik();
void ruch_lazika();
void obrot_lazika();
void menu();

  
    
};





#endif