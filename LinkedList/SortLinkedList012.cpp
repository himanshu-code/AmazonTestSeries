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
Node *segregate(Node *head)
{
    int count[3] = {0, 0, 0};
    Node *ptr = head;
    while (ptr != NULL)
    {
        count[ptr->x] += 1;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (count[i] == 0)
        {
            ++i;
        }
        else
        {
            ptr->x = i;
            --count[i];
            ptr = ptr->next;
        }
    }
    return head;
}
int main()
{
    int n;
    cin >> n;
    Node *head = buildList(n);
    printList(head);
    head = segregate(head);
    printList(head);
}