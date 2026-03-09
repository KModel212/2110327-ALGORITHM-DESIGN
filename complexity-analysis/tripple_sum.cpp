#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i =0 ; i<n ; i++) {
        int x;
        cin >> x;
        a[i]= x;
    }
    while (m--) {
        int y;
        cin >> y;
        bool found = false;
        vector<int> temp;
        for (int i =0 ; i <n ; i++) {
              int l = 0;
              int r = n-1;
            while (l<r) {
                if (i==l||r==i) break;
                if (y==a[l]+a[r]+a[i]) {
                    found =true ; 
                    break;
            }
            if (y<a[l]+a[r]+a[i]) r--;
            if (y>a[l]+a[r]+a[i]) l++;
        }
        }
        if (found) cout << "YES" <<endl;
        else cout << "NO" << endl;
        
    }
}