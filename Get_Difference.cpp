#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int global_max = INT_MIN;
int global_min = INT_MAX;

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
void print_link_list(Group *head)
{

    Group *temp = head;
    while (temp != NULL)
    {
        if (temp->value > global_max)
        {
            global_max = temp->value;
        }

        if (temp->value < global_min)
        {
            global_min = temp->value;
        }

        temp = temp->next;
    }
    int sum = global_max - global_min;
    cout << abs(sum) << " ";
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