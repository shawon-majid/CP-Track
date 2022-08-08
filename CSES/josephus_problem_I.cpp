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
 
node* append(node* x, int val){
    node *newNode = new node();
    newNode -> val = val;
    newNode -> next = NULL;
    x -> next = newNode;
    return newNode;
}
 
 
void makeCircle(){
    node *currentNode = root;
    // make current node last node
    while(currentNode -> next != NULL){
        currentNode = currentNode -> next;
    }
 
    currentNode -> next = root;
 
}
 
void printList(node* root){
    int k = 0;
    node* currentNode = root;
    while(currentNode -> next != NULL && k <= 100){
        cout << currentNode-> val << " -> ";
        currentNode = currentNode->next;
        k++;
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
 
node* deleteSecondNode(node* x){
 
 
    node* currentNode = x;
    node* prevNode = NULL;
    if(currentNode -> next != NULL){
        prevNode = currentNode;
        currentNode = currentNode -> next;
    }
 
 
    cout << currentNode -> val << " ";
 
    node* nextNode = NULL;
 
    if(currentNode -> next != NULL ) nextNode = currentNode -> next;
 
    // delete current node
 
    prevNode -> next = nextNode;
 
    return nextNode;
    
}
 
 
int main(){
 
 
    root = new node();
    root -> val = 1;
 
    int n;
    cin >> n;
 
    node* currentNode;
 
    currentNode = root;
 
    for(int i = 2; i <= n; i++){
        currentNode = append(currentNode, i);
    }
 
    // append(1);
 
    makeCircle();
    currentNode = root;
    for(int i = 0; i < n; i++){
        currentNode = deleteSecondNode(currentNode);
    }
    // printList(currentNode);
    return 0;
}