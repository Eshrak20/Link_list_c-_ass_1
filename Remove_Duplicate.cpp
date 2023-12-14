#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
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
void Insert_value(Group *&head, Group *&tail, int value)
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
void delete_node(Group *start, int val)
{
    Group *tmp2 = start;
    while (tmp2->next != NULL)
    {
        if (tmp2->next->value == val)
        {
            // Group *deleteNode = tmp2->next;
            // tmp2->next = deleteNode->next;
            // delete deleteNode;
            cout << tmp2->next->value << " ";
        }
    }
}
void print_link_list(Group *head)
{
    Group *temp = head;
    while (temp != NULL)
    {
        delete_node(temp, temp->value);

        temp = temp->next;
    }
};
int main()
{
    int input;
    Group *head = NULL;
    Group *tail = NULL;
    while (true)
    {
        cin >> input;
        if (input == -1)
        {
            break;
        }
        Insert_value(head, tail, input);
    }
    print_link_list(head);
    return 0;
}