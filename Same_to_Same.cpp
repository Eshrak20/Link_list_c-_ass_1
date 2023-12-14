#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int sum_1 = 0;
int sum_2 = 0;
int x = 1;
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
void Insert_value_2(Group *&head_2, Group *&tail_2, int value_2)
{

    Group *newNode_2 = new Group(value_2);
    if (head_2 == NULL)
    {
        head_2 = newNode_2;
        tail_2 = newNode_2;
        return;
    }
    tail_2->next = newNode_2;
    tail_2 = newNode_2;
};
void print_link_list(Group *head, Group *head_2)
{

    Group *temp = head;
    Group *temp_2 = head_2;
    Group *m = head;
    Group *n = head_2;

    while (m != NULL)
    {
        sum_1++;
        m = m->next;
    }
    while (n != NULL)
    {
        sum_2++;
        n = n->next;
    }
    if (sum_1 == sum_2)
    {
        while (temp != NULL && temp_2 != NULL)
        {

            if (temp->value != temp_2->value)
            {
                x = 0;
            }

            temp = temp->next;
            temp_2 = temp_2->next;
        }
    }
    else
    {
        x = 0;
    }
};

int main()
{
    int input, input_2;
    Group *head = NULL;
    Group *tail = NULL;
    Group *head_2 = NULL;
    Group *tail_2 = NULL;

    while (true)
    {

        cin >> input;
        if (input == -1)
        {
            break;
        }

        Insert_value(head, tail, input);
    }
    while (true)
    {

        cin >> input_2;
        if (input_2 == -1)
        {
            break;
        }

        Insert_value_2(head_2, tail_2, input_2);
    }

    print_link_list(head, head_2);
    if (x == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}