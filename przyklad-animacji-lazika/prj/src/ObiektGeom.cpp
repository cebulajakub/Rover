#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"
#include "Wektor.hh"



using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa,
		        const char*  sNazwaObiektu,
		        int          KolorID,
            double s1,double s2,double s3, double p1, double p2, double p3
		       ):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";

skala[0]=s1;
skala[1]=s2;
skala[2]=s3;
polozenie[1]=p1;
polozenie[2]=p2;
polozenie[3]=p3;

}



bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  double  WspX, WspY, WspZ;
  int Indeks_Wiersza = 0;
  
  StrmWe >> WspX >> WspY >> WspZ;

  if (StrmWe.fail())return false;
  
  do {
    WspX = WspX*skala[0]+polozenie[0];
    WspY = WspY*skala[1]+polozenie[1];    
    WspZ = WspZ*skala[2]+polozenie[2];
    StrmWy << WspX << " " << WspY << " " << WspZ << endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> WspX >> WspY >> WspZ;
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
