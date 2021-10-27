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
Node *buildLinkedList(int n)
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
int getMiddle1(Node *head)
{
    // Your code here
    int n = 0;
    Node *p = head;
    while (p->next != NULL)
    {
        n++;
        p = p->next;
    }
    p = head;
    n = (n + 1) / 2;
    while (n--)
    {
        p = p->next;
    }
    return p->x;
}
int getMiddle(Node *head)
{
    Node *temp = head;
    Node *mid = head;
    if (head == NULL)
        return -1;
    while (mid != NULL && mid->next != NULL)
    {
        mid = mid->next->next;
        temp = temp->next;
    }
    return temp->x;
}
int main()
{
    int n;
    cin >> n;
    Node *head = buildLinkedList(n);
    cout << getMiddle(head);
    cout << getMiddle1(head);
}