#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<vector<int>>> mem(n+1,vector<vector<int>>(3,vector<int>(3)));

    if(n == 1){
        cout << 3;
        return 0;
    }

    for (int x = 0 ; x <3 ; x++) {
        for (int y = 0 ; y<3;y++) {
            if((x==1&&y==2)||(x==2&&y==1)) continue;
            mem[2][x][y]=1;
        }
    }



        for (int i = 3 ; i <= n ; i ++) {
            for (int x = 0 ; x <3 ; x++) {
                for (int y = 0 ; y<3;y++) {
                    for (int z=0; z<3;z++) {
                        if(z==2&&(x==1||y==1)) continue;
                        if (z==1&&(x==2||y==2)) continue;
                        mem[i][y][z]=(mem[i][y][z]+mem[i-1][x][y])%MOD;
                    }
                }
            }
        }

        long long ans=0;

        for (int x = 0 ; x <3 ; x++) {
            for (int y = 0 ; y<3;y++) {
                ans= (ans+(mem[n][x][y])%MOD)%MOD;
            }
        }



        cout << ans;



}