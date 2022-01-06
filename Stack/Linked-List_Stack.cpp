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

    cout << "노드 삽입: " << "[ " << node->data << " ]" << endl;
}

void Top()
{
    if (top != NULL)
    {
        cout << "마지막 노드: " << "[ " << top->data << " ]" << endl;
    }
    else
    {
        cout << "마지막 노드가 비었습니다." << endl;
    }
    cout << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "스택이 언더플로우입니다." << endl;
    }
    else
    {
        cout << "노드 삭제: " << "[ " << top->data << " ]" << endl;
        top = top->next;
    }
}

void display()
{
    Node* ptr;
    if (top == NULL)
    {
        cout << "스택이 비어있습니다.";
    }
    else
    {
        ptr = top;
        cout << "\n스택: ";
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
