#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

ll n,m,u,v,w,p;

ll mtmatrix(ll n,ll r, ll c) {
    if (n==1) {
            if (r==0 && c==0) return u;
            if (r==0 && c==1) return v;
            if (r==1 && c==0) return w;
            if (r==1 && c==1) return p;
        }

        ll mid_row = 1LL << (n-1);
        ll mid_col = mid_row;

        if (r < mid_row && c < mid_col) return mtmatrix(n-1,r,c);
        if (r>=mid_row&& c < mid_col) return -mtmatrix(n-1,r-mid_row,c);
        if (r<mid_row&& c >= mid_col) return mtmatrix(n-1,c-mid_col,r);
        if (r>=mid_row&& c >= mid_col) return -mtmatrix(n-1,c-mid_col,r-mid_row);

    }


int main() {
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    while (m--) {
        ll r,c;
        cin >> r >> c;
        cout << mtmatrix(n,r-1,c-1) << endl;
    }
}