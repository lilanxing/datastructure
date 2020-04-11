#ifndef CHAIN_H
#define CHAIN_H

#include <ostream>

template <class T> class Chain;

template <class T>
class ChainNode {
    friend Chain<T>;
private:
    T data;
    ChainNode<T>* link;
};

template <class T>
class Chain {
public:
    Chain();
    ~Chain();

    bool IsEmpty() const;
    int Length() const;
    bool Find(const int k, T& x) const;
    int Search(const T& x) const;
    Chain<T>& Delete(const int k, T& x);
    Chain<T>& Insert(const int k, const T& x);
    void Output(std::ostream& out) const;

private:
    ChainNode<T>* first;
};

template <class T>
std::ostream& operator<<(std::ostream& out, const Chain<T>& x) {
    x.Output(out);
    return out;
}

#endif
