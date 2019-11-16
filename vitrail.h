#ifndef VITRAIL_H
#define VITRAIL_H

#include <vector>
#include <iostream>

using namespace std;

class Vitrail {
    int nb_cols;
    int nb_vitres;
    char **vitrail;

    public:

        Vitrail(int, int);
        ~Vitrail();
        int construireVitrail(std::vector<char>, int);
        bool estComplete(int);
        bool estEnConstruction(int);

    int getNbCols() const;

    int getNbVitres() const;

    char ** getVitrail() const;
};

ostream& operator<<(ostream&, const Vitrail&) ;


#endif // VITRAIL_H