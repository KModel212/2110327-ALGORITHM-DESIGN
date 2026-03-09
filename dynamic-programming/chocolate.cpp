#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> s(k);
    vector<int> mem(n+1,0);

    mem[0]=1;

    for (int i = 0 ; i < k ; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (auto c : s) {
            if (i-c >= 0) {
            mem[i] = (mem[i] + mem[i - c])%1000003 ;
            }
        }
    }

    cout << mem[n];
}
