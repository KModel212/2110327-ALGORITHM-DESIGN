#include <iostream>
#include <vector>

using namespace std;

int futo(int l,int r,vector<int> &a,vector<vector<int>> &memo) {
    if (l > r) return 0;
    if (l + 1 == r) return max(a[l], a[r]);
    if (memo[r][l]!=-1) return memo[r][l];
    int ans = max(futo(l,r-2,a,memo)+max(a[r],a[r-1]),max(futo(l+2,r,a,memo)+max(a[l],a[l+1]),futo(l+1,r-1,a,memo)+max(a[l],a[r])));
    memo[r][l] = ans;
    return ans;
}

int main() { 
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> memo(n,vector<int>(n,-1));
    for (int i = 0 ; i <n ; i++) {
        cin >> a[i];
    }
    cout << futo(0,n-1,a,memo);
}