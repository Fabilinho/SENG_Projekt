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


std::cout << "Welchen Spielmodus möchtest du spielen?" << std::endl;
std::cout << "1. Eine oder mehrere Zahl setzen" << std::endl;
std::cout << "2. Auf Rot oder Schwarz setzen" << std::endl;
std::cout << "3. Auf Gerade oder Ungerade setzen" << std::endl;
std::cout << "4. Auf 1-18 oder 19-36 setzen" << std::endl;
std::cout << "5. Auf 1-12, 13-24 oder 25-36" << std::endl;
std::cout << "Wähle eine Option (1-5): ";

std::srand(static_cast<unsigned int>(std::time(nullptr)));
int gewinnzahl = std::rand() % 37;

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
	

	return 0;
}




