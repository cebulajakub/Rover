#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
template<typename TYP>
Wektor<TYP> Wektor<TYP>::operator +(const Wektor<TYP> &L1){
Wektor<TYP> wynik;

for(int i=0;i<ROZMIAR;i++){
wynik[i]=this->wspolczynniki[i]+L1[i];
}
return wynik;
}

template<typename TYP>
Wektor<TYP> Wektor<TYP>::operator -( const Wektor<TYP> &L1){
Wektor<TYP> wynik;

for(int i=0;i<ROZMIAR;i++){
wynik[i]=this->wspolczynniki[i]-L1[i];
}
return wynik;
}

template<typename TYP>
Wektor<TYP> Wektor<TYP>::operator *(const TYP &L1){
Wektor<TYP> wyn;

for(int i=0;i<ROZMIAR;i++){
wyn[i]=(*this)[i]*L1;
}
return wyn;
}

template<typename TYP>
Wektor<TYP> Wektor<TYP>::operator /(const TYP &L1){
Wektor<TYP> wyn;

for(int i=0;i<ROZMIAR;i++){
wyn[i]=(*this)[i]/L1;
}
return wyn;
}
