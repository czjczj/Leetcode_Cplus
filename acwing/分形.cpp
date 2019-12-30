/*
* Author:czj
* Time  :2019/12/28 14:01
* Email :zj_cheng@csu.edu.cn
*/
/**
 * 加上了快速幂才不超时。
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

char m[730][730];

int power(int a, int b){
    int res = 1;
    while(b){
        if(b&1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void f(int n, int x, int y){
    if(n == 1){
        m[x][y] = 'X';
        return;
    }
    int len = power(3, n-2);
    f(n-1, x, y);
    f(n-1, x+len, y+len);
    f(n-1, x+2*len, y);
    f(n-1, x, y+2*len);
    f(n-1, x+2*len, y+2*len);
}
int main(){
    int c;
    cin>>c;
    while(c != -1){
        memset(m,' ',sizeof m);
        f(c,0,0);
        for(int i=0; i<power(3,c-1); i++){
            for(int j=0; j<power(3,c-1); j++){
                cout<<m[i][j];
            }
            cout<<endl;
        }
        cin>>c;
        cout<<"-"<<endl;
    }
    return 0;
}