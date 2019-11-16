#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <iostream>
#include "vitrail.h"

using namespace std;

class Joueur {
private:
    string   nom;
    int      points;
    int      position;
    Vitrail* vitrail;
public:
    Joueur(string, Vitrail*);
    string   getNom()      const;
    int      getPoints()   const;
    void    setPoints(int);
    int      getPosition() const;
    Vitrail& getVitrail()  const;

    Joueur&  operator--();
    Joueur&  operator-=(const int);
    Joueur&  operator~();
};

ostream& operator<<(ostream&, const Joueur&);

#endif // JOUEUR_H