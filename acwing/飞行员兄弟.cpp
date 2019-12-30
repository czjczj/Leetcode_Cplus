/*
* Author:czj
* Time  :2019/12/27 21:28
* Email :zj_cheng@csu.edu.cn
link: https://www.acwing.com/problem/content/118/
“飞行员兄弟”这个游戏，需要玩家顺利的打开一个拥有16个把手的冰箱。
已知每个把手可以处于以下两种状态之一：打开或关闭。
只有当所有把手都打开时，冰箱才会打开。
把手可以表示为一个4х4的矩阵，您可以改变任何一个位置[i,j]上把手的状态。
但是，这也会使得第i行和第j列上的所有把手的状态也随着改变。
请你求出打开冰箱所需的切换把手的次数最小值是多少。

输入格式
输入一共包含四行，每行包含四个把手的初始状态。
符号“+”表示把手处于闭合状态，而符号“-”表示把手处于打开状态。
至少一个手柄的初始状态是关闭的。

输出格式
第一行输出一个整数N，表示所需的最小切换把手次数。
接下来N行描述切换顺序，每行输入两个整数，代表被切换状态的把手的行号和列号，数字之间用空格隔开。

注意：如果存在多种打开冰箱的方式，则按照优先级整体从上到下，同行从左到右打开。
数据范围
1≤i,j≤4
输入样例：
-+--
----
----
-+--
输出样例：
6
1 1
1 3
1 4
4 1
4 3
4 4
*/
//欢迎大家如果有任何问题，一起交流相互学习
/**
 * 解题思路： 每一个状态只能是 0，1 显然这是一道 位操作相关的方法。
 * 我们能够操作的状态个数是  2^16.  在每次操作的时候，我们能够根据这个状态的操作对应的改变 开关的状态，
 * 等一个状态操作完毕以后，我们计算得到最后的结果（即如果开关都是打开的）  记录操作次数 ans,  更新最小结果 res
 * 时间复杂度 O(2^16 * 16 * 4)
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[4][4];
int backup[4][4];
void turn(int x, int y){
    for(int i=0; i<4; i++){
        a[i][y] ^= 1;
        a[x][i] ^= 1;
    }
    a[x][y] ^= 1;
}

bool check(){
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            if(a[i][j])
                return false;
        }
    return true;
}
int main(){
    char c;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++){
            cin>>c;
            if(c=='-')
                a[i][j]=0;
            else
                a[i][j] = 1;
        }

    int res = 0x3f;
    for(int i=0; i<(1<<16); i++){
        int ans = 0;
        memcpy(backup, a, sizeof a);
        for(int j=0; j<16; j++)
            if(i & 1<<j){
                int x = j/4;
                int y = j%4;
                turn(x,y);
                ans++;
            }

        if(check()){
            res = min(res, ans);
            cout<<res<<endl;
            for(int j=0; j<16; j++)
                if(i & 1<<j){
                    int x = j/4;
                    int y = j%4;
                    cout<<x+1<<" "<<y+1<<endl;
                    ans++;
                }
        }
        memcpy(a, backup, sizeof backup);
    }
    return 0;
}

