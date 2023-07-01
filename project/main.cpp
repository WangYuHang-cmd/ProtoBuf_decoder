#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

#ifndef TRIE_DEFINE
#include "Trie.h"
#endif

#ifndef PROTOBUF_DEFINE
#include "ProtoBuf.h"
#endif

ProtoBuf_Decoder MyPD;

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        std::string y;
        std::cin >> x >> y;
        
        if(x == 1){

        }else{

        }
    }
}

signed main()
{
    for (int i = 1; i <= 10; ++i)
    {
        std::string InputFile = "in" + std::to_string(i) + ".in";
        std::string OutputFile = "out" + std::to_string(i) + ".out";
        std::freopen(InputFile.c_str(), "r", stdin);
        std::freopen(OutputFile.c_str(), "w", stdout);
        solve();
    }
    return 0;
}