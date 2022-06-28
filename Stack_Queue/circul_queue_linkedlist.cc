#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef int ElemType;

// 链表-队列
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;


// ADT
void InitQueue(LinkQueue &Q);
bool QueueEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q, ElemType x);     // !!!
bool DeQueue(LinkQueue &Q, ElemType &x);    // !!!

int main() {

}

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode)); // head node
    Q.front->next = Q.rear->next = NULL;
}

bool IsEmpty(LinkQueue &Q) {
    return Q.front == Q.rear;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL; // 不要忘记next
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (Q.front == Q.rear)
        return false;
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return true;
}
