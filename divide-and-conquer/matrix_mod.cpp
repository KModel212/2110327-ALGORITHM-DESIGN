#include <iostream>
#include <vector>

using namespace std;

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k)  {
    vector<int> tmp(4);
    tmp[0]=(((M[0]%k)*(N[0]%k))%k+((M[1])%k*(N[2])%k)%k)%k;
    tmp[1]=(((M[0]%k)*(N[1]%k))%k+((M[1])%k*(N[3])%k)%k)%k;
    tmp[2]=(((M[2]%k)*(N[0]%k))%k+((N[2])%k*(M[3])%k)%k)%k;
    tmp[3]=(((M[2]%k)*(N[1]%k))%k+((M[3])%k*(N[3])%k)%k)%k;
    return tmp;

}

vector<int> matdiv(vector<int> &mat,int k) {
    mat[0]%=k;
    mat[1]%=k;
    mat[2]%=k;
    mat[3]%=k;
    return mat;
}


vector<int> matmod(vector<int>& mat,int n,int k) {
    if (n==1) {
        return matdiv(mat,k);
    }
    if (n%2==0) {
        vector<int> tmp = matmod(mat,n/2,k);
        return matrix_multiply(tmp,tmp,k);
    } else {
        vector<int> tmp = matmod(mat,n/2,k);
        return matrix_multiply(matrix_multiply(tmp,tmp,k),matdiv(mat,k),k);
    }
}

int main() {
    int n,k,a,b,c,d;
    vector<int> mat(4);
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    mat[0]=a; mat[1]=b; mat[2]=c; mat[3]=d;
    vector<int> ans = matmod(mat,n,k);
    for (auto x : ans) {
        cout << x << " ";
    }
}