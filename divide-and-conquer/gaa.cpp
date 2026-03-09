#include <iostream>
#include <vector>

using namespace std;

vector<int> len(60);


char solve(int k,int n) {
    if (k==0) {
        if (n==1) return 'g';
        else return 'a';
    }

    if (n<=len[k-1]) return solve(k-1,n);  
    else if (n>len[k-1]+k+3) return solve(k-1,n-(len[k-1]+k+3));  
    else if (n==len[k-1]+1) return 'g'; 
    else return 'a';

}

int main () {
    int n;
    cin>> n;
    int k =0;
    len[k]=3;
    while (n>len[k]) {
        k++;
        len[k]=2*len[k-1]+k+3;
    }
    cout << solve(k,n) << endl;
}