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
Node *swapPairs(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *next_pair = swapPairs(head->next->next);
    Node *temp = head->next;
    temp->next = head;
    head->next = next_pair;
    return temp;
}
int main()
{
    int n;
    cin >> n;
    Node *head = buildList(n);
    printList(head);
    head = swapPairs(head);
    printList(head);
}