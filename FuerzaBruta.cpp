#include "costos.hpp"

int costo = INT_MAX;

void fuerzaBruta(string s1, string s2, int valor){
    /*
    * Nombre: fuerzaBruta.
    * Parametros:
    *   * string s1: string a modificar.
    *   * string s2: string objetivo.
    *   * int valor: costo acumulado.
    * Descripción:
    *   Recorre recursivamente las palabras operación por operación hasta
    *   encontrar algún string vacio para ver el minimo.
    */
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
                fuerzaBruta(s1.substr(2), s2.substr(2), valor + costo_trans(s1[1], s1[0]));
                swap(s1[0], s1[1]);
            }
        }
    }
}


int main(){
    Insert(); Delete(); Transpose(); Replace();
    string s1, s2;
    cout << "Palabra a modificar: ";
    getline(cin, s1);
    cout << "Palabra objetivo: ";
    getline(cin, s2);
    fuerzaBruta(s1, s2, 0);
    cout << "\nDistancia de Edición minima: " << costo << "\n";
    return 0;
}