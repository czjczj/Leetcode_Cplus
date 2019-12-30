/*
* Author:czj
* Time  :2019/12/29 15:25
* Email :zj_cheng@csu.edu.cn
link:https://www.acwing.com/problem/content/112/

有C头奶牛进行日光浴，第i头奶牛需要minSPF[i]到maxSPF[i]单位强度之间的阳光。
每头奶牛在日光浴前必须涂防晒霜，防晒霜有L种，涂上第i种之后，身体接收到的阳光强度就会稳定为SPF[i]，第i种防晒霜有cover[i]瓶。
求最多可以满足多少头奶牛进行日光浴。

输入格式
第一行输入整数C和L。
接下来的C行，按次序每行输入一头牛的minSPF和maxSPF值,即第i行输入minSPF[i]和maxSPF[i]。
再接下来的L行，按次序每行输入一种防晒霜的SPF和cover值,即第i行输入SPF[i]和cover[i]。
每行的数据之间用空格隔开。
输出格式
输出一个整数，代表最多可以满足奶牛日光浴的奶牛数目。

数据范围
1≤C,L≤2500,
1≤minSPF≤maxSPF≤1000,
1≤SPF≤1000
输入样例：
3 2
3 10
2 5
1 5
6 2
4 1
输出样例：
2
*/
/**
 * 一道贪心的题目：
 * 贪心的思路: 按照每一头牛 的区间[minSPF, maxSPF]  根据 minSPF 从大到小排序，
 * 然后从  minSPF 从大到小遍历，  并寻找最大的 spf 作为该牛的阳光强度。
 *
 * why?
 * 贪心的思路：  在寻找到一个满足 当前状态下 的一个 最差 的条件
 * 可以思考下这个问题：  当我们按照 minSPF从大到小遍历的时候，  从大到小去spf作为其值的时候，能够保证
 * 更小的spf被  更小的minSPF使用。  所以当前的这种思路是正确的
 */
 //有任何问题欢迎大家相互交流，学习，共同进步
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int C, L;
vector<pair<int,int>> v;
map<int, int> m;

bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.second == b.second)
        return a.first<b.first;
    return a.second<b.second;
}
int main(){
    cin>>C>>L;
    for(int i=0, l, r; i<C; i++){
        cin>>l>>r;
        v.push_back({l,r});
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0, k, v; i<L; i++){
        cin>>k>>v;
        m[k] = v;
    }

    int res = 0;
    for(int i=0; i<v.size(); i++){
        int l = v[i].first;
        int r = v[i].second;
        for(auto tmp:m){
            if(l<=tmp.first && tmp.first<=r && tmp.second>0){
                m[tmp.first] = tmp.second-1;
                res++;
                break;
            }
        }
    }
    cout<<res;
    return 0;
}

