/*
 * Roulette.cpp
 *
 *  Created on: 11.07.2023
 *      Author: fabia
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string.h>

class RouletteSpiel {
public:
    virtual bool gewonnen(int gewinnzahl) = 0;
    virtual ~RouletteSpiel() {}
};

class ZahlSpiel : public RouletteSpiel {
private:
    std::vector<int> zahlen;

public:

    ZahlSpiel(const std::vector<int>& z) : zahlen(z) {}

    bool gewonnen(int gewinnzahl) override {
        for (int zahl : zahlen) {
            if (zahl == gewinnzahl) {
                return true;
            }
        }
        return false;
    }
};

class FarbeSpiel : public RouletteSpiel {
private:
    int farbe;

public:
    FarbeSpiel(int f) : farbe(f) {}

    bool gewonnen(int gewinnzahl) override {
        return ((farbe == 2 && gewinnzahl % 2 == 1) || (farbe == 1 && gewinnzahl % 2 == 0));
    }
};

class GeradeUngeradeSpiel : public RouletteSpiel {
private:
    int geradeUngerade;

public:
    GeradeUngeradeSpiel(int gu) : geradeUngerade(gu) {}

    bool gewonnen(int gewinnzahl) override {
        return ((geradeUngerade == 1 && gewinnzahl % 2 == 0) || (geradeUngerade == 2 && gewinnzahl % 2 == 1));
    }
};

class BereichSpiel : public RouletteSpiel {
private:
    int bereich;

public:
    BereichSpiel(int b) : bereich(b) {}

    bool gewonnen(int gewinnzahl) override {
        return ((bereich == 1 && gewinnzahl >= 1 && gewinnzahl <= 18) || (bereich == 2 && gewinnzahl >= 19 && gewinnzahl <= 36));
    }
};

class DrittelSpiel : public RouletteSpiel {
private:
    int drittel;

public:
    DrittelSpiel(int dt) : drittel(dt) {}

    bool gewonnen(int gewinnzahl) override {
        if (drittel == 1)
            return (gewinnzahl >= 1 && gewinnzahl <= 12);
        else if (drittel == 2)
            return (gewinnzahl >= 13 && gewinnzahl <= 24);
        else if (drittel == 3)
            return (gewinnzahl >= 25 && gewinnzahl <= 36);
        else
            return false;
    }
};

int main() {
int guthaben =5000;

while (true) {
std::cout << "Aktuelles Guthaben: " << guthaben << std::endl;
if (guthaben <= 0) {
	std::cout << "Du hast kein Guthaben mehr. Das Spiel ist vorbei außer du gibst das Zauberwort ein." << std::endl;
	char zauberwort[15] = "Simsalabim";
	char eingabe[15];
	std::cin >> eingabe;
	if(strcmp(zauberwort, eingabe) == 0){
	std::cout << "Weiter gehts!!" << std::endl;
	guthaben = 5000;
	}
	else{
	std::cout << "Das wars! Und Tschüss!" << std::endl;
	break;
	}
}

std::cout << "Welchen Spielmodus möchtest du spielen?" << std::endl;
std::cout << "1. Eine oder mehrere Zahl setzen" << std::endl;
std::cout << "2. Auf Rot oder Schwarz setzen" << std::endl;
std::cout << "3. Auf Gerade oder Ungerade setzen" << std::endl;
std::cout << "4. Auf 1-18 oder 19-36 setzen" << std::endl;
std::cout << "5. Auf 1-12, 13-24 oder 25-36" << std::endl;
std::cout << "Wähle eine Option (1-5): ";

int spielmodus;
std::cin >> spielmodus; //Auswahl Spielmodus

int einsatz;
std::cout << "Wie viel möchtest du setzen? ";
std::cin >> einsatz; //Auswahl Einsatz

while(guthaben < einsatz){
        std::cout << "So viel Guthaben besitzen Sie nicht. Geben Sie ein geringeren Einsatz ein!" << std::endl;
	std::cin >> einsatz;
}

std::srand(static_cast<unsigned int>(std::time(nullptr)));
int gewinnzahl = std::rand() % 37;

bool gewonnen = false;
RouletteSpiel* spiel = nullptr;

int anzahl;

switch (spielmodus) {
case 1:{

        std::cout << "Auf wie viele verschiedene Zahlen möchtest du setzen? ";
	std::cin >> anzahl;
	std::vector<int> zahlen;
	for (int i = 0; i < anzahl; ++i) {
		int zahl;
		std::cout << "Gib die " << i + 1 << ". Zahl ein: ";
		std::cin >> zahl;
		while(zahl > 36){
			std::cout << "Eingabe zu hoch! Erneut eingeben!" << std::endl;
			std::cin >> zahl;
		}
		zahlen.push_back(zahl);
        }
	spiel = new ZahlSpiel(zahlen);
	break;
}
	
case 2: {
        int farbe;
        std::cout << "Auf welche Farbe möchtest du setzen (1 = Rot, 2 = Schwarz)? ";
        std::cin >> farbe;
        spiel = new FarbeSpiel(farbe);
        break;
}
	
case 3:{
	int geradeUngerade;
   	std::cout << "Möchtest du auf Gerade (1) oder Ungerade (2) setzen? ";
        std::cin >> geradeUngerade;
        spiel = new GeradeUngeradeSpiel(geradeUngerade);
        break;
}

case 4: {
        int bereich;
        std::cout << "Möchtest du auf 1-18 (1) oder 19-36 (2) setzen? ";
        std::cin >> bereich;
        spiel = new BereichSpiel(bereich);
        break;
}
	
case 5:{
	int drittel;
        std::cout << "Auf welches Drittel möchtest du setzen (1 = 1-12, 2 = 13-24, 3 = 25-36)? ";
        std::cin >> drittel;
        spiel = new DrittelSpiel(drittel);
        break;
}
default:
        std::cout << "Ungültige Option ausgewählt." << std::endl;
        continue;
}
}

gewonnen = spiel->gewonnen(gewinnzahl);
delete spiel;

 	if (gewonnen && (spielmodus == 2 || spielmodus == 3 || spielmodus == 4)) {
		guthaben += (einsatz * 2) - einsatz;
		std::cout << "Glückwunsch! Du hast gewonnen." << std::endl;
	}

        else if (gewonnen && spielmodus == 1) {
		guthaben += (einsatz/anzahl * 36) - einsatz;
		std::cout << "Glückwunsch! Du hast gewonnen." << std::endl;
        }

        else if (gewonnen && spielmodus == 5) {
		guthaben += (einsatz * 3) - einsatz;
		std::cout << "Glückwunsch! Du hast gewonnen." << std::endl;
        }

        else {
		guthaben -= einsatz;
		std::cout << "Du hast verloren." << std::endl;
	}

	if(gewinnzahl % 2 == 1){
        	std::cout << "Die Gewinnzahl lautet: +++++++ " << gewinnzahl << " schwarz +++++++" << std::endl;
        }
        else{
        	std::cout << "Die Gewinnzahl lautet: +++++++ " << gewinnzahl << " rot +++++++" << std::endl;
        }

	std::cout << "Aktualisiertes Guthaben: " << guthaben << std::endl;

	std::cout << "Möchtest du nochmal spielen? (1 = Ja, 0 = Nein) ";
        int nochmal;
        std::cin >> nochmal;

        
        if (nochmal != 1) {
            break;
        }
    }
	return 0;
}




