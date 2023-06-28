# GoodCoder

## 任务描述：

在特定场景下，例如序列化后的数据，我们使用ProtoBuf的传输方式对数值进行传输。现在请你设计一个小型ProtolBuf解码器，并拓展以下功能：
1. 统计每个数值出现的次数，然后找出出现次数最多的数值
2. 找出ProtoBuf编码下相似率最高的两个数值
ProtoBuf编码下两个数值相似率定义：$$s = \frac{最长公共前缀}{min(两个字符分别的长度)}$$

### 输入 & 输出
第1行，一个十进制数值n
第2~n+1行。每行形如x y的形式：
x=1 表示接收到一个新的十六进制数值y (0x开头的形式)
x=2 y=1 表示输出一个数，对应目前，功能1的结果
x=2 y=2 表示输出两个数，对应目前，功能2的结果
一行输出一个询问的结果

### 样例


### 提示
- Hint1:
[] 阅读ProtoBuf ProtoBuf Introduction 

- Hint2:
[] 阅读数据结构相关简介 
  [] STL 哈希表 <unordered_map>
  [] 字典树Trie 

- Hint3:
[] [可以直接在此代码库上直接进行修改](https://github.com/WangYuHang-cmd/ProtoBuf_decoder)


### 文件提交：
一个文件夹压缩包 目录如下：


