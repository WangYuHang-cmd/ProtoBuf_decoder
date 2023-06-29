#include <string>
#include <vector>
#include <unordered_map>

#ifndef TRIE_DEFINE
#include "Trie.h"
#endif

#define PROTOBUF_DEFINE YES

class ProtoBuf_Decoder{

private:
    int MxTime{0};
    double BinarySimilarity{0.0};
    std::vector<std::string> DataVec;
    std::unordered_map<std::string, int> DataHash;
    Trie MyTrie;
public:
    ProtoBuf_Decoder(){
        /*构造函数*/
    }

    ProtoBuf_Decoder(std::vector<std::string> DataVec_, 
                    std::unordered_map<std::string, int> DataHash,
                    Trie MyTrie,
                    int MxTime_ = 0,double BinarySimilarity_ = 0.0){
        /*构造函数*/
    }

    std::string_view get_data(int index){
        /*获取下标为index对应的data*/
    }

    bool InsertVal(std::string val){ 
        /*获取十六进制的ProtoBuf编码格式的传输数据 
            并转换为二进制形式存入data中 
            同时更新MxTime和BinarySimilarity*/
    }

    double calc_s(std::string& s_a,std::string& s_b){
        /*计算两个二进制字符串的相似率*/
    }

    int GetOccurrence(std::string& s){
        /*获取字符串s的出现次数*/
    }

    int GetMxTime(){
        /*获取功能1的答案*/
    }
    
    int GetBinarySimilarity(){
        /*获取功能2的答案*/
    }
};