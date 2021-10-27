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
Node *reverseList(Node *head)
{
    Node *prev = NULL, *curr = NULL;
    if (head != NULL)
    {
        prev = head;
        curr = head->next;
        head = head->next;
        prev->next = NULL;
        while (head != NULL)
        {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        head = prev;
    }
    return head;
}
int main()
{
    int n;
    cin >> n;
    Node *head = buildList(n);
    printList(head);
    head = reverseList(head);
    printList(head);
}