/*
* Author:czj
* Time:  2019/8/16 09:35
*一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。
    假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。
    例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。
    与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。
    现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。
    注意:
    起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
    所有的目标基因序列必须是合法的。
    假定起始基因序列与目标基因序列是不一样的。
    示例 1:
    start: "AACCGGTT"
    end:   "AACCGGTA"
    bank: ["AACCGGTA"]
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
class Solution {
public:
    int minMutation(string s, string e, vector<string>& b) {
        bool flag = false;
        for(int i=0; i<b.size(); i++){
            if(e == b[i]){
                flag = true;
                break;
            }
        }
        if(!flag)  //判断 bank 是否包含 end
            return -1;
        set<string> ss;
        for(int i=0; i<b.size(); i++){
            ss.insert(b[i]);
        }
        int rtn = dfs(s, e, ss);
        return rtn==1000?-1:rtn;
    }
    int dfs(string s, string e, set<string>& b) {
        if(s==e)
            return 0;
        int minCnt = 1000;
        //比较当前字符与目标字符不同的地方
        set<string>::iterator iter = b.begin();
        while(iter != b.end()){
            //比较当前字符和 集合字符只有一个不同的位置
            string tmp = *iter;
            iter++;
            int idx = -1;
            int cnt = 0;
            bool flag = true;
            for(int i=0; i<s.length(); i++){
                if(cnt > 1)
                    flag = false;
                if(tmp[i] != s[i]){
                    idx = i;
                    cnt++;
                }
            }

            if(flag && cnt <= 1){
                set<string> tmpS(b);
                tmpS.erase(tmp);
                minCnt = min(dfs(tmp,e,tmpS)+1, minCnt);
            }
        }
        return minCnt;
    }
};
int main(){
    Solution s;
    vector<string> a = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    cout<<s.minMutation(start,end,a)<<endl;
    return 0;
}



