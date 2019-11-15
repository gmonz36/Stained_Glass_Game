#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <iostream>
#include "vitrail.h"

using namespace std;

class Joueur {
private:
    std::string nom;
    int         points;
    int         position;
    Vitrail*    vitrail;
public:
    Joueur&  operator++();
    Joueur&  operator-=(const int);
    Joueur&  operator~();
};

ostream& operator<<(ostream&, const Joueur&);

#endif // JOUEUR_H