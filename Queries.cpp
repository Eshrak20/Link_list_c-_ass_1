#include <stdio.h>
#include <iostream>
using namespace std;
class Group
{
public:
    int value;
    Group *next;
    Group(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};
void Insert_value_at_tail(Group *&head, Group *&tail, int value, int index)
{

    Group *newNode = new Group(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
};
void Insert_value_at_head(Group *&head, Group *&tail, int value, int index)
{

    Group *newNode = new Group(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
};
void delete_node(Group *head, int pos)
{

    Group *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    Group *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void print_link_list(Group *head)
{

    Group *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
};
int main()
{
    int q;
    cin >> q;
    Group *head = NULL;
    Group *tail = NULL;
    for (int i = 0; i < q; i++)
    {

        int index, value;

        cin >> index;
        cin >> value;
        if (index == 1)
        {
            Insert_value_at_tail(head, tail, value, index);
        }
        else if (index == 0)
        {
            Insert_value_at_head(head, tail, value, index);
        }
        else
        {
            delete_node(head, index);
        }

        print_link_list(head);
    }

    return 0;
}