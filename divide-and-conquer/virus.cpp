#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_divoc(vector<int>& rna,int start,int stop) {
    if (stop-start==2) {
        if (rna[start]==0&&rna[stop-1]==1) {
            return true; 
        } else return false;
    }
    vector<int> revrna = rna;
    reverse(revrna.begin()+start,revrna.begin()+(start+((stop-start)/2)));
    if (is_divoc(rna,start+((stop-start+1)/2),stop)) return is_divoc(rna,start,start+((stop-start+1)/2)) || is_divoc(revrna,start,start+((stop-start+1)/2));
    return false;
}

int main() {
    int n,k;
    cin >> n >> k;
    while (n--) {
        vector<int> rna(pow(2,k));
        for (int i =0 ; i<rna.size() ;i++) {
            int x;
            cin >> x;
            rna[i]=x;
        }
        if (is_divoc(rna,0,pow(2,k))) cout << "yes" << "\n" ;
        else cout << "no" << "\n" ;
    }
}