#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include "vitrail.h"

class Joueur {
private:
    std::string nom;
    int points;
    int position;
    Vitrail* vitrail;

};

#endif // JOUEUR_H