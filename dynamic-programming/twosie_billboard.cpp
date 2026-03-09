#include <iostream>
#include <vector>

using namespace std;

int bill(int n,int w,vector<int> &l,vector<int> &r, vector<int> &memo) {
    if(n==1)return max(l[1],r[1]);
    int ans = max(bill(n-w,w,l,r,memo)+max(l[n],r[n]);
    return ans;
}

int main() {
    int n,w,k;
    cin >> n >>w >> k; ;
    vector<int> memo(n+1,-1);
    vector<int> l(n+1),r(n+1);
    for (int i = 1 ; i <n+1 ; i++) {
        cin >> l[i];
    }
    for (int i = 1 ; i <n+1 ; i++) {
        cin >> r[i];
    }
    cout << bill(n,w,l,r,memo);

}