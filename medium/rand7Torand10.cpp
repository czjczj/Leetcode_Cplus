/*
* Author:czj
* Time:  2019/8/22 13:47
* 已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
  不要使用系统的 Math.random() 方法。
  示例 1:
  输入: 1
  输出: [7]
*/
/**
 * 解题思路：概率问题
 * rand7 产生 1-7 之间的等概率数字
 * （rand7-1）*7 相当于等概率的尝试 7的倍数的数字，例如 0 7 14 21...42
 * 两者相加以后将会等概率的产生   0....49 之间的任何一个数字
 * 因为是需要 产生1-10之间的数字，现在我们相当于有一个随机数种子为 [0...49]之间的任何一个数字
 * 对于大于40的数字，我们将随机数重新产生一次， 那么现在就相当于随机产生了 [0。。。40]之间的数字
 * 那么 a%10+1  就能够刚好等概率（4/40）的产生 1-10之间的数字了
 */
#include <iostream>
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
class Solution {
public:
    int rand10() {
        while(true){
            int a = (rand7()-1)*7+rand7();
            if(a > 40)
                continue;
            else
                return a%10+1;
        }
    }
};
using namespace std;
int main() {

    return 0;
}


