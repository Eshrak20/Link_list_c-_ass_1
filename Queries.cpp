#include <stdio.h>
#include <iostream>
using namespace std;
int sum = 0;
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
void Insert_value_at_tail(Group *&head, int value)
{

    Group *newNode = new Group(value);
    Group *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
};
void Insert_value_at_head(Group *&head, int value)
{

    Group *newNode = new Group(value);
    Group *temp = head;
    newNode->next = head;
    head = newNode;
    return;
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
void print_link_list_size(Group *head)
{

    Group *temp = head;
    while (temp != NULL)
    {
        sum++;
        temp = temp->next;
    }
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
            Insert_value_at_tail(head, value);
        }
        else if (index == 0)
        {
            Insert_value_at_head(head, value);
        }
        else if (index == 2)
        {
            if (sum > value)
            {
                // delete_node(head, value);
            }
        }

        print_link_list(head);
    }
    // print_link_list_size(head);
    // cout << sum;

    return 0;
}