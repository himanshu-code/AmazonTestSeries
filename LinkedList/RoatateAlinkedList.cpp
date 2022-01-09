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
Node *rotate(Node *head, int k)
{
    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = head;
    node = head;
    while (k > 1)
    {
        k--;
        node = node->next;
    }
    head = node->next;
    node->next = NULL;
    return head;
}
Node *rotateright(Node *head, int k)
{
    if (!head)
        return NULL;
    if (!head->next)
        return head;

    Node *node = head, *node2 = head;
    int n = 1;
    while (node->next != NULL)
    {
        n++;
        node = node->next;
    }
    k = k % n;
    for (int i = 0; i < n - k - 1; i++)
        node2 = node2->next;
    node->next = head;
    head = node2->next;
    node2->next = NULL;

    return head;
}
int main()
{
    int n, k;
    cin >> n;
    Node *head = buildList(n);
    printList(head);
    cin >> k;
    head = rotate(head, k);
    printList(head);

    head = rotateright(head, k);
    printList(head);
}