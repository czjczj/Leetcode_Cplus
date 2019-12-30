/*
* Author:czj
* Time  :2019/12/22 08:47
* Email :zj_cheng@csu.edu.cn
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 10000000;
char g[10][10];

int dir[5][2] = {{0,0}, {0,-1}, {0,1}, {1,0}, {-1,0}};
//turn the position  (x,y)
void turn(int x, int y){
    for(int i=0; i<5; i++){
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx>=0 && nx<5 && ny>=0 && ny<5){
            g[nx][ny] ^= 1;
        }
    }
}
int work(){
    int ans = INF;
    //first row state
    for(int i=0; i< 1<<5; i++){
        int res = 0;
        char backup[10][10];
        bool flag = true;
        memcpy(backup, g, sizeof(g));

        for(int j=0; j<5; j++){
            if(i & 1<<j){
                turn(0,j);
                res++;
            }
        }

        //change next
        for(int k=0; k<4; k++){
            for(int j=0; j<5; j++){
                if(g[k][j] == '0'){
                    turn(k+1,j);
                    res++;
                }
            }
        }

        for(int j=0; j<5; j++){
            if(g[4][j] == '0'){
                flag = false;
                break;
            }
        }
        memcpy(g,backup,sizeof(backup));
        if(flag)  ans = min(ans, res);
    }
    return ans>6?-1:ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        for(int i=0; i<5; ++i){
            cin>>g[i];
        }
        cout<<work()<<endl;
    }
    return 0;
}
