#include <iostream>
#include <cstdlib>
#include "lazik.hh"
#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"
#include <cmath>

#define PI 3.141592653589793238462643

using namespace std;

lazik::lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID,double s1,double s2,double s3, double p1, double p2, double p3, float orientacja):
ObiektGeom(sNazwaPliku_BrylaWzorcowa,sNazwaObiektu,KolorID,s1,s2,s3,p1,p2,p3), KatwStopniach(orientacja)
{
    OdlegloscDoPrzejechania=0;
    float KatwRadianach=KatwStopniach*(PI/180);
    MacierzRotacji(0,0)=cos(KatwRadianach); MacierzRotacji(0,1)=((-1)*sin(KatwRadianach)); MacierzRotacji(0,2)=0;
    MacierzRotacji(1,0)=sin(KatwRadianach); MacierzRotacji(1,1)=cos(KatwRadianach); MacierzRotacji(1,2)=0;
    MacierzRotacji(2,0)=0; MacierzRotacji(2,1)=0; MacierzRotacji(2,2)=1;

}






void::lazik::Przesun_lazik(PzG::LaczeDoGNUPlota &Lacze)
{
cout<<"Podaj odleglosc o jaka ma sie przesunac lazik:"<<endl;
cin>>OdlegloscDoPrzejechania;

OdlegloscDoPrzejechania=abs(OdlegloscDoPrzejechania);

float KatwRadianach=(KatwStopniach*PI)/180;
Wektor<double> wek;
while(OdlegloscDoPrzejechania>=0.1){
    wek[0]=cos(KatwRadianach)*0.1;
    wek[1]=sin(KatwRadianach)*0.1;
    wek[2]=0;
    OdlegloscDoPrzejechania=OdlegloscDoPrzejechania-0.1;
    polozenie=polozenie+wek;
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();
}
if (OdlegloscDoPrzejechania!=0)
{
    wek[0]=cos(KatwRadianach)*OdlegloscDoPrzejechania;
    wek[1]=sin(KatwRadianach)*OdlegloscDoPrzejechania;
    wek[2]=0;
    polozenie=polozenie+wek;
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj(); 
    OdlegloscDoPrzejechania=0;  
}

}

void::lazik::Obroc_lazik(PzG::LaczeDoGNUPlota &Lacze)
{
float x;
float KatwRadianach;
float tymczasowe=KatwStopniach;

cout<<"Podaj kat (w stopnaich) o jaki chcesz obrocic lazik"<<endl;
cin>>x;
KatwStopniach= KatwStopniach + x;

while(tymczasowe<KatwStopniach){
    KatwRadianach=tymczasowe*(PI/180);
    MacierzRotacji(0,0)=cos(KatwRadianach); MacierzRotacji(0,1)=((-1)*sin(KatwRadianach)); MacierzRotacji(0,2)=0;
    MacierzRotacji(1,0)=sin(KatwRadianach); MacierzRotacji(1,1)=cos(KatwRadianach); MacierzRotacji(1,2)=0;
    MacierzRotacji(2,0)=0; MacierzRotacji(2,1)=0; MacierzRotacji(2,2)=1;
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();
    tymczasowe=tymczasowe+0.1;
}
if((tymczasowe-1)!=KatwStopniach)
{
    KatwRadianach=(tymczasowe+(KatwStopniach-(tymczasowe-1)))*(PI/180);
    MacierzRotacji(0,0)=cos(KatwRadianach); MacierzRotacji(0,1)=((-1)*sin(KatwRadianach)); MacierzRotacji(0,2)=0;
    MacierzRotacji(1,0)=sin(KatwRadianach); MacierzRotacji(1,1)=cos(KatwRadianach); MacierzRotacji(1,2)=0;
    MacierzRotacji(2,0)=0; MacierzRotacji(2,1)=0; MacierzRotacji(2,2)=1;
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();
}

}

bool lazik::mozliwy_lazik(){
    return true;
}