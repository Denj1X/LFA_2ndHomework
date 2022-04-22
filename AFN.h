#ifndef AFN_H_INCLUDED
#define AFN_H_INCLUDED

#include <bits/stdc++.h>
#include "AFD.h"

class AFN {
private:
    vector < vector < set < int > > > transition; //Functia de tranzitie
    char* a; // Alfabetul de intrare
    bool* f; // Multimea Starilor Finale
    int nq; // Numarul de stari
    int na; // Numarul de cuvinte din alfabet
    int nt; // Numarul funtiilor de trazitie
public:
    AFN(const int& x, const int& y);
    virtual ~AFN();
    AFD& turn_into_AFD ( );
    friend std::istream& operator>>(std::istream& in,AFN& afn);
    friend std::ostream& operator<<(std::ostream& out,AFN& afn);
};

#endif // AFN_H_INCLUDED
