#include <iostream>
#include "joueur.h"

Joueur&  Joueur::operator--() {
    *this-=1;
    return *this;
}

Joueur&  Joueur::operator-=(const int n) {
    if(this->position - n < 0) throw  out_of_range("Le vitrier ne peut pas être déplacer hors des colonnes.");
    this->position-=n;
    return *this;
}

Joueur&  Joueur::operator~() {
    this->position = 6;
    return *this;
}

string   Joueur::getNom()      const {return nom;}
int      Joueur::getPoints()   const {return points;}
int      Joueur::getPosition() const {return position;}
Vitrail& Joueur::getVitrail()  const {return *vitrail;}

ostream& operator<<(ostream& gauche, const Joueur& droit) {
    gauche << "Joueur " << droit.getNom() << " " << droit.getPoints() << " points" << endl;
    gauche << "Vitrier à la position " << droit.getPosition() << "." << endl;
    gauche << "Plan :" << endl;
    gauche << droit.getVitrail() << endl;
    return gauche;
}