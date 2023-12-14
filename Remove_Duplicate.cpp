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

void print_link_list(Group *head)
{
    Group *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    Group *temp_2 = head;
    while (temp_2 != NULL)
    {
        cout << temp_2->value << " ";
        temp_2 = temp_2->next;
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