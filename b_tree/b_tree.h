/*
 * 参考geeksforgeeks，根据B树的度（而不是阶）来实现
*/

#ifndef B_TREE_H
#define B_TREE_H

class BTreeNode {
    friend class BTree;
public:
    BTreeNode(int _t, bool _leaf);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);
    void traverse();
    BTreeNode* search(int k);
    
private:
    int t;         // B树的度
    int n;         // 关键字个数
    bool leaf;     // 是否是叶节点
    int* keys;     // 关键字数组
    BTreeNode** C; // 孩子节点数组
};

class BTree {
public:
    BTree(int _t);
    void traverse();
    BTreeNode* search(int k);
    void insert(int k);
    
private:
    BTreeNode* root;
    int t;
};

#endif
