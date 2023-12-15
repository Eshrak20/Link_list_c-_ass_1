#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
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
void delete_fun(Group *head, int val)
{
    Group *tmp2 = head;
    while (tmp2->next != NULL)
    {
        if (tmp2 != NULL && tmp2->next->value == val)
        {
            Group *deleteNode = tmp2->next;
            if (tmp2->next->next == NULL)
            {
                // tmp2 = NULL;
                return;
            }
            else
            {
                tmp2->next = tmp2->next->next;
                delete deleteNode;
            }
        }
        tmp2 = tmp2->next;
    }
};
void print_link_list(Group *head)
{
    Group *temp = head;
    while (temp != NULL)
    {

        delete_fun(temp, temp->value);
        cout << temp->value << " ";
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
