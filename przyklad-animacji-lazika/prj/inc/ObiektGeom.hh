#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH
#include "Wektor.hh"
#include "Macierz.hh"
#include "lacze_do_gnuplota.hh"

#include <string>


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

class ObiektGeom {
  protected:
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;
    Wektor<double> skala;
    Wektor<double> polozenie;
    Macierz<double> MacierzRotacji;
  
  public:
  Wektor<double> akt;

    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID,double s1,double s2,double s3, double p1, double p2, double p3);

    int WezKolorID() const { return _KolorID; }
  
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
  
    const std::string & WezNazwePliku_BrylaRysowana() const
                 { return _NazwaPliku_BrylaRysowana; }

    bool Przelicz_i_Zapisz_Wierzcholki();
    bool mozliwy_lazik();
    virtual ~ObiektGeom(){};
				     
};


#endif
