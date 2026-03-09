#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n , m ,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> p(n,vector<int>(m));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> a[i][j];
        }
    }
    p[0][0]=a[0][0];
    for (int j=1 ; j <m ; j++) {
        p[0][j]=p[0][j-1]+a[0][j];
    }
    for (int i = 1 ; i <n ; i++) {
        p[i][0]=p[i-1][0]+a[i][0];
        for (int j = 1 ; j < m ; j ++) {
            p[i][j]=p[i-1][j] + p[i][j-1] - p[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 0 ; i < k ; i ++) {
        int r1,r2,c1,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        long long ans = p[r2][c2];

        if (r1 > 0)
            ans -= p[r1-1][c2];

        if (c1 > 0)
            ans -= p[r2][c1-1];

        if (r1 > 0 && c1 > 0)
            ans += p[r1-1][c1-1];

        cout << ans << "\n";
    }
}