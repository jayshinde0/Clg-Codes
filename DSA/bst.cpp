#include <iostream>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node *left, *right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

class bstree {
public:
    node *root;
    bstree() {
        root = NULL;
    }

    void create(int val) {
        cout << "Creating root with value " << val << endl;
        root = new node(val);
    }

    void insert(int val) {
        if (root == NULL) {
            create(val);
            return;
        }
        node *p = new node(val);
        node *temp = root;

        while (temp != NULL) {
            if (p->data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = p;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (p->data > temp->data) {
                if (temp->right == NULL) {
                    temp->right = p;
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                cout << "Already inserted " << p->data << endl;
                delete p;
                break;
            }
        }
    }

    void inorder(node *root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void postorder(node *root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    void preorder(node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    int findMin() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return -1;
        }
        node *temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp->data;
    }

    int findMax() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return -1;
        }
        node *temp = root;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp->data;
    }

    void preorder_non_recursive() {
        if (root == NULL)
            return;
        stack<node *> s;
        node *tmp = root;
        while (true) {
            while (tmp != NULL) {
                cout << tmp->data << " ";
                s.push(tmp);
                tmp = tmp->left;
            }
            if (s.empty())
                return;
            tmp = s.top();
            s.pop();
            tmp = tmp->right;
        }
    }

    void inorder_non_recursive() {
        stack<node *> s;
        node *tmp = root;
        while (true) {
            while (tmp != NULL) {
                s.push(tmp);
                tmp = tmp->left;
            }
            if (s.empty())
                return;
            tmp = s.top();
            s.pop();
            cout << tmp->data << " ";
            tmp = tmp->right;
        }
    }

    void postorder_non_recursive() {
        if (root == NULL)
            return;
        stack<node *> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    int height(node *nodePtr) {
        if (nodePtr == NULL)
            return 0;
        int leftH = height(nodePtr->left);
        int rightH = height(nodePtr->right);
        return max(leftH, rightH) + 1;
    }

    bool search(node *nodePtr, int key) {
        if (nodePtr == NULL)
            return false;
        if (nodePtr->data == key)
            return true;
        else if (key < nodePtr->data)
            return search(nodePtr->left, key);
        else
            return search(nodePtr->right, key);
    }
};

int main() {
    bstree b;
    int choice, val;

    do {
        cout << "\n=== BST Menu ===\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Find Min\n";
        cout << "6. Find Max\n";
        cout << "7. Search\n";
        cout << "8. Height of Tree\n";
        cout << "9. Preorder (Non-Recursive)\n";
        cout << "10. Inorder (Non-Recursive)\n";
        cout << "11. Postorder (Non-Recursive)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                b.insert(val);
                break;

            case 2:
                b.inorder(b.root);
                cout << endl;
                break;

            case 3:
                b.preorder(b.root);
                cout << endl;
                break;

            case 4:
                b.postorder(b.root);
                cout << endl;
                break;

            case 5:
                cout << "Min Node: " << b.findMin() << endl;
                break;

            case 6:
                cout << "Max Node: " << b.findMax() << endl;
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> val;
                if (b.search(b.root, val))
                    cout << "Found\n";
                else
                    cout << "Not Found\n";
                break;

            case 8:
                cout << "Height: " << b.height(b.root) << endl;
                break;

            case 9:
                b.preorder_non_recursive();
                cout << endl;
                break;

            case 10:
                b.inorder_non_recursive();
                cout << endl;
                break;

            case 11:
                b.postorder_non_recursive();
                cout << endl;
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
