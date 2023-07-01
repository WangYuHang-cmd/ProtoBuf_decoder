#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ": " << x << endl

int total = 1000000;

string getBinary(int len){
    if(len < 2) len += 2;
    string ans = "";
    for(int i=0;i<len;++i){
        int t = rand() % 2;
        ans += '0' + t;
    }
    return ans;
}

string Binary2Proto(string s){
    // 转换为ProtoBuf编码
    string ans = "0x";
    reverse(s.begin(), s.end());
    while(s.back()=='0') s.pop_back();
    while(s.size()%7!=0) s.push_back('0');
    reverse(s.begin(), s.end());
    // debug(s);    
    for(int i=s.size()-1;i>=0;i-=7){
        int tmp = (i == 6 ? 0 : 1);
        for(int j=i-6;j<=i-4;++j){
            tmp = (tmp << 1) | (s[j]=='1');
        }
        if(tmp<10) ans += tmp+'0';
        else ans += 'A' + (tmp-10);
        
        // debug(tmp);

        tmp = 0;
        for(int j=i-3;j<=i;++j){
            tmp = (tmp << 1) | (s[j]=='1');
        }

        if(tmp < 10) ans += tmp+'0';
        else ans += 'A'+(tmp-10);            
    }
    return ans;
}

void solve(){
    int total = 100000;
    vector<string> res;
    int num = 10000;
    cout << num << endl;
    for(int tt = 0; tt < num; ++tt){
        int flag = rand() % 2;
        if(tt==0) flag=1;
        if(flag){
            if(total < 0) {
                cout << 2 << " " << "0x3F" << endl;
                continue;
            }
            int siz = rand() % total;
            if(tt == 0) siz = 50000;
            if(siz < 7) siz = 7;
            string ans = getBinary(siz);
            ans = Binary2Proto(ans);
            cout << 1 << " " << ans << endl;
            total -= ans.size();
        }else{
            cout << 2 << " ";
            if(res.empty()) cout << "0x3F" << endl;
            else{
                int index = rand() % (int)(res.size());
                cout << res[index] << endl;
            }
        }
    }
}

signed main(){
    srand((unsigned)time(0));
    for(int i=10;i<=10;++i){
        string OutputFile = "in" + to_string(i) + ".txt";
        freopen(OutputFile.c_str(), "w", stdout);
        solve();
    }
    return 0;
}