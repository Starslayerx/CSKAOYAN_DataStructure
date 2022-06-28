#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef int ElemType;

#define MaxSize 100

// 顺序栈
typedef struct{
    ElemType data[MaxSize]; // element
    int top;                // pointer
} SqStack;

// ADT
void InitStack(SqStack &S);
bool StackEmpty(SqStack &S);
bool Push(SqStack &S, ElemType x);
bool Pop(SqStack, ElemType &x);
bool GetTop(SqStack &S, ElemType &x);
void DestoryStack(SqStack &S);

int main() {

}


void InitStack(SqStack &S) {
    S.top = -1;
}

bool IsEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, ElemType data) {
    if (S.top + 1 == MaxSize)
        return false;
    S.data[++S.top] = data;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

void DestoryStack(SqStack &S) {
    S.top = -1;
}
