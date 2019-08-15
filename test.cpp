#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int dp[2][4/2+1];
    fill(dp[0], dp[0]+(2*(4/2+1)),5);
    cout<<dp[1][2];
    return 0;
}