#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> pos;
vector<int> xpos;

vector<int> pareto(int l,int r) {

    if (l==r) return {xpos[l]} ;

    int m = (l+r)/2;

    vector<int> pareleft = pareto(l,m);
    vector<int> pareright = pareto(m+1,r);

    vector<int> pareans;

    for (int i =0 ; i <pareleft.size();i++) {
        if (pos[pareleft[i]]>pos[pareright[0]]) pareans.push_back(pareleft[i]);
    }
    for (int i =0 ; i <pareright.size();i++) pareans.push_back(pareright[i]);
    
    return pareans;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x,y;
        cin >> x >> y;
        pos[x]=y;
        xpos.push_back(x);
    }
    sort(xpos.begin(),xpos.end());
    cout << pareto(0,pos.size()-1).size() << endl;
}