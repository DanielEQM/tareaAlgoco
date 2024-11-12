#include "costos.hpp"

int costo = INT_MAX;

void fuerzaBruta(string s1, string s2, int valor){
    if(s1.size() == 0){
        for(int i = 0; i < s2.size(); i++){
            valor += costo_ins(s2[i]);
        }
        costo = min(costo, valor);
    } else if(s2.size() == 0){
        for(int i = 0; i < s1.size(); i++){
            valor += costo_del(s1[i]);
        }
        costo = min(costo, valor);
    } else {
        fuerzaBruta(s1.substr(1), s2.substr(1), valor + costo_sub(s1[0], s2[0]));
        fuerzaBruta(s1, s2.substr(1), valor + costo_ins(s2[0]));
        fuerzaBruta(s1.substr(1), s2, valor + costo_del(s1[0]));
        
        if(s1.size() > 1 && s2.size() > 1){
            if(s1[1] == s2[0] && s1[0] == s2[1]){
                swap(s1[0], s1[1]);
                fuerzaBruta(s1.substr(1), s2.substr(1), valor + costo_trans(s1[1], s1[0]));
                swap(s1[0], s1[1]);
            }
        }
    }
}


int main(){
    Insert(); Delete(); Transpose(); Replace();
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    fuerzaBruta(s1, s2, 0);
    cout << costo << "\n";
    return 0;
}