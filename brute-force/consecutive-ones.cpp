#include <iostream>
using namespace std;
#include <vector>

void base2(int n,int k,vector<int>& temp,int len,bool consecutive,int keep) {
    if (len<n) {
        temp[len]=0;
        base2(n,k,temp,len+1,consecutive,0); 
        temp[len]=1;
        base2(n,k,temp,len+1,keep+1>=k||consecutive,keep+1);
    }else {
        if (consecutive) {
            for (int i=0;i<n;i++) {
                cout<< temp[i];
            }
            cout<< endl;
        }
    }
}

int main() {
    int n, k;
    cin>> n >> k;
    vector<int> temp(n);
    base2(n,k,temp,0,false,0);
}