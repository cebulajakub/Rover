#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename TYP>
class Macierz {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  Wektor<TYP> wektor[ROZMIAR];
  void zamienwiersz(int w1, int w2);
  const TYP & operator () (int x, int y) const {return this-> wektor[x][y];}
  TYP & operator() (int x, int y) {return this->wektor[x][y];}
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    

friend std::istream& operator >> (std::istream &Strm, Macierz<TYP> &Mac){

for(int i=0; i<ROZMIAR;i++)
Strm>>Mac.wektor[i];

return Strm;

}

friend std::ostream& operator<<(std::ostream &Strm, Macierz<TYP> &Mac){

for(int i=0; i<ROZMIAR;i++)
Strm<<Mac.wektor[i];

return Strm;

}

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */



#endif
