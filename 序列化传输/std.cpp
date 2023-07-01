
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <chrono>
#define debug(x) std::cout<<#x<<": "<<x<<std::endl
using namespace std;

const int N = 10000100;

struct Trie{
    int tr[N][2],idx{0};  //trie树
    int cnt[N]; //cnt数组用于标记当前节点的个数

    void insert(string& s,int id){
        int p=0;
        for(auto u:s){
            int ch = u-'0';
            if(!tr[p][ch])
                tr[p][ch] = ++idx;
            p=tr[p][ch];
            cnt[p] ++;
        }
    }

    int query(string &s){  //返回值为下标
        int p=0, len = 0;
        for(auto u:s){
            int ch = u-'0';
            if(tr[p][ch]){
                p = tr[p][ch];
                ++len;
            }else{
                break;
            }
        }
        return len;
    }

    void remove(string &s){  //删除一个串
        int p = 0;
        for(auto u:s){
            int ch = u-'0';
            int tmp = tr[p][ch];
            cnt[tr[p][ch]] --;
            if(cnt[tr[p][ch]] == 0){
                tr[p][ch] = 0;
            }
            p = tmp;
        }
    }
}T;

string Hex2Proto(string &s){  //s=0x...
    string res = "";
    for(int i=2;i<(int)s.size();++i){
        int num = 0;
        if(isdigit(s[i])){
            num = s[i]-'0';
        }else{
            num = s[i]-'A'+10;
        }
        string tmp = "";
        for(int j=0;j<4;++j){
            tmp += ('0' + (num&1));
            num >>= 1;
        }
        reverse(tmp.begin(), tmp.end());
        res += tmp;
    }
    return res;
}

string Proto2Binary(string &s){
    string res = "";
    for(int i=s.size()-1;i>=0;i-=8){
        for(int j=i-6;j<=i;++j){
            res += s[j];
        }
    }
    reverse(res.begin(), res.end());
    while(res.size()&&res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

void solve(){
    int n; cin >> n;

    vector<string> vec(1, "0");     //存放所有的数值二进制过后的数据

    int idx = 0, s = 0;             //string数组下标, 相似长度

    unordered_map<string, int> mp; //存放每个编码的出现次数

    while(n--){
        int x;
        string y;
        cin >> x >> y;

        if(x == 1){
            mp[y] += 1;
            string Proto_y = Hex2Proto(y);
            string Binary_y = Proto2Binary(Proto_y);

            s = T.query(Binary_y);
            T.insert(Binary_y, ++idx);
            vec.push_back(Binary_y);

            cout << mp[y] << " " << s << endl;
        }else{
            if(mp.count(y) && mp[y] > 0) {
                mp[y] --;
                string Proto_y = Hex2Proto(y);
                string Binary_y = Proto2Binary(Proto_y);
                T.remove(Binary_y);
            }
        }
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // int _=1;
    // cin >> _;
    // while(_--)
    // int i;
    // cin >> i;
    // string InputFile = "in" + to_string(i) + ".txt";
    // string OutputFile = "out" + to_string(i) + ".txt";
    // freopen(InputFile.c_str(), "r", stdin);
    // freopen(OutputFile.c_str(), "w", stdout);
    // auto t0 = std::chrono::steady_clock::now();
    solve();
    // auto t1 = std::chrono::steady_clock::now();
    // auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
    // cerr << dt.count() << "ms\n";
    
    return 0;
}