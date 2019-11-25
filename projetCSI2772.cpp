#include <iostream>
#include <vitrail.h>
#include <joueur.h>
#include <lots.h>
using namespace std;

int main() {
    Vitrail vitrailA(7, 5);
    Vitrail vitrailB(7, 5);
    Joueur joueurA("A", &vitrailA);
    Joueur joueurB("B", &vitrailB);
    Joueur joueurs[] = {joueurA, joueurB};
    bool joueur = false;
    int phase = 1;
    Lots lots;

    while(phase<6) {
        cout << "Ronde " << phase << endl;
        Joueur* courant = &joueurs[joueur];

        while(!lots.lotVide() or !lots.surplusVide()){
            cout << *courant << endl;
            cout << lots     << endl;
            int option;

            if((courant->getVitrail()).doitRepositionner(courant->getPosition())) {
                option = 2;
                cout << "Votre vitrier est replacé à la position 6 pour que vous puissiez construire à nouveau." << endl;
            }
            else if (courant->getPosition() == 6) {
                option = 1;
                cout << "Veuillez prendre des vitres d’une couleur dans l’un des lots ou dans le surplus, "
                        "puis les placer dans la colonne de votre choix a la gauche de votre position." << endl;
            }
            else {
                bool optionValide = false;
                while(!optionValide) { // Le jeu redemande au joueur de choisir une option jusqu'à ce quelle soit valide
                    string input_option;
                    cout << "Vos options sont : " << endl;
                    cout << "(1) - Prendre des vitres d’une couleur dans l’un des lots ou dans le surplus, "
                            "puis les placer dans la colonne de votre choix a la gauche de votre position." << endl;
                    cout << "(2) - Déplacer le vitrier à la position 6 et terminer votre tour." << endl;
                    cout << "Entrez le numéro de l'option de votre choix : ";
                    getline(cin, input_option); // getline est utilisé pour éviter des erreurs s'il y a plusieurs input ou un input vide
                    try {
                        if( input_option.size()>1) throw -1; //l'option ne devrait être qu'un seul chiffre donc un seul charactère
                        option = input_option[0] - '0'; //transforme le input en un int
                        if( (option==1) || (option==2)) optionValide = true;
                        else throw -1; // Toute autre option que 1 ou 2 est invalide et est considéré comme une exception
                    } catch(...) {
                        cout << "Tu n'as pas choisi une option valide." << endl;
                    }
                }
            }

            if (option == 1) {
                char couleur;
                int numeroLot;
                int colonne;

                do {
                    bool validInputs = false;
                    while(!validInputs) { // Le jeu redemande au joueur de choisir des options jusqu'à ce quelles soient tous valides
                        validInputs = true;

                        string input_couleur;
                        cout << "Choisit une couleur : ";
                        getline(cin, input_couleur);

                        string input_numeroLot;
                        cout << "Choisit un lot (entrez -1 si vous voulez choisir du surplus) : ";
                        getline(cin, input_numeroLot);

                        string input_colonne;
                        cout << "Choisit une colonne : ";
                        getline(cin, input_colonne);

                        try {
                            // Les input du joueur devraient avoir une taille de un caractère car il doit insérer des chiffres entre 0 et 6
                            // Dans le cas du numéro du lot, il peut avoir 2 caractères seulement si c'est -1
                            if( input_colonne.size()>1 || input_numeroLot.size()>2 || input_couleur.size()>1 ||
                                (input_numeroLot.size()==2 && input_numeroLot!="-1")) throw -1;
                            couleur   = input_couleur[0];
                            if(input_numeroLot.size()==1) numeroLot = input_numeroLot[0] - '0';
                            else numeroLot = -1;
                            colonne   = input_colonne[0] - '0';
                        } catch(...) {
                            cout << "Tu n'as pas fourni des options valides." << endl;
                            validInputs = false;
                        }
                    }

                    try {
                        if(colonne>courant->getPosition()){
                            throw invalid_argument("Tu ne peux pas construire un vitrail qui est à ta gauche.");
                        }
                        vector<char> vitres = lots.ramasseVitre(couleur, numeroLot);
                        *courant -= colonne;
                        int pts_perdu = courant->getVitrail().construireVitrail(vitres, colonne);
                        if(numeroLot>0) lots.ajouteAuSurplus(pts_perdu, couleur); //ajoute vitres non-utilisées au surplus
                                                                                  // à moins qu'elles ne viennent du surplus
                        int pts = 0;
                        if (courant->getVitrail().estComplete(colonne)) {
                            pts += 3;
                            for (int i = colonne - 1; i >= 0; i--) {
                                if (courant->getVitrail().estEnConstruction(i)) {
                                    pts += 1;
                                }
                            }
                        }
                        courant->setPoints(pts-pts_perdu);
                        cout << *courant << endl;
                        cout << lots << endl;
                        break;
                    } catch (const invalid_argument &e) {
                        cout << e.what() << endl;
                    } catch (const out_of_range &e) {
                        cout << e.what() << endl;
                    }
                } while(true);

            } else if (option == 2) {
                ~(*courant);
            }
            if(courant->getVitrail().estComplete()) {
                cout << "Ton vitrail est complété!" << endl;
                phase = 6;
                break;
            }
            joueur  = !joueur;
            courant = &joueurs[joueur];
        }
        lots.reset();
        if(++phase > 5) { cout << "Fin de la partie!" << endl;}
    }
    if (joueurs[0].getPoints() > joueurs[1].getPoints()){
        cout << "Joueur " << joueurs[0].getNom() << " est le gagnant!" << endl;
    } else if (joueurs[1].getPoints() > joueurs[0].getPoints()){
        cout << "Joueur " << joueurs[1].getNom() << " est le gagnant!" << endl;
    } else{
        cout << "C'est une partie égale!" << endl;
    }

    return 0;
};
