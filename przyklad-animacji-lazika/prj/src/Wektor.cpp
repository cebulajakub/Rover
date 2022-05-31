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

template<typename TYP>
Wektor<TYP> Wektor<TYP>::operator *(const Wektor<TYP> &L1){
Wektor<TYP> wektor;

wektor[0]=(*this)[0]*L1[0];
wektor[1]=(*this)[1]*L1[1];
wektor[2]=(*this)[2]*L1[2];

return wektor;
}