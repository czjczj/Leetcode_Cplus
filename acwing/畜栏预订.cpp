/*
* Author:czj
* Time  :2019/12/30 14:04
* Email :zj_cheng@csu.edu.cn
有N头牛在畜栏中吃草。
每个畜栏在同一时间段只能提供给一头牛吃草，所以可能会需要多个畜栏。
给定N头牛和每头牛开始吃草的时间A以及结束吃草的时间B，每头牛在[A,B]这一时间段内都会一直吃草。
当两头牛的吃草区间存在交集时（包括端点），这两头牛不能被安排在同一个畜栏吃草。
求需要的最小畜栏数目和每头牛对应的畜栏方案。

输入格式
第1行：输入一个整数N。
第2..N+1行：第i+1行输入第i头牛的开始吃草时间A以及结束吃草时间B，数之间用空格隔开。

输出格式
第1行：输入一个整数，代表所需最小畜栏数。
第2..N+1行：第i+1行输入第i头牛被安排到的畜栏编号，编号是从1开始的 连续 整数，只要方案合法即可。

数据范围
1≤N≤50000,
1≤A,B≤1000000
输入样例：
5
1 10
2 4
3 6
5 8
4 7
输出样例：
4
1
2
3
2
4
*/
/**
 * 解题思路：  首先来理解下题目的意思，  对于给定的一个牛，  我们需要使用最少的畜栏
 * 首先我们需要按照 开始时间从下到达排序，如果开始时间相同，则在依据结束时间
 * 对于后面的新的 [开始时间，结束时间]-->[l,r]
 * 我们需不需要使用一个新的畜栏，  将要去寻找前面最早的结束时间（这里使用一个最小堆维护这样的信息）min_r
 * 如果min_r > l,  对于这个后面的区间我们需要使用一个新的  畜栏
 * 否则，我们可以直接使用对应的 最小的min_r的畜栏到这里使用。
 *
 * 具体实现的话， c++ STL优先队列 priority_queue（默认从小到大排序的是）
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int N = 50010;
struct node{
    int l, r, x;
    bool operator <(const node& a) const{
        if(r == a.r)
            return l>a.l;
        return r>a.r;
    }
}a[N];

priority_queue<node> p;//默认为大根堆，所以 operator < 这样子写
int n;
bool cmp(node a, node b){
    if(a.l == b.l)
        return a.r<b.r;
    return a.l<b.l;
}

int ans[N];
int main(){
    cin>>n;
    int res = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i].l>>a[i].r;
        a[i].x = i;
    }
    sort(a+1, a+n+1, cmp);

    for(int i=1; i<=n; i++){
        if(!p.empty() && p.top().r < a[i].l){
            ans[a[i].x] = ans[p.top().x];
            p.pop();
        }else{
            res++;
            ans[a[i].x] = res;
        }
        p.push(a[i]);
    }

    cout<<res<<endl;
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}


