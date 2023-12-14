#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int global_max = INT_MIN;
int global_min = INT_MAX;
int flag = 0;
long long int sum = 0;

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
void print_link_list(Group *head, int check)
{

    Group *temp = head;
    while (temp != NULL)
    {
        if (temp->value == check)
        {
            cout << sum << endl;
            flag = 1;
            break;
        }
        sum++;
        temp = temp->next;
    }
    if (flag == 0)
    {
        cout << -1 << endl;
    }
};

int main()
{
    long long int input, q, check;
    cin >> q;
    Group *head = NULL;
    Group *tail = NULL;
    for (int i = 0; i < q; i++)
    {
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
        cin >> check;
        print_link_list(head, check);
        flag = 0;
        sum = 0;
    }

    return 0;
}