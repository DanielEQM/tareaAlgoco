#ifndef FUNTION_HPP
#define FUNTION_HPP
#include <bits/stdc++.h>
using namespace std;

vector<vector <int> > cost_replace(26, vector<int>(26));
vector <int> cost_delete(26);
vector <int> cost_insert(26);
vector<vector <int> > cost_transpose(26, vector<int>(26));

void Replace(){
    ifstream entrada;
    entrada.open("data/cost_replace.txt");
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            entrada >> cost_replace[i][j];
        }
    }
    entrada.close();
}

void Delete(){
    ifstream entrada;
    entrada.open("data/cost_delete.txt");
    for(int i = 0; i < 26; i++){
        entrada >> cost_delete[i];
    }
    entrada.close();
}

void Insert(){
    ifstream entrada;
    entrada.open("data/cost_insert.txt");
    for(int i = 0; i < 26; i++){
        entrada >> cost_insert[i];
    }
    entrada.close();
}

void Transpose(){
    ifstream entrada;
    entrada.open("data/cost_transpose.txt");
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            entrada >> cost_transpose[i][j];
        }
    }
    entrada.close();
}


#endif