#include <iostream>
#include <cstdlib>
#include "lazik.hh"
#include "Wektor.hh"
#include "lacze_do_gnuplota.hh"
#include <cmath>
#include "Macierz.cpp"

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


bool lazik::Kolizja(std::list<std::shared_ptr<ObiektGeom>> Wszystkie_Obiekty)
{
double odleglosc;
double maksymalna_odleglosc=25;
Wektor<double> Wek;
Wektor<double> Pol=(*this).Polozenie();
std::vector<std::shared_ptr<ObiektGeom>> laziki;

for(std::shared_ptr<ObiektGeom> obiekt: Wszystkie_Obiekty)
{
    if(obiekt->WezNazweObiektu()!=(*this).WezNazweObiektu())
    laziki.push_back(obiekt);
}

for(long unsigned int i=0;i<laziki.size();i++)
{
    Wek=laziki[i]->Polozenie();
    odleglosc=sqrt(((Wek[0]-Pol[0])*(Wek[0]-Pol[0]))+((Wek[1]-Pol[1])*(Wek[1]-Pol[1])));

if(odleglosc<maksymalna_odleglosc)
{
    std::cout<<"Prawdopodobna kolizja"<<std::endl;
    return 1;
}
}
return 0;

}




bool::lazik::Przesun_lazik(PzG::LaczeDoGNUPlota &Lacze,std::list<std::shared_ptr<ObiektGeom>> Wszystkie_Obiekty)
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
if((*this).Kolizja(Wszystkie_Obiekty)==1)
{
    std::cout<<"Prawdopodobna kolizja";
    polozenie=polozenie-wek;
    return 1;
}
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj();
}
if (OdlegloscDoPrzejechania!=0)
{
    wek[0]=cos(KatwRadianach)*OdlegloscDoPrzejechania;
    wek[1]=sin(KatwRadianach)*OdlegloscDoPrzejechania;
    wek[2]=0;
    polozenie=polozenie+wek;
    if((*this).Kolizja(Wszystkie_Obiekty)==1)
{
    std::cout<<"Prawdopodobna kolizja";
    polozenie=polozenie-wek;
    return 1;
}
    Przelicz_i_Zapisz_Wierzcholki();
    Lacze.Rysuj(); 
    OdlegloscDoPrzejechania=0;  
}
return 0;
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

bool lazik::Przelicz_i_Zapisz_Wierzcholki()
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

  Wektor<double> Wsp;
  int Indeks_Wiersza = 0;
  
  StrmWe >> Wsp;

  if (StrmWe.fail())return false;
  
  do {
    Wsp = MacierzRotacji*(Wsp*skala)+polozenie;
    StrmWy << Wsp<<endl;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    StrmWe >> Wsp;
    
  } while (!StrmWe.fail());

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

bool lazik::mozliwy_lazik(){
    return true;
}