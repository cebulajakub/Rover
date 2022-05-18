#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.h"
#include <iostream>
#include <iomanip>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename TYP>
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  
  public:
  TYP wspolczynniki[ROZMIAR+1];
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  Wektor<TYP> operator + (const Wektor<TYP> &L1);
  Wektor<TYP> operator - (const Wektor<TYP> &L1);
  Wektor<TYP> operator * (const TYP &L1);
  Wektor<TYP> operator / (const TYP &L1);
  const TYP & operator [] (int ind) const {return this-> wspolczynniki[ind];}
  TYP & operator[] (int ind) {return this->wspolczynniki[ind];}




friend std::ostream &operator<<(std::ostream &Strm, Wektor<TYP> &Wek){
  int i;
for(i=0;i<ROZMIAR;i++){

    Strm<< std::fixed<<std::setprecision(2)<<Wek[i]<<" ";
}
std::cout<<std::endl;
return Strm;
}

friend std::istream &operator>>(std::istream &Strm, Wektor<TYP> &Wek){
for(int i=0;i<ROZMIAR;i++){
    Strm>>Wek[i];    
}
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
