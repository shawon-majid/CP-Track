//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

struct node{
	int val;
	node* next;
};

node *root = NULL;

void append(int val){
	
	node *currentNode = root;
	while(currentNode->next != NULL){
		currentNode = currentNode -> next;	
	}
	node *newNode = new node();
	newNode -> val = val;
	newNode -> next = NULL;
	currentNode -> next = newNode;

}


void printList(node* root){
	node* currentNode = root;
	while(currentNode -> next != NULL){
		cout << currentNode-> val << " -> ";
		currentNode = currentNode->next;
	}
	cout << currentNode -> val << endl;
}


void deleteNode(int toDelete){
	node *currentNode = root;

	if(currentNode -> val == toDelete){
		root = currentNode->next;
		return;
	}

	node* prevNode = root;
	currentNode = root -> next;

	while(currentNode -> val != toDelete){
		prevNode = currentNode;
		currentNode = currentNode -> next;
	}

	prevNode->next = currentNode->next;

}


int main(){


	root = new node();
	root -> val = 10;

	append(11);
	append(12);
	append(13);

	printList(root);
	deleteNode(10);
	deleteNode(12);

	printList(root);


    return 0;
}