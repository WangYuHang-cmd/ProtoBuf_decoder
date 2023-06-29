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

void solve()
{
    ProtoBuf_Decoder MyPD;

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        std::cin >> x;
        if (x == 1)
        {
            std::string y;
            std::cin >> y;
            try{
                if(!MyPD.InsertVal(std::move(y))){
                    throw false;
                }
            }catch(bool flag){
                std::cerr << "Insert error!\n" << std::endl;
            }
        }
        else
        {
            int y;
            std::cin >> y;
            if(y == 1){
                std::cout << MyPD.GetMxTime() << std::endl;
            }else{
                std::cout << MyPD.GetBinarySimilarity() << std::endl;
            }   
        }
    }
}

signed main()
{
    for (int i = 1; i <= 100; ++i)
    {
        std::string InputFile = "test_" + std::to_string(i) + ".in";
        std::string OutputFile = "test_" + std::to_string(i) + ".out";
        std::freopen(InputFile.c_str(), "r", stdin);
        std::freopen(OutputFile.c_str(), "w", stdout);
        solve();
    }
    return 0;
}