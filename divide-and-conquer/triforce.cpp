#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int triforce(vector<vector<int>>& ingr,pair<int,int> start,int n) {
    if (n==2) {
        if (ingr[start.first+1][start.second+1]!=0) return 0;
        else if (ingr[start.first][start.second]==0||ingr[start.first][start.second+1]==0||ingr[start.first+1][start.second]==0) return 0;
        else if (ingr[start.first][start.second]==ingr[start.first][start.second+1]) return ingr[start.first][start.second];
        else if (ingr[start.first][start.second+1]==ingr[start.first+1][start.second]) return ingr[start.first][start.second+1];
        else if (ingr[start.first][start.second]==ingr[start.first+1][start.second]) return ingr[start.first+1][start.second];
        else return 0; 
    } else {
        int m = n/2;
        bool not_triforce = false;
        for (int i=start.first+m ; i<start.first+n ; i++) {
            for (int j=start.second+m ; j <start.second+n ; j++) {
                if (ingr[i][j] != 0) {
                    return 0;
                }
        }
        }
        auto a = triforce(ingr,{start.first,start.second},m);
        auto b = triforce(ingr,{start.first,start.second+m},m);
        auto c = triforce(ingr,{start.first+m,start.second},m);
        if (a==0||b==0||c==0) return 0;
        if (a==b) return a;
        else if (b==c) return b;
        else if (c==a) return c;
        else return 0; 
    }

}

int main(){
    for (int l=0;l<3;l++) {
        int n;
        cin >> n;
        vector<vector<int>> ingr(n,vector<int>(n));
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j <n ; j++) {
                cin >> ingr[i][j];
            }
        }
        int m =n/2;
        bool not_triforce = false;
        cout << triforce(ingr,{0,0},n) << endl;

    }
}