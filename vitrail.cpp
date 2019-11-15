#include <iostream>
#include <vitrail.h>
#include <random>
using namespace std;


Vitrail::Vitrail(int nb_cols, int nb_vitres): nb_cols(nb_cols), nb_vitres(nb_vitres) {
    vitrail=new char *[nb_cols];
    for(int i = 0; i<nb_cols; i++){
        vitrail[i] = new char[nb_vitres];
        auto couleur1 = static_cast<Couleur>(random()%5);
        auto couleur2 = static_cast<Couleur>(random()%5);
        int h = random() % nb_vitres + 0;
        for(int j = 0; j<=h; j++){
            vitrail[i][j]= couleur1;
        }
        for(int j = h+1; j<nb_vitres; j++){
            vitrail[i][j]= couleur2;
        }
    }



}

int Vitrail::getNbCols() const {return nb_cols;}
int Vitrail::getNbVitres() const {return nb_vitres;}
char** Vitrail::getVitrail() const {return vitrail;}

Vitrail::~Vitrail() {
    for(int i = 0; i<nb_vitres; i++){
        delete[] vitrail[i];
    }
    delete[] vitrail;
}

int Vitrail::construireVitrail(std::vector<char> vitres, int colonne) {
    return 0;
}

bool Vitrail::estEnConstruction(int colonne) {
    return false;
}

bool Vitrail::estComplete(int colonne) {
    return false;
}

ostream& operator<<(ostream& gauche, const Vitrail& droit) {
    for(int i = 0; i<droit.getNbCols(); i++){
        for(int j = 0; j<droit.getNbVitres(); j++){
            gauche << droit.getVitrail()[j][i] << endl;
        }
    }
    for(int i = droit.getNbCols()-1; i>=0; i--){
        gauche << i << endl;
    }

    return gauche;

}






