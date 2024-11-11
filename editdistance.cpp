#include "costos.hpp"

int edit_distance(string s1, string s2){
    if(s1 == s2) return 0;
    else {
        vector <vector <int> > matrix(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        initMatrix(matrix, s1, s2);
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                int del = matrix[i-1][j] + costo_del(s1[i-1]),
                    sub = matrix[i-1][j-1] + costo_sub(s1[i-1], s2[j-1]),
                    ins = matrix[i][j-1] + costo_ins(s2[j-1]);

                matrix[i][j] = min(del, min(sub, ins));
                if(i > 1 && j > 1 && s1[i-1] == s2[j-2] && s1[i-2] == s2[j-1]){
                    matrix[i][j] = min(matrix[i][j], matrix[i-2][j-2] + costo_trans(s1[i-1], s1[i-2]));
                }
            }
        }
        /*
        cout << "    ";
        for(char s: s2) cout << s << " ";
        cout << "\n";
        for(int i = 0; i < matrix.size(); i++){
            if(i) cout << s1[i-1] << " "; else cout << "  ";
            for(int j = 0; j < matrix[0].size(); j++){
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }*/
        return matrix[matrix.size()-1][matrix[0].size()-1];
    }
}

int main(){
    Replace(); Insert(); Delete(); Transpose();
    //printMatrix(cost_replace);
    //cout << "\n";
    //for(int i = 0; i < cost_delete.size(); i++) cout << cost_delete[i] << " ";
    //cout << "\n\n";
    //for(int i = 0; i < cost_insert.size(); i++) cout << cost_insert[i] << " ";
    //cout << "\n\n";
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << edit_distance(s1, s2) << "\n";
    return 0;
}