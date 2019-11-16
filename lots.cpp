#include <iostream>
#include "lots.h"

using namespace std;

char** Lots::getLot() const {return lot;}
vector<char> Lots::getSurplus() const { return surplus;}

Lots::Lots() {
    char couleurs[] = {'G','J','B','O','R'};
    lot = new char *[5];
    for(int i = 0; i<5; i++){
        lot[i] = new char[4];
        for(int j = 0; j<4; j++){
            lot[i][j]= couleurs[random()%5];;
        }
    }
}

vector<char> Lots::ramasseVitre(char couleur, int numeroLot) {
    vector<char> vitres;
    if(numeroLot>0 and numeroLot<=5) {
        if(lot[numeroLot][0]=='.') throw invalid_argument("On ne peut pas sélectionner un lot vide.");
        for(int i=0;i<4;i++) {
            if(couleur == lot[numeroLot][i]) {
                vitres.push_back(lot[numeroLot][i]);
                lot[numeroLot][i] = '.';
            } else {
                surplus.push_back(lot[numeroLot][i]);
                lot[numeroLot][i] = '.';
            }
        }
    } else if(numeroLot<0) {
        vector<char> tmp;
        for(char vitre: surplus) {
            if(couleur==vitre) vitres.push_back(vitre);
            else tmp.push_back(vitre);
        }
        surplus = tmp;
    } else throw out_of_range("Le numéro de lot sélectionné ne peut pas être supérieure à 5.");
    return vitres;
}

void Lots::reset() {
    char couleurs[] = {'G','J','B','O','R'};
    for(int i = 0; i<5; i++){
        for(int j = 0; j<4; j++){
            lot[i][j]= couleurs[random()%5];;
        }
    }
}

ostream& operator<<(ostream& gauche, const Lots& droit) {
    for(int i = 0; i<4; i++){
        for(int j = 0; j<5; j++){
            gauche << droit.getLot()[j][i] << "    ";
        }
        gauche << endl;
    }

    for(int i = 4; i>=0; i--){
        gauche << i << "    ";
    }
    gauche << endl;

    gauche << "Surplus:" << endl;
    gauche << "[ ";
    for (auto c: droit.getSurplus()) std::cout << c << ' ';
    gauche << "]" << endl;

    return gauche;
}


Lots::~Lots() {
    for(int i = 0; i<4; i++){
        delete[] lot[i];
    }
    delete[] lot;
}