#include "stdafx.h"
#include "Kleintier.h"


Kleintier::Kleintier() {
    this->tierart = "Huehner";
    this->aktBestand = 0;
    this->aktMenge = 0;
    this->erzeugnis = "Eier ";
    this->einheit = "Stk. ";
}

void Kleintier::setBuyData() {
    int eingabe;
    cout << "Wieviele " << this->tierart << " wurden erworben? ";
    cin >> eingabe;
    this->aktBestand = this->aktBestand + eingabe;
};

void Kleintier::setSellData() {
    int eingabe;
    cout << "Wieviele " << this->tierart << "wurden abgegeben/aussortiert? ";
    cin >> eingabe;
    this->aktBestand = this->aktBestand - eingabe;
};

void Kleintier::inputTaeglErtrag() {
    int eingabe;
    cout << "Tagesmenge " << this->erzeugnis << " von " << this->aktBestand << " " << this->tierart << ":\t";
    cin >> eingabe;
    this->aktMenge = this->aktMenge + eingabe;
};

void Kleintier::printStatistik(float preis_ei) {
    cout << left
		 << setw(8) << this->tierart
		 << "*Bestand:"
		 << right
		 << setw(3) << this->aktBestand
		 << left
		 << setw(3) << "*"
		 << right
		 << setw(5) << this->erzeugnis
		 << ":"
		 << setw(5) << this->aktMenge
		 << setw(6) << this->einheit
		 << setw(9) << "Ertrag:"
		 << setw(9) << setprecision(2) << fixed << (this->aktMenge * preis_ei)
		 << left
		 << setw(5) << " EUR"
		 << endl;
};

Kleintier::~Kleintier() {
}

ofstream& operator<<(ofstream& datei, const Kleintier &kleintier) {
	datei << kleintier.aktBestand << " "
		<< kleintier.aktMenge << " ";
	return datei;
}

ifstream& operator>>(ifstream& datei, Kleintier &kleintier) {
	datei >> kleintier.aktBestand
		>> kleintier.aktMenge;
	return datei;
}