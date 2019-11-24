#include <iostream>
#include <algorithm>
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
    if ( (couleur!='O') && (couleur!='J') && (couleur!='R') && (couleur!='B') && (couleur!='G') ){
        throw invalid_argument("La couleur sélectionnée n'est pas valide.");
    }
    vector<char> vitres;
    if(numeroLot>=0 and numeroLot<5) {
        if(lot[numeroLot][0]=='.') throw invalid_argument("On ne peut pas sélectionner un lot vide.");
        bool couleur_valide = false;
        for(int i=0;i<4;i++) if(couleur == lot[numeroLot][i]) couleur_valide = true;
        if(!couleur_valide) throw invalid_argument("On ne peut pas sélectionner une couleur qui n'est pas dans le lot.");
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
        if (surplus.empty()){
            throw invalid_argument("On ne peut pas sélectionner le surplus car il est vide.");
        }
        if(find(surplus.begin(), surplus.end(), couleur) == surplus.end()) {
            throw invalid_argument("On ne peut pas sélectionner une couleur qui n'est pas dans le surplus.");
        }
        vector<char> tmp;
        for(char vitre: surplus) {
            if(couleur==vitre) vitres.push_back(vitre);
            else tmp.push_back(vitre);
        }
        surplus = tmp;

    }
    else{
        throw out_of_range("Le numéro de lot sélectionné ne peut pas être supérieure à 5.");
    }
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


bool Lots::lotVide() {
    for(int i = 0; i<5; i++){
        if (lot[i][0]!= '.'){
            return false;
        }
    }
    return true;
}


bool Lots::surplusVide() {
    return surplus.empty();
}



ostream& operator<<(ostream& gauche, const Lots& droit) {
    for(int i = 0; i<4; i++){
        for(int j = 4; j>=0; j--){
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

void Lots::ajouteAuSurplus(int pts_perdu, char couleur) {
    for (int i = 0; i<pts_perdu; i++){
        surplus.push_back(couleur);
    }
}
