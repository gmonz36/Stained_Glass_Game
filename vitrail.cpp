#include <iostream>
#include <vitrail.h>
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

    if(estComplete(colonne)){
        throw std::invalid_argument("La colonne choisie est deja complete!");
    }
    else{
        char colour = vitres[0];

        for(int i = 0; i<nb_vitres; i++){
            if(vitrail[colonne][i] == colour and !vitres.empty()){
                vitrail[colonne][i] = 'x';
                vitres.erase(vitres.end()-1);
            }

        }
        return vitres.size();
    }

}

bool Vitrail::estEnConstruction(int colonne) {
    for(int i = 0; i<nb_vitres; i++){
        if(vitrail[colonne][i]=='x'){
            return true;
        }
    }
    return false;
}

bool Vitrail::estComplete(int colonne) {
    for(int i = 0; i<nb_vitres; i++){
        if(vitrail[colonne][i]!='x'){
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& gauche, const Vitrail& droit) {
    for(int i = 0; i<droit.getNbVitres(); i++){ //todo change back
        for(int j = droit.getNbCols()-1; j>=0; j--){
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






