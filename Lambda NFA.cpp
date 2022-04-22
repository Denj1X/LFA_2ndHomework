#include <bits/stdc++.h>

using namespace std;

int state0;

class LambdaNFA {
    typedef struct nod {
        int y, nr_transition;
        char transition;
    } NOD;
    vector<NOD> a[100];
    vector<int> final_states, cycle;
    int N, M, number_final_states, initial_state, count;
    bool word_accepted;
    ifstream fin;
    ofstream fout;
public:
    LambdaNFA();
    ~LambdaNFA();
    void read();
    int isFinalState(int);
    int numberOfStatesSameTransition(int, char);
    int solve(int, char*);
    void print();
};

LambdaNFA::LambdaNFA()
{   count = 0;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
}

LambdaNFA::~LambdaNFA()
{   fin.close();
    fout.close();
}

void LambdaNFA::read()
{              // here we read the lambda-NFA
    NOD z;
    int x;
    fin >> N >> M >> initial_state >> number_final_states;
    state0 = initial_state;
    for (int i = 0; i < number_final_states; i++)
    {   fin >> x;
        final_states.push_back(x);
    }

    for (int i = 1; i <= M; i++)
    {   fin >> x >> z.transition >> z.y;
        z.nr_transition = 0;

        a[x].push_back(z);
    }
}

int LambdaNFA::isFinalState(int x)
{
    for (int i = 0; i < (int)final_states.size(); i++)
        if (final_states[i] == x)
            return 1;

    return 0;
}

int LambdaNFA::numberOfStatesSameTransition(int state, char transition)
{
    int nr = 0;
    for (auto & i : a[state])
        if (i.transition == transition)
            nr++;
    return nr;
}

int LambdaNFA::solve(int first_state, char* word)
{
    stack<int> s;
    int primul, word_index = 0, j, k, word_length = strlen(word), good_to_push;

    s.push(first_state);
    while (s.empty() == 0 && !word_accepted)
    {
        primul = s.top();
        k = 0;

        good_to_push = 1;
        int modified_k = 0;
        int same_transition[1000], nr_same_transition = -1; // practic e same transition si/sau lambda-uri
        char simbol[1000];        // same_transition means nodes with the same transition

        for (int l = 0; l < (int)a[primul].size() && !word_accepted; l++)
        {
            if (a[primul][l].transition == word[word_index])
            {
                nr_same_transition++;
                same_transition[nr_same_transition] = a[primul][l].y;
                simbol[nr_same_transition] = a[primul][l].transition;
                if (modified_k == 0)
                    k = 1;
            }
            else
            if (a[primul][l].transition == '0')
            {
                nr_same_transition++;
                same_transition[nr_same_transition] = a[primul][l].y;
                simbol[nr_same_transition] = a[primul][l].transition;

                k = 1;
                for (int u = 0; u < (int)cycle.size(); u++)
                    if (same_transition[l] == cycle[u])
                    {
                        for (int t = 0; t < (int)cycle.size(); t++)
                            cycle.erase(cycle.begin(), cycle.end());
                        k = 0;  // to pop it from stack
                        modified_k = 1;
                    }
            }
        }

        if (nr_same_transition == -1)
            return 0;
        if (k == 1)
        {
            for (int l = 0; l <= nr_same_transition && !word_accepted; l++)
            {			//make cu a l-lea varianta din same_...
                if (strlen(word) != 0)
                {
                    if (simbol[l] != '0')
                    {
                        if (isFinalState(same_transition[l]) && strlen(word + 1) == 0)
                        {
                            word_accepted = true;
                            return 1;
                        }
                        if (!word_accepted)
                            if (solve(same_transition[l], word + 1) == 0)
                                good_to_push = 0;
                    } /* simbol[l] != '0' */
                    else
                    {
                        cycle.push_back(same_transition[l]);
                        if (isFinalState(same_transition[l]) && strlen(word) == 0)
                        {
                            word_accepted = true;
                            return 1;
                        }
                        if (!word_accepted)
                        {
                            count++;
                            if (count > 10)
                                return 0;
                            if (solve(same_transition[l], word) == 0)
                                good_to_push = 0;
                        }
                    } /* simbol[l] == '0' */
                } /* strlen(word) != 0 */

                if (good_to_push)
                    s.push(same_transition[l]);
                if (isFinalState(same_transition[l]) && strlen(word) == 0)
                {
                    word_accepted = true;
                    return 1;
                }
            } /* for */
        } /* k == 1 */
        else
        {
            s.pop();
            if (modified_k == 1)
                return 0;
        }
    }
    return 0;
}





void LambdaNFA::print()
{   int number_of_words;
    char* s;
    s = new char[10];
    fin >> number_of_words;
    for (int i = 1; i <= number_of_words; i++)
    {   fin >> s;
        word_accepted = false;
        count = 0;
        cycle.erase(cycle.begin(), cycle.end());
        solve(state0, s);

        if (word_accepted)
           fout << "The word " << s << " is accepted by the NFA.\n";
        else
            fout << "The word " << s << " is not accepted by the NFA.\n";
    }
    delete [] s;
}

int main()
{   LambdaNFA nfa;
    nfa.print();
    return 0;
}
