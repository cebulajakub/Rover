#include "Macierz.hh"
#include "Wektor.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

template<typename TYP>
void Macierz<TYP>::zamienwiersz(int w1, int w2){
    Wektor<TYP>  x;
x=(*this).wektor[w1];
(*this).wektor[w1]=(*this).wektor[w2];
(*this).wektor[w2]=x;
}