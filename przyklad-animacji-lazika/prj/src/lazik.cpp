#include <iostream>
#include "lazik.hh"
#include <cmath>

#define PI 3,141592653589793238462643

using namespace std;

void::lazik::Przesun_lazik()
{
double KatwRadianach=(KatwStopniach*PI)/180;


}

void::lazik::Obroc_lazik(const Wektor<double> &polozenie)const
{
double KatwRadianach=(KatwStopniach*PI)/180;
double sinus=sin(KatwRadianach);
double cosinus=cos(KatwRadianach);
Wektor<double> pozycja_obrocona;

pozycja_obrocona[0]=(polozenie[0] * cosinus) - (polozenie[1] * sinus);
pozycja_obrocona[1]=(polozenie[0] * cosinus) - (polozenie[1] * sinus);
pozycja_obrocona[2]=polozenie[2];

}