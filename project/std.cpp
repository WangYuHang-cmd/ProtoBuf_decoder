#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1000010;

struct Trie{
    int tr[N][2],idx;  //trie树
    int cnt[N]; //cnt数组用于标记当前串对应的下标

    void insert(string& s,int id){
        int p=0;
        for(auto u:s){
            int ch = u-'0';
            if(!tr[p][ch])
                tr[p][ch] = ++idx;
            p=tr[p][ch];
        }
        cnt[p] = id;
    }

    int query(string &s){  //返回值为下标
        int p=0;
        for(auto u:s){
            int ch = u-'0';
            if(!tr[p][ch^1]){
                p = tr[p][ch];
            }else{
                p = tr[p][ch^1];
            }
        }
        return cnt[p];
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
    for(int i=s.size()-1;i>=0;--i){
        for(int j=i-6;j<=i;++j){
            res += s[j];
        }
    }
    return res;
}

double calc(string &a,string &b){ //计算a和b的二进制相似率
    int len = min((int)a.size(), (int)b.size());
    int i=0;
    while(i<len&&a[i] == b[i]){
        i ++;
    }
    return (double)i/((double)len);
}

void solve(){
    int n; cin >> n;

    vector<string> vec(1, "$"); //存放所有的数值二进制过后的数据

    double s = 0.0;  //相似率

    int idx = 0, mx_time = 0; //string数组下标, 最多次数

    unordered_map<string, int> mp; //存放每个编码的出现次数

    while(n--){
        int x;
        cin >> x;
        if(x==1){
            string y;
            cin >> y;

            mp[y] += 1;
            mx_time = max(mx_time, mp[y]);

            string Proto_y = Hex2Proto(y);
            string Binary_y = Proto2Binary(Proto_y);

            int id = T.query(Binary_y);
            s = max(s, calc(vec[id], y));
            T.insert(Binary_y, ++idx);
            vec.push_back(Binary_y);
        }else{
            int y;
            cin >> y;
            if(y==1){
                cout << mx_time << endl;
            }else{
                cout << s << endl;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    // cin >> _;
    while(_--){
        solve();
    }
    return 0;
}