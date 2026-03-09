#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>f

using namespace std;
using ll = long long;

ll snap(vector<ll>& pos,ll I,ll A,ll B,ll start,ll stop) {
        ll m = upper_bound(pos.begin(), pos.end(), stop)
          - lower_bound(pos.begin(), pos.end(), start);
          
        if (m == 0) return A;
        if (start==stop) return B*m*1;
        
        ll l = snap(pos,I/2,A,B,start,(start+stop)/2);
        ll r = snap(pos,I/2,A,B,(start+stop)/2+1,stop);

        return min(l+r,B*I*m);
}

int main(){
    int p,k,A,B;
    cin >> p >> k >> A >> B;
    vector<ll> avpos(k);
    for (int i =0 ; i <k ; i++) {
        cin >> avpos[i];
    }
    sort(avpos.begin(),avpos.end());

    auto ans = snap(avpos,pow(2,p),A,B,1,pow(2,p));
    cout <<ans << endl;

}