// FarmEDV.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Farm.h"

#define TITEL "FARM EDV"
#define VERSION   "1.2"

int main()
{
	int eingabe = 0;
	int datengeladen = 0;
    Farm farm;

	cout << "## WELCOME TO " << TITEL << " " << VERSION << " ##" << endl;
	cout << "........lade Farmdaten" << endl << endl;
	farm.loadTiere();
	datengeladen = 1;

	do {
		if (datengeladen == 0) system("cls");
		datengeladen = 0;
		cout << "MENU:" << endl;
		cout << "(1) Eingabe taegl. Tierertrag (Eier(Stk.) / Milch(l)" << endl;
		cout << "(2) Eingabe Bestand Tiere" << endl;
		//cout << "(3) ..." << endl;
		//cout << "(4) ..." << endl;
		cout << endl;
		cout << "(5) Ausgabe Statistik Tiere" << endl;
		//cout << "(6) ..." << endl;
		//cout << "(7) ..." << endl;
		//cout << "(8) ..." << endl;
		cout << endl;
		cout << "(9) Programm beenden" << endl;

		cout << "Eingabe: "; cin >> eingabe;
		if (cin.fail()) {			// cin Abbruch bei falscher Eingabe z.B. Zeichen
			eingabe = 0;
			cin.clear();		// repair instream
			cin.ignore(std::numeric_limits<int>::max(), '\n'); // clear buffer
			cin.ignore();
		}
		
		switch (eingabe) {
        case 1: farm.inputErtragTiere();
			break;
		case 2: farm.editBestandTiere();
			break;
		case 5: farm.printStatistikTiere();
			break;
		case 9:
			system("cls");
			cout << "Bitte warten ..... Farmdaten werden gespeichert" << endl;
            farm.saveTiere();
			cout << "Danke fuer das Verwenden von " << TITEL << " "<< VERSION << endl;
			cout << endl;
			return 0;
			break;
		default:
			cout << "Falsche Eingabe" << endl;
			system("pause");
			break;
		}

	} while (eingabe != 9);

	return 0;
}

