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
    int t;         // min degree
    int n;         // current number of keys
    bool leaf;     // whether node is leaf
    int* keys;     // array of keys
    BTreeNode** C; // array of child pointers
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
