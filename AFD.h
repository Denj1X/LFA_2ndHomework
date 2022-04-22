#ifndef AFD_H_INCLUDED
#define AFD_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

class AFD {
public:
    AFD();
    AFD(const int& x, const int& y);
    virtual ~AFD();
    AFD(const AFD& afd); //ctor copiere
    AFD& operator=(const AFD& afd); //supraincarcare =
    bool check_word (char c[]);
    friend std::ostream& operator << (ostream& out, AFD& afd);
    vector < vector < int > >  transition ;
    char* a; // Alfabetul de intrare
    bool* f; // Multimea Starilor Finale
    int nq; // Numarul de stari
    int na; // Numarul de cuvinte din alfabet
    int nt; // Numarul funtiilor de trazitie
};

#endif // AFD_H_INCLUDED
