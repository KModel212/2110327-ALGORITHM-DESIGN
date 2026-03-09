#include <iostream>
#include <vector>

using namespace std;

const int MOD = 100000007;

int main(){
    int n;
    cin >>n ;
    vector<vector<vector<int>>> memo(n+1,vector<vector<int>>(2,vector<int>(2,0)));

    if (n==1) {
        cout << 2;
        return 0;
    }

    for (int x = 0 ; x<2 ; x ++) {
        for (int y = 0 ; y < 2 ; y++ ) {
            memo[2][x][y]=1;
        }
    }

    for (int i = 3;i<=n;i++) {
        for (int x= 0 ;x<2;x++) {
            for (int y=0;y<2;y++) {
                for (int z=0 ; z <2 ; z++) {
                    if (z==1&&y==0&&x==1) continue;
                    memo[i][y][z] = ((memo[i][y][z])%MOD+(memo[i-1][x][y])%MOD)%MOD;
                }
            }
        }
    }

    long long ans=0;

    for (int x =0 ; x <2 ; x ++) {
        for (int y = 0 ; y <2 ;y++) {
            ans=((ans)%MOD+(memo[n][x][y])%MOD)%MOD;    
        }
    }
    cout << ans;
}