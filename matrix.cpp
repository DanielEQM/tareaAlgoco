#include <bits/stdc++.h>
using namespace std;

void base_case2(){
    ofstream salida;
    salida.open("data/cost_replace.txt");
    srand(time(0));
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) salida << 0 << " ";
            else salida << rand() % 9 + 1<< " ";
        }
        salida << "\n";
    }
    salida.close();
    salida.open("data/cost_delete.txt");
    for(int i = 0; i < 26; i++){
        salida << rand() % 9 + 1 << " ";
    }
    salida.close();
    salida.open("data/cost_insert.txt");
    for(int i = 0; i < 26; i++){
        salida << rand() % 9 + 1 << " ";
    }
    salida.close();
    salida.open("data/cost_transpose.txt");
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) salida << 0 << " ";
            else salida << rand() % 9 + 1 << " ";
        }
        salida << "\n";
    }
    salida.close();
}

void base_case(){
    ofstream salida;
    salida.open("data/cost_replace.txt");
    srand(time(0));
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) salida << 0 << " ";
            else salida << 1 << " ";
        }
        salida << "\n";
    }
    salida.close();
    salida.open("data/cost_delete.txt");
    for(int i = 0; i < 26; i++){
        salida << 1 << " ";
    }
    salida.close();
    salida.open("data/cost_insert.txt");
    for(int i = 0; i < 26; i++){
        salida << 1 << " ";
    }
    salida.close();
    salida.open("data/cost_transpose.txt");
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(i == j) salida << 0 << " ";
            else salida << 1 << " ";
        }
        salida << "\n";
    }
    salida.close();
}

int main(){
    base_case();
    //base_case2();
    return 0;
}