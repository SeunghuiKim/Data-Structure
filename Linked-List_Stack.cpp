#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* top = NULL;

void push(int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = top;
    top = node;

    cout << "��� ����: " << "[ " << node->data << " ]" << endl;
}

void Top()
{
    if (top != NULL)
    {
        cout << "������ ���: " << "[ " << top->data << " ]" << endl;
    }
    else
    {
        cout << "������ ��尡 ������ϴ�." << endl;
    }
    cout << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "������ ����÷ο��Դϴ�." << endl;
    }
    else
    {
        cout << "��� ����: " << "[ " << top->data << " ]" << endl;
        top = top->next;
    }
}

void display()
{
    Node* ptr;
    if (top == NULL)
    {
        cout << "������ ����ֽ��ϴ�.";
    }
    else
    {
        ptr = top;
        cout << "\n����: ";
        while (ptr != NULL)
        {
            cout << "[ " << ptr->data << " ]" << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

int main()
{
    display();
    Top();

    push(12);
    push(56);
    push(90);

    display();
    Top();

    pop();
    pop();

    display();
    Top();

    push(34);
    push(78);

    display();
    Top();
}