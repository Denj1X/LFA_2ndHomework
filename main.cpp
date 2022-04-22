#include <bits/stdc++.h>
#include "AFN.h"
#include "AFD.h"

ifstream fin ("AFN.in");
ofstream fout ("AFD.out");
using namespace std;

int main() {
    int x, y;
    fin >> x >> y;
    AFN afn (x ,y);
    fin >> afn;
    cout << afn;
    afn.turn_into_AFD();
    return 0;
}
