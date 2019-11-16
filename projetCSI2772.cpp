#include <iostream>
#include <vitrail.h>
#include <joueur.h>
#include <lots.h>
//On vous demande donc de programmer ce jeu de façon à ce que 2 joueurs puissent y joueur en interagissant avec la console.

//Les deux instances de la classe joueur sont créées.
//Deux vitraux de 7 colonnes par 5 cases sont créées et associés à chacun des joueurs. Les lots sont créés
//Votre programme alterne alors entre les 2 joueurs.
//Le joueur choisit un lot, une couleur et une colonne. Ce qui retire les vitres du lot (méthode ramasseVitre), déplace
// le vitrier (opérateur -=), et place les vitres sur la colonne (méthode construireVitrail). Les points rapportés par
// cette action sont automatique comptés.
//Alternativement, le joueur peut simplement demander de replacer son vitrier sur la colonne de gauche (opérateur ~).
//Si un joueur tente un coup illégal, une exception est lancée et il doit proposer une autre action.
//


int main() {
    bool jeu = true;

    //phase 1

    //start game

    while(jeu){
        Vitrail vitrailA(7, 5);
        Vitrail vitrailB(7, 5);

        Joueur joueurA("Joueur A", &vitrailA);
        Joueur joueurB("Joueur B", &vitrailB);
        int phase = 0;

        while(phase!=5) {
            phase++;
            Joueur& courant=joueurA; // todo check rules, who starts each phase? what is the deciding factor?
            Lots lots; // todo check rules, does each player have a set of lots, or is it 1 per phase?


            while(!lots.lotVide() || !lots.surplusVide()){
                if (courant.getNom() == "Joueur A") {

                    //turn


                    courant = joueurB;
                } else {


                    //turn

                    courant = joueurA;
                }

            }

        }
        if (joueurA.getPoints() > joueurB.getPoints()){
            //Player A wins!
        }
        else if (joueurB.getPoints() > joueurA.getPoints()){
            //Player B wins!
        }
        else{
            //its a tie!
        }
        jeu = false;

    }





    return 0;
};
