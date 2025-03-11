#include <iostream>
#include<string>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
	Node(int value){
		data=value;
		next=nullptr;
	}
};

class linkedlist{
	public:
		Node*head;
		 linkedlist(){
		 	head=nullptr;
		 }
		 
		 void insert(int data){
		 	Node* newnode=new Node(data);
		 	if(!head){
		 		head=newnode;
		 		return;
		 	}
		 	
		 	Node* temp=head;
		 	while(temp->next!=NULL){
		 		temp=temp->next;
		 	}
		 	
		 	temp->next=newnode;
		 }
		 
		 void display(){
		 if(head==nullptr){
		 	cout<<"Empty list!!";
		 }
		 	Node* temp=head;
			while(temp!=NULL){
				cout<<temp->data << " -> " ;
				temp=temp->next;
			}
			cout<<endl;
		 }
		 
		 void concat(linkedlist l2){
		 	Node* temp=head;
		 	if(head ==NULL){
		 		head=l2.head;
		 		l2.head=NULL;
		 		return;
		 	}
		 	
		 	while(temp->next !=NULL){
		 		temp=temp->next;
		 	}
		 	temp->next=l2.head;
		 	l2.head=NULL;
		 	
		 }
		 void reverse(){
		 	Node* prev=head;
		 	Node* current=prev->next;
		 	
		 	while(current !=NULL){
		 	Node* newnode=current->next;
		 		current->next=prev;
		 		prev=current;
		 		current=newnode;
		 	}
		 	head->next=NULL;
		 	head=prev;
		 } 
		 
		 void deleteall(){
		 	Node* current = head;
		 	Node* next;
		 	
		 	while(current){
		 		next=current->next;
		 		delete current;
		 		current=next;
		 	}
		 	head=NULL;
		 }
		 
		 
};

int main(){
	linkedlist l1,l2;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	
	l2.insert(4);
	l2.insert(5);
	l2.insert(6);
	l2.display(); 
	
	
	//l1.concat(l2);
	
	l1.reverse();
	l1.display();
	
	l1.deleteall();
	l1.display();
	
}
