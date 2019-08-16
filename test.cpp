#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int main(){
    set<string> temp1;
    temp1.insert("520");
    temp1.insert("521");
    temp1.insert("522");
    temp1.insert("523");
    set<string> tmpS(temp1);
    temp1.erase("521");
    set<string>::iterator iter = tmpS.begin();
    while (iter!=tmpS.end())
    {

        string a = *iter;
        cout<<a<<endl;
        iter++;
    }
    return 0;
}