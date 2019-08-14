#include <iostream>
using namespace std;
int reward[6][6] = {
        {-1,-1,-1,-1,0,-1},
        {-1,-1,-1,0,-1,100},
        {-1,-1,-1,0,-1,-1},
        {-1,0,0,-1,0,-1},
        {0,-1,-1,0,-1,100},
        {-1,0,-1,-1,0,100},
};
int q[6][6];
int old[6][6];
int Max(int s){
    int max = 0;
    for(int i=0; i<6; i++){
        if(old[s][i] > max)
            max = old[s][i];
    }
    return max;
}
int main(){
    int episode = 1000000;
    int alpha = 0.8;
    int eps = 10;
    int s = 0;
    //1. 对于每一个 eposide
    //1.1 随机初始化一个状态
    //1.2 随机初始化一个action
    //根据公式 q(s,a)=r(s,a)+max(s', a') 计算
    //计算 state = next_state
    do{
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                int val = q[i][j];
                val = reward[i][j] + alpha*Max(j);
                s = max(s, abs(q[i][j]-val));
            }
        }
        //使用 old 将当前值保存起来
        for(int i=0; i<6; i++){
            for(int j=0; j<6; j++){
                old[i][j] = q[i][j];
            }
        }
    }while(s>eps);

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cout<<q[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

