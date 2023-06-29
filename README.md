## 任务描述：

工程环境下我们常使用`ProtoBuf`进行数据的序列化传输。`ProtoBuf`编码对于`Varint`的传输原理就是：将一个整数转化成二进制的形式，从低位开始每七位一组，加上最高位0/1。首位为0表示当前段为此数值传输的最后一段，首位为1表示后面仍然进行传输。例如$(300)_{10}$转化为二进制后$(1 0010 1100)_2$可以分成两组进行传输，且不足7位的用0补足，且从低位依次进行传输：$(1 0101100 )_{ProtoBuf}$ $(0 0000010)_{ProtoBuf}$。因此其在传输的时候的十六进制信息为$0xAC02$。

现在请你设计一个小型整数`ProtolBuf`解码器，并拓展以下功能：

1. 插入一个数值
2. 找出出现次数最多的数值的出现次数
3. 找出所有数值二进制下的最高相似率

两个数值二进制下的相似率定义：$$s = \frac{二进制最长公共前缀}{min(两个字符分别的二进制长度)}$$



**输入 & 输出**

第1行，一个十进制数值`n`

第2~n+1行。每行形如`x y`的形式：

`x=1` 表示接收到一个新的十六进制数值`y` (0x开头的形式)

`x=2 y=1` 表示输出一个数，对应目前，功能1的结果

`x=2 y=2` 表示输出两个数，对应目前，功能2的结果

一行输出一个询问的结果



**数据范围**

$5 \le n \le 10^5 $

$4 \le len(y_{16进制}) \le 10^5 $ 且  $ \sum{len(y_{16进制})} \le 10^5$





### 提示

- Hint1:
- 阅读ProtoBuf [ProtoBuf Introduction](https://zelostech.feishu.cn/wiki/A3x8wImokiL6bskSpuSc6nptngd) 

- Hint2:
- 阅读数据结构相关简介 
  - [STL 哈希表](https://cplusplus.com/reference/unordered_map/unordered_map/) <unordered_map>
  - [字典树Trie](https://oi-wiki.org/string/trie/) 

- Hint3:
- 可以直接在[此代码库](https://github.com/WangYuHang-cmd/ProtoBuf_decoder#提示)上直接进行修改

### 文件提交：

一个文件夹压缩包 目录如下：

```C++
- project
|-xxx.h
|-xxx.h
|-...
|-main.c
```

### 编译方式

使用bazel进行编译