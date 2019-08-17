#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int main(){
    string s = "abcd";
    int i = 1;
    string a1 = s.substr(0,i+1);
    string a2 = s.substr(i+1,s.length()-i);
    cout<<a1<<" "<<a2;
    return 0;
}