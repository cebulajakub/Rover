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
template<typename TYP>
Wektor<TYP> Macierz<TYP>::operator *(const Wektor<TYP> Wek)const
{
Wektor<TYP> wektor;
int i,j;

wektor[0]=0; wektor[1]=0; wektor[2]=0;
for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            wektor[i]+=(*this)(i,j)*Wek[j];
        }
    }

return wektor;
}