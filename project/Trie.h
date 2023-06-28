#include <cstdio>
#include <vector>
#include <string>


/*
    这是前缀树的基类节点
    需要完成简单的设计
*/

class TrieNode
{
public:
    explicit TrieNode(char key_char){
        /*构造函数*/
    }

    TrieNode(TrieNode &&other_trie_node) noexcept
    {
        /*移动构造函数*/
    }

    virtual ~TrieNode() = default;

    bool HasChild(char key_char) const {  
        /*判断是否key_char对应的子节点*/
    }

    bool HasChildren() const { 
        /*是否有子节点*/
    }

    bool IsEndNode() const {
        /*是否是叶子节点*/
    }

    char GetKeyChar() const {
        /*获得到达当前节点的字符*/
    }

    std::unique_ptr<TrieNode> *InsertChildNode(char key_char, std::unique_ptr<TrieNode> child){
        /*根据key_char插入节点*/
    }

    std::unique_ptr<TrieNode> *GetChildNode(char key_char){
        /*获得儿子节点*/
    }

    void RemoveChildNode(char key_char){
        /**/
    }

    void SetEndNode(bool is_end) { is_end_ = is_end; }

protected:
    /** Key character of this trie node */
    char key_char_;
    /** whether this node marks the end of a key */
    bool is_end_{false};
    /** A map of all child nodes of this trie node, which can be accessed by each child node's key char. */
    std::unordered_map<char, std::unique_ptr<TrieNode>> children_; 
};

template <typename T>
class TrieNodeWithValue : public TrieNode
{
private:
    T value_;

public:
    TrieNodeWithValue(TrieNode &&trieNode, T value) : TrieNode(std::forward<TrieNode>(trieNode)){
        /*构造函数1*/
    }

    TrieNodeWithValue(char key_char, T value) : TrieNode(key_char){
        /*构造函数2*/
    }

    ~TrieNodeWithValue() override = default;

    T GetValue() const { /*返回value_*/ }
};


/*
    本题在单线程环境下，无需读写锁，因此需要将锁的部分删除
*/

class Trie
{
private:
    /* Root node of the trie */
    std::unique_ptr<TrieNode> root_;
    /* Read-write lock for the trie */
    ReaderWriterLatch latch_;

public:
    Trie(){
        /*初始化Trie*/
    }

    template <typename T>
    bool Insert(const std::string &key, T value){
        /*插入节点*/
    }

    template <typename T>
    T GetValue(const std::string &key, bool *success){
        /*获取节点对应的值*/
    }

    /*这个函数不用管*/
    bool Remove(std::string_view key) {
        if (key.empty())
        {
            return false;
        }

        latch_.WLock();
        std::vector<std::unique_ptr<TrieNode> *> stk; // use stack
        auto now = &root_;

        stk.push_back(now);
        bool flag = true;

        std::unique_ptr<TrieNode> *temp;
        for (size_t i = 0; i < key.size(); ++i)
        {
            temp = (*now)->GetChildNode(key[i]);
            if (temp != nullptr)
            {
                if (i == key.size() - 1)
                {
                    if (!((*temp)->IsEndNode()))
                    {
                        flag = false;
                    }
                    else
                    {
                        stk.push_back(temp);
                    }
                }
                else
                {
                    stk.push_back(temp);
                    now = temp;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            stk.clear();
            latch_.WUnlock();
            return false;
        }

        if ((*temp)->HasChildren())
        {
            if ((*temp)->IsEndNode())
            {
                (*temp)->SetEndNode(false);
                stk.clear();
                latch_.WUnlock();
                return true;
            }
            stk.clear();
            latch_.WUnlock();
            return false;
        }

        for (int j = key.size() - 1; j >= 0; --j)
        {
            (*stk[j])->RemoveChildNode((*stk[j + 1])->GetKeyChar());
            stk.pop_back();
            if ((*stk[j])->HasChildren() || (*stk[j])->IsEndNode())
            {
                break;
            }
        }

        stk.clear();
        latch_.WUnlock();
        return true;
    }
};
