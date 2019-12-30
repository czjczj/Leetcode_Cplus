/*
* Author:czj
* Time  :2019/12/27 22:17
* Email :zj_cheng@csu.edu.cn
*/
/**
 * 这是一道不算太难的题目，知需要按照题目的流程，求解就可以了，第一次卡在了  vis[]的赋值先后的问题上，导致了些许错误
 */
#include <iostream>
#include <algorithm>
using namespace std;

int a[14][4];
int cnt[14];
bool vis[14][4];
int main(){
    char c;
    for(int i=1; i<14; i++)
        for(int j=0; j<4; j++){
            cin>>c;
            if(c>='2' && c<='9')
                a[i][j] = (c-'0');
            else if(c=='0')
                a[i][j] = 10;
            else if(c=='A')
                a[i][j] = 1;
            else if(c=='J')
                a[i][j] = 11;
            else if(c=='Q')
                a[i][j] = 12;
            else
                a[i][j] = 13;
        }
    for(int i=0; i<4; i++){
        int x = a[13][i];
        while(x != 13){
            cnt[x]++;
            for(int j=3; j>=0; j--){
                if(vis[x][j]) continue;
                vis[x][j] = true;
                x = a[x][j];
                break;
            }
            //cout<<x<<endl;
        }
    }

    int res = 0;
    for(int i=1; i<14; i++){
        if(cnt[i] == 4)
            res++;
    }
    cout<<res;
    return 0;
}

