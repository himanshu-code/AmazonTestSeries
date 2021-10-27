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
Node *deleteMid(Node *head)
{
    Node *temp = head;
    Node *mid = head;
    Node *r = NULL;
    while (mid != NULL and mid->next != NULL)
    {
        mid = mid->next->next;
        r = temp;
        temp = temp->next;
    }
    r->next = temp->next;

    return head;
}
int main()
{
    int n;
    cin >> n;
    Node *head = buildList(n);
    printList(head);
    head = deleteMid(head);
    printList(head);
}