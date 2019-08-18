#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
void a(vector<int>& b){
    b.erase(b.begin());
    cout<<b.size();
}
int main(){
    vector<int> v = {1,3,5,2,4};
    map<string, int> d;
    d["wkq"] = 520;
    cout<<d.size()<<" "<<d["wkq"]<<" "<<d.count("czj")<<d.count("wkq");
    return 0;
}