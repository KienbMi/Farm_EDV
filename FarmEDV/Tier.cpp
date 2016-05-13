#include "stdafx.h"
#include "Tier.h"

Tier::Tier() {
}

Tier::Tier(string tierart) {
	this->tierart = tierart;
	this->name = "kein Name";
	this->aktiv = false;
	this->alter = 0;
	this->ek_preis = 0;
	this->vk_preis = 0;
	this->aktMenge = 0;
	this->erzeugnis = "-----";
	this->einheit = "-----";
	
	if (this->tierart == "Kuh") {
		this->erzeugnis = "Milch";
		this->einheit = "Liter";
	}
}

void Tier::setBuyData() {
	cout << "Sie haben ein(e) " << this->tierart << " gekauft" << endl;
	cout << "Wie lautet der Name? ";
	cin >> this->name;
	cout << "Wie alt ist " << this->name << "? ";
	cin >> this->alter;
	cout << "Wie hoch ist der Einkaufspreis (Euro)? ";
	cin >> this->ek_preis;
	this->aktiv = true;
}
void Tier::setSellData() {
	cout << "Sie haben " << this->name << " verkauft." << endl;
	cout << "Wie hoch war der Verkaufspreis (Euro)? ";
	cin >> this->vk_preis; cout << endl;
	this->aktiv = false;
}
string Tier::getName() {
	return this->name;
}
void Tier::inputTaeglErtrag() {
	if ((this->tierart=="Kuh")&&(this->aktiv==true)) {
		int eingabe;
		cout << "Tagesmenge " << this->erzeugnis << " von " << this->name << ": \t\t";
		cin >> eingabe;
		this->aktMenge = this->aktMenge + eingabe;
	}
}

void Tier::printStatistik(float preis_milch) {
	float ertrag = this->vk_preis+(this->aktMenge*preis_milch)-this->ek_preis;
	cout << left    
		 << setw(8) << this->tierart   
		 << setw(15) << this->name
		 << right
		 << setw(5) << this->erzeugnis 
		 << ":" 
		 << setw(5) << this->aktMenge 
		 << setw(6) << this->einheit 
		 << setw(9) << "Ertrag:" 
		 << setw(9) << setprecision(2) << fixed << ertrag
		 << left
		 << setw(5) << " EUR";

	if (!this->aktiv) {
		cout << " VERKAUFT";
	}
	cout << endl;
}


Tier::~Tier() {
}

ofstream& operator<<(ofstream& datei, const Tier &tier) {
	datei << tier.aktiv << " "
		<< tier.tierart << " "
		<< tier.name << " "
		<< tier.alter << " "
		<< tier.erzeugnis << " "
		<< tier.einheit << " "
		<< tier.ek_preis << " "
		<< tier.vk_preis << " "
		<< tier.aktMenge << " ";
	return datei;
}

ifstream& operator>>(ifstream& datei, Tier &tier) {
	datei >> tier.aktiv
		>> tier.tierart
		>> tier.name
		>> tier.alter
		>> tier.erzeugnis
		>> tier.einheit
		>> tier.ek_preis
		>> tier.vk_preis
		>> tier.aktMenge;
	return datei;
}

bool isName(Tier &tier,string name) {
	return (tier.name == name);
}