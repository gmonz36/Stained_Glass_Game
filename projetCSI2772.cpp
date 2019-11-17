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
            cout << "Ronde " << phase << endl;
            Joueur* courant=&joueurs[joueur]; // todo check rules, who starts each phase? what is the deciding factor?
            Lots lots;

            while(!lots.lotVide() or !lots.surplusVide()){
                cout << *courant << endl;
                cout << lots << endl;
                int option;
                cout << "Vos options sont : " << endl;
                cout << "(1) - Prendre des vitres d’une couleur dans l’un des lots ou dans le surplus, "
                        "puis les placer dans la colonne de votre choix a la gauche de votre position." << endl;
                if (courant->getPosition() != 6) {
                    cout << "(2) - Déplacer le vitrier à la posiiton 6 et terminer votre tour." << endl;
                }
                cout << "Entrez le numéro de l'option de votre choix : ";
                cin >> option;

                if (option == 1) {
                    char couleur;
                    int numeroLot;
                    int colonne;

                    do {
                        cout << "Choisit une couleur : ";
                        cin >> couleur;

                        cout << "Choisit un lot (entrez -1 si vous voulez choisir du surplus) : ";
                        cin >> numeroLot;

                        cout << "Choisit une colonne : ";
                        cin >> colonne;

                        try {
                            vector<char> vitres = lots.ramasseVitre(couleur, numeroLot);
                            *courant -= colonne;
                            if(colonne>courant->getPosition()){
                                throw invalid_argument("Tu ne peux pas construire un vitrail qui est à ta gauche.");
                            }
                            int pts_perdu = courant->getVitrail().construireVitrail(vitres, colonne);
                            lots.ajouteAuSurplus(pts_perdu, couleur);
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
                        }
                        catch (const invalid_argument &e) {
                            cout << e.what() << endl;
                        }
                        catch (const out_of_range &e) {
                            cout << e.what() << endl;
                        }

                    } while(true);

                } else if (courant->getPosition() != 6 and option == 2) {
                    ~(*courant);

                }
                joueur=!joueur;
                courant = &joueurs[joueur];
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
