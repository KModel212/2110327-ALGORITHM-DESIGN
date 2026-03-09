#include <iostream>
#include <vector>

using namespace std;

int maxtri(int i,int j,vector<vector<int>> &tri,vector<vector<int>> &memo) {
    if (i==1&&j==0) {
        return tri[1][0];
    }
    if (memo[i][j]!=-1) return memo[i][j];
    int best=0;
    if (j==0) best = maxtri(i-1,j,tri,memo);
    else if (j==i-1) best= maxtri(i-1,j-1,tri,memo);
    else best=max(maxtri(i-1,j,tri,memo),maxtri(i-1,j-1,tri,memo));
    int ans= tri[i][j] + best;
    memo[i][j]=ans;
    return ans;
    
}

int main() {
    int n;
    cin >> n ;
    vector<vector<int>> tri(n+1);
    vector<vector<int>> memo(n+1);
    for (int i = 1 ; i <= n ; i++) {
        tri[i].resize(i);
        memo[i].assign(i, -1);
        for (int j=0 ; j < i ; j++) cin >> tri[i][j];
    }
    int ans=0;

    for(int j = 0; j < n; j++)
        ans = max(ans, maxtri(n, j, tri, memo));

    cout << ans;

}