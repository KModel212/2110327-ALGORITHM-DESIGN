#include <iostream>
#include <map>
#include <vector>
using namespace std;

void permu(int n,int len,vector<int>& v,vector<bool>& used,map<int,int> arrg,bool correct) {
    if (len < n && correct!=false) {
        for (int i=0;i<n;i++) {
            if (used[i]==false) {
                if (arrg.find(i)!=arrg.end()) {
                    bool check=false;
                    for (int j=0;j<len;j++) {
                        if (v[j]==arrg[i]) check =true;
                    }
                    if (!check) {
                        used[i]=true;
                        v[len]=i;
                        permu(n,len+1,v,used,arrg,false);
                        used[i]=false;
                    } else {
                        used[i]=true;
                        v[len]=i;
                        permu(n,len+1,v,used,arrg,correct);
                        used[i]=false;
                    }
                } else {
                used[i]=true;
                v[len]=i;
                permu(n,len+1,v,used,arrg,correct);
                used[i]=false;
                }
            } 
        }
    } else {
        if (correct) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    map<int,int> arrg; 
    vector<int> v(n);
    vector<bool> used(n);
    while (m--) {
        int a,b;
        cin >> a >> b;
        arrg[b]=a;
    }
    permu(n,0,v,used,arrg,true);
}

