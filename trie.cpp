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
	bool isWord;
	int cnt;
	node* next[26+1];
	node(){
		isWord = false;
		cnt = 1;
		for(int i = 0; i <= 26; i++){
			next[i] = NULL;
		}
	}
};

node *root;

int getID(char c){
	return c-'a';
}

void insert_(string s){
	node* currentNode = root;
	for(int i = 0; i < s.size(); i++){
		int id = getID(s[i]);
		if(currentNode -> next[id] == NULL){
			currentNode -> next[id] = new node();
		}
		else{
			currentNode -> next[id] -> cnt++;
		}
		currentNode = currentNode->next[id];
	}
	currentNode -> isWord = true;
}


bool search_(string s){
	node* currentNode = root;
	for(int i = 0; i < s.size(); i++){
		int id = getID(s[i]);
		if(currentNode -> next[id] == NULL){
			return false;
		}
		currentNode = currentNode -> next[id];
	}

	return currentNode -> isWord;
}

bool searchPre(string s){
	node* currentNode = root;
	for(int i = 0; i < s.size(); i++){
		int id = getID(s[i]);
		if(currentNode -> next[id] == NULL){
			return false;
		}
		currentNode = currentNode -> next[id];
	}

	return true;
}

int main(){

	root = new node();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		insert_("911");

	}

	cin >> n;
	while(n--){
		string s;
		cin >> s;
		bool isWord = search_(s);
		cout << isWord << endl;
	}


    return 0;
}