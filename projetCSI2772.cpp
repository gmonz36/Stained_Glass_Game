#include <iostream>
#include <vitrail.h>
#include <joueur.h>
#include <lots.h>


int main() {
    bool jeu = true;
    while(jeu){
        Vitrail vitrailA(7, 5);
        Vitrail vitrailB(7, 5);
        Joueur joueurA("A", &vitrailA);
        Joueur joueurB("B", &vitrailB);
        Joueur joueurs[] = {joueurA, joueurB};
        bool joueur = false;
        int phase = 1;

        while(phase!=5) {
            Joueur& courant=joueurs[joueur]; // todo check rules, who starts each phase? what is the deciding factor?
            Lots lots;

            while(!lots.lotVide() or !lots.surplusVide()){
                cout << courant << endl;
                cout << lots << endl;
                bool turn = true;
                while(turn) {
                    int option;
                    cout << "Vos options sont : " << endl;
                    cout << "(1) - Prendre des vitres d’une couleur dans l’un des lots ou dans le surplus, "
                            "puis les placer dans la colonne de votre choix a la gauche de votre position." << endl;
                    if (courant.getPosition() != 6) {
                        cout << "(2) - Déplacer le vitrier à la posiiton 6 et terminer votre tour." << endl;
                    }
                    cout << "Entrez le numéro de l'option de votre choix : " << endl;
                    cin >> option;

                    if (option == 1) {

                        char couleur;
                        int numeroLot;
                        int colonne;

                        cout << "Choisit une couleur: ";
                        cin >> couleur; // todo make sure the colour is present in the lot chosen
                        cout << "Choisit un lot: ";
                        cin >> numeroLot; //todo allow player to select the surplus pile
                        cout << "Choisit une colonne: ";
                        cin >> colonne; // todo make sure the column chosen is to the left of his current position

                        vector<char> vitres = lots.ramasseVitre(couleur, numeroLot);
                        courant -= colonne;
                        int pts = vitrailA.construireVitrail(vitres, colonne);
                        if (vitrailA.estComplete(colonne)) {
                            pts += 3;
                            for (int i = colonne - 1; i >= 0; i--) {
                                if (vitrailA.estEnConstruction(i)) {
                                    pts += 1;
                                }
                            }
                        }
                        courant.setPoints(pts);
                        turn = false;
                    } else if (courant.getPosition() != 6 and option == 2) {
                        ~courant;
                        turn = false;
                    }
                }
                joueur=!joueur;
                courant = joueurs[joueur];

            }
            phase++;
        }
        if (joueurA.getPoints() > joueurB.getPoints()){
            cout << "Joueur " << joueurA.getNom() << " est le gagnant!" << endl;
        }
        else if (joueurB.getPoints() > joueurA.getPoints()){
            cout << "Joueur " << joueurB.getNom() << " est le gagnant!" << endl;
        }
        else{
            cout << "C'est une partie égale!" << endl;

        }
        jeu = false;

    }

    return 0;
};
