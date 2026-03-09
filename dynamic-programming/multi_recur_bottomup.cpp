#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    vector<vector<int>> b(n-k);
    vector<int> ans(n+1);
    for (int i =0 ; i < k ; i++) {
        cin >> a[i];
    }
    for (int i = 0 ; i <n-k; i ++) {
        int p;
        cin >> p;
        b[i].resize(p);
        for (int j = 0 ; j <p ; j++) {
            cin >> b[i][j];
        }

    }
    ans[0]=0;
    for (int i = 1 ; i <=k ; i ++) {
        ans[i]=a[i-1]; 
    }
    for (int i =k+1 ; i <=n ; i ++) {
        long long a =0;
        for (int j = 0 ; j <  b[i-k-1].size() ; j ++) {
            if (i - b[i-k-1][j] > 0) a=(a+(ans[i - b[i-k-1][j]])%32717)%32717;
        }
        ans[i]=a;
    }
    for (int i = 1 ; i <= n ; i++) {
        cout << ans[i] << " ";
    }
}