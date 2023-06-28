#include <iotream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>

using namespace std;

const int N = 1000010;

struct Trie{
    int tr[N][2],idx; 
    int cnt[N];

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

    int query(string &s){  //return id
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
};

string Hex2Binary(string &s){
    string t = "";
    for(int i=2;i<(int)s.size();++i){

    }
    return t;
}

double calc(string &a,string &b){ // calc s of(a,b)

}

void solve(){
    Trie T;

    int n; cin >> n;

    double s = 0.0;  //相似率

    int idx = 0, mx_time = 0; //string数组下标

    vector<string> vec; //存放所有的数值二进制过后的数据

    unordered_map<string, int> mp; //存放每个编码的出现次数

    while(n--){
        int x;
        cin >> x;
        if(x==1){
            string y;
            cin >> y;

            string Binary_y = Hex2Binary(y);

            int id = T.query(Binary_y);

            s = max(s, calc(vec[id], y));
            
            T.insert(Binary_y, ++cnt);
            vec.push_back(Binary_y);

            mp[Binary_y] ++;
            mx_time = max(mx_time, mp[Binary_y]);
        }else{
            int y;
            cin >> y;
            if(y==1){
                std::cout << mx_time << std::endl;
            }else{
                std::cout << s << std::endl;
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