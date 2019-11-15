

#ifndef VITRAIL_H
#define VITRAIL_H

#include <vector>
using namespace std;

class Vitrail {
    char **vitrail;

    public:

        int construireVitrail(std::vector<char>, int);
        bool estComplete(int);
        bool estEnConstruction(int);

    };

ostream& operator<<(ostream&, const Vitrail&) ;


#endif // VITRAIL_H