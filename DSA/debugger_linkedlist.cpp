#include <iostream>
#include<string>
using namespace std;
struct Node {
    string name;
    string post;
    Node* next;

    Node(string n,string p){
		this->name = n;
		this->post = p;
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
    void insert(string name,string post) {
        Node* newNode = new Node(name,post);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void insertAtbeginning(string name,string post){
    	Node* newnode=new Node(name,post);
    	
    	newnode->next=head;
    	head=newnode;
    }
    
    void insertAtpos(string name,string post, int pos){
    	Node* newnode=new Node(name,post);
    	Node* temp=head;
    	int i=1;
    	
    	while(temp!=nullptr && i<pos-1){
    		temp=temp->next;
    		i++;
    	}
    	
    	newnode->next=temp->next;
    	temp->next=newnode;
    }
    void deleteAtbeginnig(){
    	Node* temp=head;
    	head=temp->next;
    	delete temp;	
    }
    void deleteatpos(string name){
    	Node *temp=head;
    	
    	while(temp->next){
    		if(temp->next->name==name){
    			Node* dtemp=temp->next;
    			temp->next=temp->next->next;
    			delete dtemp;
    		}
    		
    		temp=temp->next;
    	}
    	
    	
    	
    }
    void display(){
		Node* temp = head;
		while(temp){
			cout<<"Name: "<<temp->name<<" Post: "<<temp->post<<endl;
			temp = temp->next;
		}
	}
};
int main() {
    LinkedList list;
    list.insertAtbeginning("Kundan ","a");
    list.insert("Jay Shinde","b");
    list.insertAtpos("Bhumi jha","d" ,2);
    list.insert("Swayam dusing" , "Vice-c");
    cout << "Linked List: "<<endl;
    list.display();
    //list.deleteAtbeginnig();
    list.deleteatpos("Jay Shinde");
    cout << "Linked List: "<<endl;
    list.display();
    return 0;
}