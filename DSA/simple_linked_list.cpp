#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList();

    // Create linked list manually by taking user input
    void createList(int n);

    // Display List
    void display();

    // Destructor to free memory
    ~LinkedList();
};

// Constructor
LinkedList::LinkedList()
{
    head = nullptr;
}

// Create linked list manually
void LinkedList::createList(int n)
{
    if (n <= 0)
    {
        cout << "Invalid number of elements!" << endl;
        return;
    }

    cout << "Enter element 1: ";
    int value;
    cin >> value;

    head = new Node(value);
    Node *temp = head;

    for (int i = 2; i <= n; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> value;

        temp->next = new Node(value);
        temp = temp->next;
    }
}

void LinkedList::display()
{
    if (!head)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

LinkedList::~LinkedList()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// Driver Code
int main()
{
    LinkedList list;

    int n;
    cout << "Enter number of elements to insert: ";
    cin >> n;

    list.createList(n);

    cout << "Linked List: ";
    list.display();

    return 0;
}
