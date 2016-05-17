#include "stdafx.h"
#include "Farm.h"

#define DATEINAME_KLEINTIERE "Kleintiere.txt"
#define DATEINAME_TIERE   "Tiere.txt"

//aldkjfäasdf
Farm::Farm() {
	this->preis_ei = 0.4f;
	this->preis_milch = 0.8f;
}

void Farm::loadTiere() {							// lade Tierdaten aus Datei
    ifstream file;
    
    file.open(DATEINAME_KLEINTIERE);
    if (file) {
        file >> huehner;
    }
    file.close();

    file.open(DATEINAME_TIERE);
    if (file) {
        while (!file.eof()) {
            Tier tempTier;
            file >> tempTier;
            if (file.eof()) break;
            tiere.push_back(tempTier);
        }
    }
    file.close();
}

void Farm::saveTiere() {							// sichere Tierdaten in Datei		
    ofstream file;
    file.open(DATEINAME_KLEINTIERE);
    if (file) {
        file << huehner;
    }
    file.close();

    file.open(DATEINAME_TIERE);
    if (file) {
        vector<Tier>::iterator it;
        for (it = tiere.begin(); it != tiere.end(); it++) {
            file << *it << endl;
        }
    }
    file.close();
}

void Farm::inputErtragTiere() {
	system("cls");
    cout << "EINGABE TAEGL. TIERERTRAG (Eier(Stk.) / Milch(l)" << endl << endl;
    huehner.inputTaeglErtrag();
    vector<Tier>::iterator it;
    for (it = tiere.begin(); it != tiere.end(); it++) {
        it->inputTaeglErtrag();
    }
	cout << endl << "Tagesmenge fuer alle Tiere eingegeben    " << endl;
	system("pause");
}

void Farm::editBestandTiere() {
    int eingabe = 0;
    string name;
    do {
		system("cls");
		cout << "EINGABE BESTAND TIERE" << endl;
        cout << "(1) Huhn gekauft" << endl;
        cout << "(2) Huhn verkauft" << endl;
        cout << "(3) Kuh gekauft" << endl;
        cout << "(4) Schwein gekauft" << endl;
        cout << "(5) Tier verkauft" << endl;
        cout << endl;
        cout << "(9) Zurueck" << endl;

        cout << "Eingabe: "; cin >> eingabe;
		if (cin.fail()) {			// cin Abbruch bei falscher Eingabe z.B. Zeichen
			eingabe = 0;
			cin.clear();		// repair instream
			cin.ignore(std::numeric_limits<int>::max(), '\n'); // clear buffer
		}

        switch (eingabe) {
        case 1: huehner.setBuyData();
            break;
        case 2: huehner.setSellData();
            break;
        case 3: tiere.push_back(Tier("Kuh"));
            tiere.back().setBuyData();
            break;
        case 4: tiere.push_back(Tier("Schwein"));
            tiere.back().setBuyData();
            break;
        case 5:
            cout << "Wer wurde verkauft? "; cin >> name;
            for (it = tiere.begin(); it != tiere.end(); it++) {
                if (it->getName() == name) {
                    it->setSellData();
					break;
                }
            }
			if (it == tiere.end()) cout << name << " nicht vorhanden!" << endl;
            break;
        case 9:
            return;
            break;
        default:
			cout << "Falsche Eingabe" << endl;
			system("pause");
            break;
        }

    } while (eingabe != 0);
}

void Farm::printStatistikTiere() {
	system("cls");
    cout << "AUSGABE STATISTIK TIERE" << endl << endl;
    huehner.printStatistik();
    vector<Tier>::iterator it;
    for (it = tiere.begin(); it != tiere.end(); it++) {
        it->printStatistik();
    }
	system("pause");
}

Farm::~Farm() {
}
