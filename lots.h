#ifndef LOTS_H
#define LOTS_H
#include <vector>
#include <iostream>

using namespace std;

class Lots {
private:
    char**       lot;
    vector<char> surplus;
public:
    Lots();
    char** getLot() const;
    vector<char> getSurplus() const;
    vector<char> ramasseVitre(char, int);
    void reset();
    ~Lots();

    bool surplusVide();
    bool lotVide();
    void ajouteAuSurplus(int, char);
};

ostream& operator<<(ostream&, const Lots&);

#endif // LOTS_H