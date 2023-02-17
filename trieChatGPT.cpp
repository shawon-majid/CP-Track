#include <map>
#include <string>
#include <iostream>

// Trie class definition
class Trie {
 public:
  // Constructor initializing count to 0
  Trie() : count(0) {}

  // Method to insert a word in the trie
  void insert(std::string word) {
    // Start from the root node
    Trie* node = this;
    // Iterate through each character in the word
    for (char c : word) {
      // If the current character is not present as a child of the node
      if (!node->children.count(c)) {
        // Add the current character as a child to the node
        node->children[c] = new Trie();
      }
      // Move to the child node corresponding to the current character
      node = node->children[c];
      // Increment the count for the node
      node->count++;
    }
    // Mark the end of the word at the last node
    node->is_end = true;
  }

  // Method to search for a word in the trie
  int search(std::string word) {
    // Start from the root node
    Trie* node = this;
    // Iterate through each character in the word
    for (char c : word) {
      // If the current character is not present as a child of the node
      if (!node->children.count(c)) {
        // Return 0 as the word is not present in the trie
        return 0;
      }
      // Move to the child node corresponding to the current character
      node = node->children[c];
    }
    // Return the count for the node corresponding to the last character of the word
    return node->count;
  }

 private:
  // Map to store the children of a node, with key as the character and value as the node pointer
  std::map<char, Trie*> children;
  // Boolean flag to mark the end of a word
  bool is_end = false;
  // Integer to store the count of nodes
  int count;
};

int main() {
  Trie trie;
  trie.insert("hello");
  trie.insert("hey");
  trie.insert("hi");
  std::cout << "Count for prefix 'h': " << trie.search("h") << std::endl;
  std::cout << "Count for prefix 'he': " << trie.search("he") << std::endl;
  std::cout << "Count for prefix 'hel': " << trie.search("hel") << std::endl;
  std::cout << "Count for word 'hello': " << trie.search("hello") << std::endl;
  return 0;
}
