#include "costos.hpp"

int costo = 1000000;
int valor = 0;

void fuerzaBruta(string s1, string s2){
    int aux = 0;
    if(s1.size() == 0){
        for(int i = 0; i < s2.size(); i++){
            aux += costo_ins(s2[i]);
        }
        costo = min(costo, valor + aux);
    } else if(s2.size() == 0){
        for(int i = 0; i < s1.size(); i++){
            aux += costo_del(s1[i]);
        }
        costo = min(costo, valor + aux);
    } else if(s1 == s2){
        costo = min(costo, valor);
    } else {
        valor += costo_sub(s1[0], s2[0]);
        fuerzaBruta(s1.substr(1), s2.substr(1));
        valor -= costo_sub(s1[0], s2[0]);

        valor += costo_ins(s2[0]);
        fuerzaBruta(s1, s2.substr(1));
        valor -= costo_ins(s2[0]);

        valor += costo_del(s1[0]);
        fuerzaBruta(s1.substr(1), s2);
        valor -= costo_del(s1[0]);

        
        if(s1.size() <= 2 && s2.size() <= 2){
            if(s1[1] == s2[0] && s1[0] == s2[1]){
                valor += costo_trans(s1[0], s1[1]);
                swap(s1[0], s1[1]);
                fuerzaBruta(s1.substr(1), s2.substr(1));
                swap(s1[0], s1[1]);
                valor -= costo_trans(s1[0], s1[1]);
            }
        }
    }
}



int main(){
    Insert(); Delete(); Transpose(); Replace();
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    fuerzaBruta(s1, s2);
    cout << costo << "\n";
    return 0;
}