#ifndef LINEAR_STACK_H
#define LINEAR_STACK_H

template <class T>
class LinearStack {
public:
    LinearStack(const int cap);
    ~LinearStack();

    bool IsEmpty() const;
    int Length() const;
    LinearStack& Push(const T& x);
    LinearStack& Pop(T& x);
    LinearStack& Clear();
    const T& Top() const;
    void Output() const;
    
private:
    T*  data;
    int top;
    int cap;
};

#endif
