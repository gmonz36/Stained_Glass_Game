#ifndef LOTS_H
#define LOTS_H
#include <vector>
#include <iostream>

using namespace std;

class Lots {
private:
    char         lot[4][5];
    vector<char> surplus;
public:
    vector<char> ramasseVitre(char couleur, int numeroLot);
    void reset();
};

ostream& operator<<(ostream&, const Lots&);

#endif // LOTS_H