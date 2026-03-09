#include <iostream>
#include <map>

using namespace std;

int main(){
   std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int N,Q;
    map<int,int> m,num;
    cin >> N >> Q;
    while (N--) {
        int x,c;
        cin >> x >> c;
        m[x]+=c;
    }
    int temp=0;
    for (auto x : m) {
        temp += x.second;
        num[temp]=x.first; 
    }
    while (Q--) {
        int p;
        cin >> p;
        auto res = num.lower_bound(p);
        if (res==num.end()) res--;
        cout << res->second << endl ;
    }
}