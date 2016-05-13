#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // std::setw
using namespace std;

class Tier
{
private: 
	string tierart;             // z.B. Kuh
	string name;				// Name des Tier
	bool aktiv;					// aktiv = am Hof; inaktiv = verkauft;
	int alter;					// Alter
	float ek_preis;		        // Einkaufspreis
	float vk_preis;				// Verkaufspreis

	string erzeugnis;           // z.B. Milch
	int aktMenge;               // Summe Erzeugnismenge  
	string einheit;             // z.B. Liter

public:
	Tier();
	Tier(string tierart);
	void setBuyData();
	void setSellData();
	string getName();
	void inputTaeglErtrag();
	void printStatistik(float preis_milch = 0.4f);
	~Tier();
	friend ofstream& operator<<(ofstream& datei, const Tier &tier);
	friend ifstream& operator>>(ifstream& datei, Tier &tier);
	friend 	bool isName(Tier &tier,string name);
};

