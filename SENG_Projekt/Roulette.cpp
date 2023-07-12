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



switch (spielmodus) {
case 3: {
	int geradeUngerade;
   	std::cout << "Möchtest du auf Gerade (1) oder Ungerade (2) setzen? ";
        std::cin >> geradeUngerade;
        spiel = new GeradeUngeradeSpiel(geradeUngerade);
        break;
        }

	

	return 0;
}


