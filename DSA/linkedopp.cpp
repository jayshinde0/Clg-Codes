#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAtPosition(int value, int position);

    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int position);

    void display();

    ~LinkedList();
};

void LinkedList::insertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insertAtPosition(int value, int position) {
    if (position <= 0) {
        cout << "Invalid position!\n";
        return;
    }

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void LinkedList::deleteFromPosition(int position) {
    if (head == nullptr || position <= 0) {
        cout << "Invalid position or list is empty!\n";
        return;
    }

    if (position == 1) {
        deleteFromBeginning();
        return;
    }

    Node* temp = head;
    for (int i = 1; temp->next != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Position out of range!\n";
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}

void LinkedList::display() {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    LinkedList list;
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> value >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
