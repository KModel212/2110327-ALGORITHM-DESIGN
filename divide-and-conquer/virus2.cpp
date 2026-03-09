#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


pair<bool,int> is_divoc20(vector<int>& rna,int start,int stop) {
    if (stop-start==2) {
        if ((rna[start]==0&&rna[stop-1]==1) || (rna[start]==1&&rna[stop-1]==0 ) ) {
            return {true,1}; 
        } else if ((rna[start]==0&&rna[stop-1]==0)) return {true,0}; 
        else if (rna[start]==1&&rna[stop-1]==1) return {true,2};
    }
    
    auto r = is_divoc20(rna,start+((stop-start+1)/2),stop);
    auto l = is_divoc20(rna,start,start+((stop-start+1)/2));
    if (l.first==false||r.first==false||abs(l.second-r.second)>1) {
            return {false,l.second+r.second};
        } else return {true,l.second+r.second};
    return {false,l.second+r.second};
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
        if (is_divoc20(rna,0,pow(2,k)).first) cout << "yes" << "\n" ;
        else cout << "no" << "\n" ;
    }
}