#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <cstdio>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

using namespace std;

class Przeksztalcenia;  //deklarujemy klase przeksztalcenia

class Macierz{

public:

    static const int rozmiar = 4;
    float** tab;

public:

    Macierz();
    Macierz(float);
    Macierz(float [rozmiar][rozmiar]);
    Pokaz();
    Macierz operator = (const float & x){
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 tab[i][j] = x;
            }
        }
        return *this;
    }
    Macierz operator + (const float & x){
        Macierz* wynik = new Macierz;
        //wynik->Macierz();
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 wynik->tab[i][j] = this->tab[i][j] + x;
            }
        }
        return *wynik;
    }
    Macierz operator += (const float & x){
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 tab[i][j] = tab[i][j] + x;
            }
        }
        return *this;
    }
    Macierz operator - (const float & x){
        Macierz* wynik = new Macierz;
        //wynik->Macierz();
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 wynik->tab[i][j] = this->tab[i][j] - x;
            }
        }
        return *wynik;
    }
    Macierz operator -= (const float & x){
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 tab[i][j] = tab[i][j] - x;
            }
        }
        return *this;
    }
    Macierz operator * (const int & x){
        Macierz* wynik = new Macierz;
        //wynik->Macierz();
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 wynik->tab[i][j] = this->tab[i][j] * x;
            }
        }
        return *wynik;
    }
    Macierz operator *= (const int & x){
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                 tab[i][j] = tab[i][j] * x;
            }
        }
        return *this;
    }
    Macierz operator * (const Macierz & x){
        Macierz* wynik = new Macierz;
        //wynik->Macierz();
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                    wynik->tab[i][j] = 0;
                    for ( int k = 0; k < rozmiar; k++ ) wynik->tab[i][j] += this->tab[i][k] * x.tab[k][j];
            }
        }
        return *wynik;
    }
    Macierz operator *= (const Macierz & x){
        Macierz* wynik = new Macierz;
        //wynik->Macierz();
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                    wynik->tab[i][j] = 0;
                    for ( int k = 0; k < rozmiar; k++ ) wynik->tab[i][j] += this->tab[i][k] * x.tab[k][j];
            }
        }

        for( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                this->tab[i][j] = wynik->tab[i][j];
            }
        }

        return *this;
    }
    Macierz operator * (const float *x){
        Macierz* wynik = new Macierz;
        //wynik->Macierz();
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                    wynik->tab[i][j] = 0;
                    for ( int k = 0; k < rozmiar; k++ ) wynik->tab[i][j] += this->tab[i][k] * x[k];
            }
        }
        return *wynik;
    }
    friend std::ostream&	operator << ( std::ostream& out, const Macierz& x );
    Ustaw(int w, int k, float x){
        tab[w][k] = x;
    }
    Sprawdz(int w, int k){
        cout << tab[w][k];
    }
    Jednostkowa(){
        for ( int i = 0; i < rozmiar; i++){
            for (int j = 0; j < rozmiar; j++){
                if( i == j) tab[i][j] =1;
                else tab[i][j] = 0;
            }
        }
    }
    Transpozycja(){
        float temp;
        for(int i = 0; i < rozmiar - 1; i++){
            for(int j = i + 1; j < rozmiar; j++)
            {
              temp = tab[i][j];
              tab[i][j] = tab[j][i];
              tab[j][i] = temp;
            }
        }
    }
    friend Przeksztalcenia;
};

Macierz::Macierz(){
    tab = new float* [rozmiar];
    for ( int i = 0; i < rozmiar; i++){
        tab[i] = new float [rozmiar];
    }
    for ( int i = 0; i < rozmiar; i++){
        for (int j = 0; j < rozmiar; j++){
            tab[i][j] = 0;
        }
    }
}

Macierz::Macierz(float x){
    tab = new float* [rozmiar];
    for ( int i = 0; i < rozmiar; i++){
        tab[i] = new float [rozmiar];
    }
    for ( int i = 0; i < rozmiar; i++){
        for (int j = 0; j < rozmiar; j++){
            tab[i][j] = x;
        }
    }
}

Macierz::Macierz ( float tablica[rozmiar][rozmiar] ){
    tab = new float* [rozmiar];
    for ( int i = 0; i < rozmiar; i++){
        tab[i] = new float [rozmiar];
    }
    for ( int i = 0; i < rozmiar; i++){
        for (int j = 0; j < rozmiar; j++){
            tab[i][j] = tablica[i][j];
        }
    }
}

Macierz::Pokaz(){
    for ( int i = 0; i < rozmiar; i++){
        for (int j = 0; j < rozmiar; j++){
            cout << tab[i][j] << " " ;
        }
        cout << endl;
    }
}

std::ostream& operator << (std::ostream& out, const Macierz & x){

        for ( int i = 0; i < x.rozmiar; i++){
            for (int j = 0; j < x.rozmiar; j++){
                out << x.tab[i][j] << " " ;
            }
            out << endl;
        }
        return out;
    }

//TO CO ZNAJDUJE SIE WYZEJ JUZ BYLO W POPRZEDNIM PROGRAMIE///

class Przeksztalcenia{

private:
    int wymiar;
    static const int maksRozmiar = 4;


public:
    Macierz macierz;    //jedna ze zmiennych jest zmienna typu macierz
    Skalowanie2D(float);    //tak jak poprzednio, deklarujemy funkcje
    Skalowanie2D(float, float); //tutaj np funkcja sklalowanie z dwoma argumentami typu float
    Skalowanie2D(float []); //a tutaj funkcja skalowanie z tablica jako argument
    Rotacja2D(float);   //funkcja rotaja z jednym argumentem
    Translantacja2D(float);
    Translantacja2D(float,float);
    Translantacja2D(float []);

    Skalowanie3D(float);
    Skalowanie3D(float, float, float);
    Skalowanie3D(float []);
    Rotacja3D(float, char); //tutaj argumentem jest takze litera, oznaczajaca os
    Translantacja3D(float);
    Translantacja3D(float,float, float);
    Translantacja3D(float []);
};

Przeksztalcenia::Skalowanie2D(float x){
    wymiar = 3; //tutaj okreslamy wymiar naszej macierzy 2d wiec macierz 3x3
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if( i == j && (j == 0 || j == 1)){
                macierz.tab[i][j] = x;  //na przekatnej w pierwszym i drugim wyrazie wpisujemy wartosc "x"
            }else if ( i == j ){
                macierz.tab[i][j] = 1;  //pozostale miescje na przekatnej dajemy 1
            }else{
                macierz.tab[i][j] = 0;  //wszystkie inne miejsca maxcierzy dajemy 0
            }
        }
    }
}

Przeksztalcenia::Skalowanie2D(float x, float y){//dokladnie to samo co wyzej
    wymiar = 3;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if( i == j && j == 0){
                macierz.tab[i][j] = x;
            }else if( i == j && j == 1){
                macierz.tab[i][j] = y;  //jedyna zmina to tutaj, zamiast dwa razy wpisac wartosc x, to wpisujemy y
            }else if ( i == j ){
                macierz.tab[i][j] = 1;
            }else{
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Skalowanie2D(float tablica []){
    wymiar = 3;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if( i == j && i == 0){
                macierz.tab[i][j] = tablica[i];//jak wyzej, ale wpisujemy elementy tablicy na przekatnych macierzy
            }else if( i == j && i == 1){
                macierz.tab[i][j] = tablica[i];
            }else if ( i == j ){
                macierz.tab[i][j] = 1;
            }else{
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Rotacja2D (float x){//wypelniamy macierz  rotacji zgodnie z szablonem
    wymiar = 3;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j && (j == 0 || j == 1)){
                macierz.tab[i][j] = cos(x); //funkcje trygonometryczne obliczamy za pomoca wbudowanych funkcji w math.h
            }else if(i == 0 && j == 1){
                macierz.tab[i][j] = sin(x);
            }else if ( i == 1 && j == 0){
                macierz.tab[i][j] = -sin(x);
            }else if (i == j){
                macierz.tab[i][j] = 1;
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Translantacja2D (float x){//wypelniamy macierz translacji zgodnie z szablonem
    wymiar = 3;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j) {
                macierz.tab[i][j] = 1;
            }else if(i == 0 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else if ( i == 1 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else if (i == wymiar - 1 && (j == wymiar - 1)){
                macierz.tab[i][j] = 1;
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Translantacja2D (float x, float y){//wypelniamy macierz translacji zgodnie z szablonem
    wymiar = 3;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j) {
                macierz.tab[i][j] = 1;
            }else if(i == 0 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else if ( i == 1 && j == wymiar - 1){
                macierz.tab[i][j] = y;  //w tym przypadku przekazujemy do funkcji dwa argumenty, x i y
            }else if (i == wymiar - 1 && (j == wymiar - 1)){
                macierz.tab[i][j] = 1;
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Translantacja2D (float tablica[]){
    wymiar = 3;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j) {
                macierz.tab[i][j] = 1;
            }else if(i == 0 && j == wymiar - 1){
                macierz.tab[i][j] = tablica[i];
            }else if ( i == 1 && j == wymiar - 1){
                macierz.tab[i][j] = tablica[i];
            }else if (i == wymiar - 1 && (j == wymiar - 1)){
                macierz.tab[i][j] = 1;
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Skalowanie3D(float x){ //przeksztalcenia 3d
    wymiar = 4; //teraz beda macierze 4x4
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if( i == j && (j == 0 || j == 1 || j == 2)){
                macierz.tab[i][j] = x;  //w odpowidnie miejsca wpisujemy wartosci x
            }else if ( i == j ){
                macierz.tab[i][j] = 1;
            }else{
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Skalowanie3D(float x, float y, float z){   //tej funkcji przekazujemy 3 argumenty
    wymiar = 4;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if( i == j && j == 0){
                macierz.tab[i][j] = x;  //wpisujemy argumenty w odpowiednie miejsca
            }else if( i == j && j == 1){
                macierz.tab[i][j] = y;
            }else if( i == j && j == 2){
                macierz.tab[i][j] = z;
            }else if ( i == j ){
                macierz.tab[i][j] = 1;
            }else{
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Skalowanie3D(float tablica []){//wszystkie funkcje dzialaja bardzo podobnie
    wymiar = 4;
    for ( int i = 0; i < wymiar; i++){  //wszystkie skladaja sie z dwoch petli for
        for ( int j = 0; j < wymiar; j++){  //jedna inkrementuje wiersze (i) a druga kolumny
            if( i == j && i == 0){
                macierz.tab[i][j] = tablica[i]; //funkcje roznia sie zawartoscia w petlach for, sa w nich rozne warunki
            }else if( i == j && i == 1){        // i wpisujemy do nich inne rzeczy
                macierz.tab[i][j] = tablica[i];
            }else if( i == j && i == 2){
                macierz.tab[i][j] = tablica[i];
            }else if ( i == j ){
                macierz.tab[i][j] = 1;
            }else{
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Rotacja3D (float x, char os){  //w tej funkcji dodatkowych argumentem jest litera oznaczajaca os przeksztalcen
    wymiar = 4;
    if ( os == 'x'){//dzialania dla osi x
        for ( int i = 0; i < wymiar; i++){  //wypelniamy zgodnie z szablonym znalezionym na wikipedii
            for ( int j = 0; j < wymiar; j++){
                if ( i == j && (j == 2 || j == 1)){
                    macierz.tab[i][j] = cos(x);
                }else if(i == 1 && j == 2){
                    macierz.tab[i][j] = -sin(x);
                }else if ( i == 2 && j == 1){
                    macierz.tab[i][j] = sin(x);
                }else if (i == j){
                    macierz.tab[i][j] = 1;
                }else {
                    macierz.tab[i][j] = 0;
                }
            }
        }
    }else if (os == 'y'){//wypelniamy zgodnie z szablonym znalezionym na wikipedii dla osi y
        for ( int i = 0; i < wymiar; i++){
            for ( int j = 0; j < wymiar; j++){
                if ( i == j && (j == 2 || j == 0)){
                    macierz.tab[i][j] = cos(x);
                }else if(i == 0 && j == 2){
                    macierz.tab[i][j] = sin(x);
                }else if ( i == 2 && j == 0){
                    macierz.tab[i][j] = -sin(x);
                }else if (i == j){
                    macierz.tab[i][j] = 1;
                }else {
                    macierz.tab[i][j] = 0;
                }
            }
        }
    }else if (os == 'z'){//wypelniamy zgodnie z szablonym znalezionym na wikipedii dla osi z
        for ( int i = 0; i < wymiar; i++){
            for ( int j = 0; j < wymiar; j++){
                if ( i == j && (j == 1 || j == 0)){
                    macierz.tab[i][j] = cos(x);
                }else if(i == 1 && j == 0){
                    macierz.tab[i][j] = sin(x);
                }else if ( i == 0 && j == 1){
                    macierz.tab[i][j] = -sin(x);
                }else if (i == j){
                    macierz.tab[i][j] = 1;
                }else {
                    macierz.tab[i][j] = 0;
                }
            }
        }
    }
}

Przeksztalcenia::Translantacja3D (float x){
    wymiar = 4;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j) {
                macierz.tab[i][j] = 1;
            }else if(i == 0 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else if ( i == 1 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else if ( i == 2 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Translantacja3D (float x, float y, float z){
    wymiar = 4;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j) {
                macierz.tab[i][j] = 1;
            }else if(i == 0 && j == wymiar - 1){
                macierz.tab[i][j] = x;
            }else if ( i == 1 && j == wymiar - 1){
                macierz.tab[i][j] = y;
            }else if ( i == 2 && j == wymiar - 1){
                macierz.tab[i][j] = z;
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

Przeksztalcenia::Translantacja3D (float tablica[]){
    wymiar = 4;
    for ( int i = 0; i < wymiar; i++){
        for ( int j = 0; j < wymiar; j++){
            if ( i == j) {
                macierz.tab[i][j] = 1;
            }else if(i == 0 && j == wymiar - 1){
                macierz.tab[i][j] = tablica[i];
            }else if ( i == 1 && j == wymiar - 1){
                macierz.tab[i][j] = tablica[i];
            }else if ( i == 2 && j == wymiar - 1){
                macierz.tab[i][j] = tablica[i];
            }else {
                macierz.tab[i][j] = 0;
            }
        }
    }
}

int main(){

    float tablica[4][4] = { {3, 5, 6, 8}, {5, 1, 4, 7}, {2, 4.5, 6, 7}, {0.4, 5.6, 7.7, 8} };

    float wektor [4] = {0.12, 0.5, 0.3, 0.89};
    float x = 4.5, z;
    int integer, w, k, y;

    cout << "Czesc pierwsza - dzialania na macierzach." << endl;
    cout << "Deklaruje zmienne typu \"Macierz\"" << endl;

    Macierz  nasza;//  new Macierz


    cout << "Najpierw spawdzimy konstruktory:" << endl;
    cout << "Uzywam kontruktora zmiennej \"Macierz\" bez parametrow:" << endl;

    cout << endl << "Oto utworzona macierz:" << endl;
    nasza.Pokaz();

    cout << endl << "Teraz utwoerzymy macierz z uzyciem konstruktora z jednym argumentem" << endl;
    cout << "Podaj liczbe typu float." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    Macierz  temp(x);
    cout << endl << "Oto utworzona macierz:" << endl;
    temp.Pokaz();

    cout << endl << "Teraz utworzymy macierz z uzyciem konstruktora, z tablica jako argumentem" << endl;
    cout << "Uzyjemy wczesniej przygotowanej tablicy:" << endl;
    for ( int i = 0; i < 4; i++){
        for ( int j = 0; j < 4; j++){
            cout << tablica[i][j] << " ";
        }
        cout << endl;
    }

    Macierz temp2(tablica);
    cout << endl << "Oto utworzona macierz z tablicy jako argument konstruktora:" << endl;
    temp2.Pokaz();

    cout << "Teraz bedziemy sprawdzac operatory:" << endl;
    cout << "Punkt 2.1 - przypisanie (*nasza = x), podaj liczbe float." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    nasza = x;
    cout << endl << "Oto nasza macierz:" << endl;
    nasza.Pokaz();

    cout << "Punkt 2.2 - dodawanie (*temp = *nasza + x), podaj liczbe float." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    temp = nasza + x;
    cout << endl << "Oto macierz pomocnicza:" << endl;
    temp.Pokaz();

    cout << "Punkt 2.3 - dodawanie z przypisaniem (*nasza += x), podaj liczbe float." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    nasza += x;
    cout << endl << "Oto nasza macierz:" << endl;
    nasza.Pokaz();

    cout << "Punkt 2.4 - odejmowanie (*temp=*nasza-x), podaj liczbe float." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    temp = nasza - x;
    cout << endl << "Oto macierz pomocnicza:" << endl;
    temp.Pokaz();

    cout << "Punkt 2.5 - odejmowanie z przypisaniem (*nasza -= x), podaj liczbe float." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    nasza -= x;
    cout << endl << "Oto nasza macierz:" << endl;
    nasza.Pokaz();

    cout << "Punkt 2.6 - mnozenie (*temp=*nasza * integer), podaj liczbe int." << endl;
    while ( !(cin >> integer) ){
                cout << "Wprowadz liczbe int." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    temp = nasza * integer;
    cout << endl << "Oto macierz pomocnicza:" << endl;
    temp.Pokaz();

    cout << "Punkt 2.7 - mnozenie z przypisaniem (*nasza *= integer), podaj liczbe int." << endl;
    while ( !(cin >> integer) ){
                cout << "Wprowadz liczbe int." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    nasza *= integer;
    cout << endl << "Oto nasza macierz:" << endl;
    nasza.Pokaz();

    cout << "Przed mnozeniem macierzy sprawdzimy sobie mnozwenie przez wektor." << endl;
    cout << "Tak jak wczesniej mamy juz przygotowany wektor." << endl;
    for (int i = 0; i < 4; i++) cout << wektor[i] << " ";
    cout << endl << "2.10 mnozenie przez wektor (*temp = *nasza * wektor):" << endl;
    temp = nasza * wektor;
    cout << "Oto macierz pomocnicza:" << endl;
    temp.Pokaz();

    cout << "Punkt 2.8 - mnozenie macierzy (*temp2=*nasza*(*temp))." << endl;
    temp2 = nasza * temp;
    cout << endl << "Oto macierz pomocnicza2:" << endl;
    temp2.Pokaz();

    cout << "Punkt 2.9 - mnozenie macierzy z przypisaniem (*nasza *= *temp)." << endl;
    nasza *= temp;
    cout << endl << "Oto nasza macierz:" << endl;
    nasza.Pokaz();

    cout << "Pomnozymy jeszcze macierze utworzne za pomoca konstruktora z tablica jako argumentem." << endl;
    //tempStworz(tablica);
    //nasza->Stworz(tablica);
    nasza *= temp;
    cout << "Wynik pokazemy jako cout << *nasza << endl (punkt 2.11)" <<endl;
    cout << nasza << endl;

    cout << "Przechodzimy do punktu 3." << endl;

    cout << "Punkt 3.1, ustawimy jakis element, podaj wiersz." << endl;
    while ( !(cin >> w) || w > 3 || w < 0 ){
                cout << "Wprowadz liczbe int." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    cout << "Podaj kolumne." << endl;
    while ( !(cin >> k ) || k > 3 || k < 0){
                cout << "Wprowadz liczbe int." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    cout << "Podaj liczbe float, ktora wpisac w podane miejsce." << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    nasza.Ustaw(w,k,x);
    cout << "Oto nasza macierz:" << endl;
    nasza.Pokaz();

    cout << "Podaj element macierzy, ktory odczytac." << endl;
    cout << "Podaj wiersz." << endl;
    while ( !(cin >> w) || w > 3 || w < 0){
                cout << "Wprowadz liczbe int." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    cout << "Podaj kolumne." << endl;
    while ( !(cin >> k) || k > 3 || k < 0){
                cout << "Wprowadz liczbe int." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    nasza.Sprawdz(w,k);

    cout << "Z punktu 3.2 wielokrotnie korzystalismy w tym programie." << endl;
    cout << "3.3. Funkcja tworzaca macierz jednostkowa (wpiszemy ja do zmiennnej temp2):" << endl;
    temp2.Jednostkowa();
    cout << "Oto ona:" << endl;
    temp2.Pokaz();

    cout << "Ostatnie zadanie, transponowanie maciierzy." << endl;
    cout << "Oto nasza macierz przed transpozycja:" << endl;
    nasza.Pokaz();
    cout << "Transponujemy." << endl;
    nasza.Transpozycja();
    cout << "Nasza macierz po transpozycji:" << endl;
    cout << nasza << endl;

    Przeksztalcenia test;   //klase przeksztalcenia nazwiemy sobie test

    test.Rotacja3D(M_PI, 'x');
    test.macierz.Pokaz();
    cout<<test.macierz.tab[1][1];

    cout << "Czesc druga - przkesztalcenia macierzy." << endl;
    cout << "Skalowanie macierzy 2d - jeden argument." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Skalowanie2D(x);
    test.macierz.Pokaz();   //tak odwolujemy sie do funkcji w klasie macierz poprzez klase przeksztalcenia
    cout << endl;

    cout << "Skalowanie macierzy 2d - dwa argumenty." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> y) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Skalowanie2D(x, y);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Skalowanie macierzy 2d - tablica." << endl;
    cout << "Tablica beda wczesniej podane argumenty w odwortnej kolejnosci." << endl;
    wektor[0] = y;
    wektor[1] = x;
    test.Skalowanie2D(wektor);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Rotacja macierzy 2d." << endl;
    cout << "pi/2 (argument)" << endl;
    test.Rotacja2D(M_PI/2);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Translantacja macierzy 2d - jeden argument." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Translantacja2D(x);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Translantacja macierzy 2d - dwa argumenty." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> y) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Translantacja2D(x,y);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Translantacja macierzy 2d - tablica." << endl;
    cout << "Tablica beda wczesniej podane argumenty w odwortnej kolejnosci." << endl;
    wektor[0] = y;
    wektor[1] = x;
    test.Translantacja2D(wektor);
    test.macierz.Pokaz();

//////////////////////////////3D//////////////////////////////////////////////////////

    cout << "Teraz 3d" << endl;
    cout << "Skalowanie macierzy 3d - jeden argument." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Skalowanie3D(x);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Skalowanie macierzy 3d - 3 argumenty." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> y) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    while ( !(cin >> z) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Skalowanie3D(x, y, z);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Skalowanie macierzy 3d - tablica." << endl;
    cout << "Tablica beda wczesniej podane argumenty w odwortnej kolejnosci." << endl;
    wektor[0] = z;
    wektor[1] = y;
    wektor[2] = x;
    test.Skalowanie3D(wektor);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Rotacja macierzy 3d." << endl;
    cout << "pi/2 (argument), os x" << endl;
    test.Rotacja3D(M_PI/2, 'x');
    test.macierz.Pokaz();
    cout << endl;
    cout << "pi (argument), os y" << endl;
    test.Rotacja3D(M_PI, 'y');
    test.macierz.Pokaz();
    cout << endl;
    cout << "2pi (argument), os z" << endl;
    test.Rotacja3D(2*M_PI, 'z');
    test.macierz.Pokaz();
    cout << endl;

    cout << "Translantacja macierzy 3d - jeden argument." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> x) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Translantacja3D(x);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Translantacja macierzy 3d - 3 argumenty." << endl;
    cout << "Podaj liczbe float (argument)" << endl;
    while ( !(cin >> y) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    while ( !(cin >> z) ){
                cout << "Wprowadz liczbe float." << endl;
                cin.clear(); //kasowanie flagi b³êdu strumienia
                cin.sync(); //kasowanie zbêdnych znaków z bufora
    }
    test.Translantacja3D(x,y,z);
    test.macierz.Pokaz();
    cout << endl;

    cout << "Translantacja macierzy 3d - tablica." << endl;
    cout << "Tablica beda wczesniej podane argumenty w odwortnej kolejnosci." << endl;
    wektor[0] = z;
    wektor[1] = y;
    wektor[2] = x;
    test.Translantacja3D(wektor);
    test.macierz.Pokaz();

    getchar();

return 0;
}
