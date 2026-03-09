#include <iostream>

using namespace std;

int mod_expo (int x,int n,int k) {
    if (n==1) return x%k;
    if (n%2==0) {
        int tmp = mod_expo(x,n/2,k);
        return (tmp*tmp)%k;
    } else {
        int tmp = mod_expo(x,n/2,k);
        return ((tmp*tmp)%k*x%k)%k;
    }
}

int main(){
    int x,n,k;
    cin >> x >> n >> k;
    cout << mod_expo(x,n,k) << endl;
}