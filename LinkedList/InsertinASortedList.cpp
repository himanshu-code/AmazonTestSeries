#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int x;
    Node *next;
    Node(int x)
    {
        this->x = x;
        this->next = NULL;
    }
};
Node *buildList(int n)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }
    return head;
}
void printList(Node *head)
{
    Node *p = head;
    if (p == NULL)
        return;
    while (p != NULL)
    {
        cout << p->x << " ";
        p = p->next;
    }
    cout << endl;
}
Node *sortInserted(Node *head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
        return node;
    else if (head->next == NULL)
    {
        if (head->x > data)
        {
            node->next = head;
            return node;
        }
        else
        {
            head->next = node;
            return head;
        }
    }
    if (head->x >= data)
    {
        node->next = head;
        return node;
    }
    Node *p = head;
    Node *q = head->next;
    while (q != NULL)
    {
        if (q->x >= data)
        {
            p->next = node;
            node->next = q;
            return head;
        }
        p = q;
        q = q->next;
    }
    p->next = node;
    return head;
}
int main()
{
    int n;
    cin >> n;
    Node *head = buildList(n);
    printList(head);
    int data;
    cin >> data;
    head = sortInserted(head, data);
    printList(head);
}