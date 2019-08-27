/*
* Author:czj
* Time:  2019/8/23 10:02
*
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#define MAX_VALUE 1e9
using namespace std;
void sort_core(vector<int>& a, int i, int e){
    int s1 = 2*i+1;
    if(s1 > e)
        return;
    int s2 = 2*i+2;
    int m = s1;
    if(s2<e && a[s2]>a[s1]){
        m = s2;
    }
    if(a[m]>a[i]){
        int tmp = a[m];
        a[m] = a[i];
        a[i] = tmp;
        sort_core(a, m, e);
    }
}
void heap_sort(vector<int>& a){
    int n = a.size();
    for(int i=n/2-1; i>=0; i--){
        sort_core(a,i,n-1);
    }
    for(int i=n-1; i>0; i--){
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        sort_core(a,0,i-1);
    }
}
int main(){
    vector<int> a = {5,10,11,8,7};
    heap_sort(a);
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}


