/*
* Author:czj
* Time  :2019/12/22 10:50
* Email :zj_cheng@csu.edu.cn
*/

#include <iostream>
#include <algorithm>
using namespace std;

void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main() {
    divide(27);
    return 0;
}


