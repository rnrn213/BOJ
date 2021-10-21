#include <bits/stdc++.h>

using namespace std;

vector< vector<string> > periodicTable(26);
vector<string> initialPeriodicTable = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm","Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv"};

void initPeriodicTable() {
    for (int i = 0; i < initialPeriodicTable.size(); i++) {
        initialPeriodicTable[i][0] = static_cast<char>(initialPeriodicTable[i][0] + 32);
        periodicTable[initialPeriodicTable[i][0] - 'a'].push_back(initialPeriodicTable[i]);
    }
}


bool solve(string& word) {
    if (word.size() == 0)
        return true;
    
    bool ret = false;
    for (int i = 0; i < periodicTable[word[0] - 'a'].size(); i++) {
        if (word.substr(0, periodicTable[word[0] - 'a'][i].size()) == periodicTable[word[0] - 'a'][i]) {
            string temp = word.substr(0, periodicTable[word[0] - 'a'][i].size());
            word = word.substr(periodicTable[word[0] - 'a'][i].size());
            ret = ret || solve(word);
            word = temp + word;
        }
    }
    
    return ret;
}

int main() {
    initPeriodicTable();

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        if (solve(word))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}