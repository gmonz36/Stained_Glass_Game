#include <iostream>
#include <vitrail.h>
#include <random>
using namespace std;


Vitrail::Vitrail(int nb_cols, int nb_vitres): nb_cols(nb_cols), nb_vitres(nb_vitres) {
    char couleur[] = {'G', 'J', 'B', 'R', 'O'};

    vitrail=new char *[nb_cols];
    for(int i = 0; i<nb_cols; i++){
        vitrail[i] = new char[nb_vitres];
        int index1 = random() % 5;
        int index2 = random() % 5;

        char couleur1 = couleur[index1];
        char couleur2 = couleur[index2];

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
    for(int i = 0; i<droit.getNbVitres(); i++){
        for(int j = 0; j<droit.getNbCols(); j++){
            gauche << droit.getVitrail()[j][i] << "    ";
        }
        gauche << endl;
    }

    for(int i = droit.getNbCols()-1; i>=0; i--){
        gauche << i << "    ";
    }
    gauche << endl;

    return gauche;

}






