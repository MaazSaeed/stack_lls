#include <iostream>

using namespace std;

struct Node
{
    char ch;
    Node* next;
    Node* prev;
};

class Stack
{
private:
    Node* top;
    Node* lastEntry;
    Node* recent;
public:
    Stack()
    {
        top = NULL;
        lastEntry = NULL;
        recent = NULL;
    }

    bool isEmpty()
    {
        if(top == NULL)
            return true;
        return false;
    }
    void push()
    {
        char ch;
        cout << "Enter character to push onto stack: ";
        cin >> ch;
        cout << endl;

        Node* newNode = new Node;

        newNode->next = top;
        newNode->ch = ch;
        newNode->prev = NULL;

        recent = newNode;

        if(!top)
            lastEntry = newNode;

        if(top)
            top->prev = recent;

        top = newNode;
    }

    void pop()
    {
        if(!top)
        {
            cout << "Stack empty!";
            return;
        }
        char c = top->ch;
        Node* t = top;
        top = top->next;
        delete t;
        cout << "Popped value -> [" << c << "]" << endl;
        return;
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "Stack empty!";
            return;
        }
        Node *t = top;
        while(t)
        {
            cout << "[" << t->ch << "]" << " -> ";
            t = t->next;
        }
        cout << "NULL";
    }

    void reverseStack()
    {
        if(!top)
        {
            cout << "Stack empty!";
            return;
        }
        Node* r = lastEntry;
        while(r)
        {
            cout << "[" << r->ch << "]" << " -> ";
            r = r->prev;
        }

        cout << "NULL";
    }

    void top_()
    {
        if(!top)
        {
            cout << "Stack empty!";
            return;
        }

        cout << "Top -> [" << top->ch  << "]" << endl << endl;
        return;
    }
};
int main()
{
    Stack s = Stack();
    for(;;)
    {
        int option;
        cout << "===== STACK =====\n";
        cout << "| 1-> Push      |\n";
        cout << "| 2-> Pop       |\n";
        cout << "| 3-> Display   |\n";
        cout << "| 4-> Top       |\n";
        cout << "| 5-> Reverse   |\n";
        cout << "| 6-> is empty? |\n";
        cout << "=================\n";
        cout << endl;
        cout << "Option: ";
        cin >> option;
        cout << endl;
        system("CLS");

        cout << "!@#$%--- OUTPUT ---%$#@!\n\n";
        switch(option)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            s.top_();
            break;
        case 5:
            s.reverseStack();
            break;
        case 6:
            string msg = s.isEmpty() ? "Stack is empty..." : "Stack is not empty...";
            cout << msg;
            break;
        }
        cout << "\n\n";
    }
    return 0;
}
