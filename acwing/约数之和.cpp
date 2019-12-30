/*
* Author:czj
* Time  :2019/12/22 11:03
* Email :zj_cheng@csu.edu.cn
link: https://www.acwing.com/problem/content/99/
假设现在有两个自然数A和B，S是AB的所有约数之和。
请你求出S mod 9901的值是多少。
输入格式
在一行中输入用空格隔开的两个整数A和B。
输出格式
输出一个整数，代表S mod 9901的值。
数据范围
0≤A,B≤5×107
输入样例：
2 3
输出样例：
15
注意: A和B不会同时为0。
*/
/**
 * 解题思路： 首先分析下题目意思：  0< A,B< 5x10^7,  直接乘方 肯定是不可以的
 * 分解A;
 * 任意数字A的质数分解可以表示为
 * A = p0^k0 * p1^k1 * ... * pn^kn
 *
 * 则A的约数的个数为
 *     (k0+1) * (k1+1) * ... * (kn+1)   #取p0的个数有 0...k0种取法， 则同样的可以推导出  约数 的个数
 *
 * A的约数的和为：
 * (1 + p0^1 + ... + p0^k0) * (1 + p1^1 + ... + p1^k1) * ... * (1 + p0^1 + ... + pn^kn)
 *
 * 那么显然，最后我们需要求解的问题就是最后一项。  这是一个等比数列
 * 我们可以给出其 递归的 求解方式  假设 sum(p,k) = (1+p+...+p^k)
 *
 * 如果k是奇数，那么
 * sum(p,k) = (1+p+...+p^(k/2)) + ( p^(k/2 + 1) + ... + p^k)
 *          = (p^(k/2 + 1) + 1) * (1 + p +...+p(k/2))
 *          = sum(p, k/2) * (p^(k/2 + 1) + 1)
 *
 * 求解 p^n 使用了快速幂函数算法
 */
#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 9901;

int qmi(int a, int b){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1)
            res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
int sum(int p, int k){
    if(k==0) return 1;
    if(k%2 == 0)
        return (p%mod * sum(p, k-1) + 1) % mod;
    return (1+qmi(p, k/2 +1 )) * sum(p,k/2) % mod;
}
int main() {
    int A, B;
    cin>>A>>B;
    int res = 1;
    for(int i=2; i<=A; i++){
        int k = 0;
        while(A%i == 0){
            k++;
            A /= i;
        }
        if(k){
            res = res*sum(i,k*B)%mod;
        }
    }
    if(!A) res = 0;
    cout<<res<<endl;
    return 0;
}




