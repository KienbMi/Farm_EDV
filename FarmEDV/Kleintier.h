#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // std::setw
using namespace std;


class Kleintier
{
private:
    string tierart;             // z.B. Huhn, 
    int aktBestand;             // aktueller Bestand
    
    string erzeugnis;           // z.B. Eier
    int aktMenge;               // Summe Erzeugnismenge  
    string einheit;             // z.B. Stk.

public:
    Kleintier();
    void setBuyData();
    void setSellData();
    void inputTaeglErtrag();
    void printStatistik(float preis_ei = 0.4f);
    ~Kleintier();
	friend ofstream& operator<<(ofstream& datei, const Kleintier &kleintier);
	friend ifstream& operator>>(ifstream& datei, Kleintier &kleintier);
};

