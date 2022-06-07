#include <iostream>
#include <typeinfo>
#include <memory>
#include <vector>
#include <unistd.h>
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"
#include "lazik.hh"
#include "ObiektGeom.hh"




Scena::Scena(PzG::LaczeDoGNUPlota &Lacze) : Lacze(Lacze){
}

void Scena::dodaj_do_listy(std::shared_ptr<ObiektGeom> OB){
    PzG::InfoPlikuDoRysowania *wInfoPliku;
    wInfoPliku=&Lacze.DodajNazwePliku(OB->WezNazwePliku_BrylaRysowana());
    wInfoPliku->ZmienKolor(OB->WezKolorID());

    Wszystkie_Obiekty.push_back(OB);
}

void Scena::wybeierz_lazik(){
    int numer_lazika=0;
    
    std::vector<std::shared_ptr<ObiektGeom>> laziki;

    for(std::shared_ptr<ObiektGeom> obiekt: Wszystkie_Obiekty){
    if (obiekt->mozliwy_lazik())
    {
        laziki.push_back(obiekt);
    }
}
std::cout<<"\nWybierz lazik ktorym chcesz się poruszać:\n";
for (long unsigned int i = 0; i < laziki.size(); ++i)
{
    std::cout<<" ";
    std::cout<<i+1;
    std::cout<<"-";
    std::cout<< laziki[i]->WezNazweObiektu();
}

std::cout<<"Twoj wybor:";
std::cin>>numer_lazika;

Aktywny_Lazik=std::dynamic_pointer_cast<lazik>(laziki[numer_lazika-1]);

}

void Scena::ruch_lazika(){


    Aktywny_Lazik->Przesun_lazik(Lacze);
}


void Scena::obrot_lazika(){

    Aktywny_Lazik->Obroc_lazik(Lacze);
}


void Scena::menu(){
    char wybor;

    while(true){
        system("clear");
        std::cout<<"\nOpcje:";
        std::cout<<"\n j - jazda";
        std::cout<<"\n o - obrot";
        std::cout<<"\n w - wybor lazika";
        std::cout<<"\n q - wyjście z programu"<<endl;


        std::cin>>wybor;

        switch(wybor){
            case 'j':
                ruch_lazika();
                break;
            case 'o':
                obrot_lazika();
                break;
            case 'w':
                wybeierz_lazik();
                break;
            case 'q':
                system("clear");
                std::cout<<"Wyjście z programu";
                usleep(1000000);
                system("clear");
                exit(1);
            default:
                std::cout<<"Zly znak";
                break;            
        }

    }
}