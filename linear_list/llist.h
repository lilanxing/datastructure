#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include <iostream>

template <class T>
class LinearList {
public:
    LinearList(const int max_size);
    ~LinearList();
    bool IsEmpty() const;
    int Length() const;
    bool Find(const int k, T& x) const;             // 返回第k个元素至x
    int Search(const T& x) const;                   // 返回x所在位置
    LinearList<T>& Delete(const int k, T& x);       // 删除第k个元素并返回至x中
    LinearList<T>& Insert(const int k, const T& x); // 在第k个元素后插入x
    void Output(std::ostream& out) const;

private:
    int max_size;
    int length;
    T*  element;
};

template <class T>
std::ostream& operator<<(std::ostream& out, const LinearList<T>& x) {
    x.Output(out);
    return out;
}

#endif
