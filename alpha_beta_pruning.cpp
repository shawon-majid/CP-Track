//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

int minimax(int currentDepth, int totalHeight, int index, int alpha, int beta, bool isMax, vector<int> &leaves) {
    if (currentDepth == totalHeight) {
        return leaves[index];
    }

    if (isMax) { // maximizing move
        int maxValue = INT_MIN;
        maxValue = max(maxValue, minimax(currentDepth + 1, totalHeight, 2 * index, alpha, beta, false, leaves));
        if (beta <= alpha) {
            return maxValue; // Prune the remaining branches
        }
        maxValue = max(maxValue, minimax(currentDepth + 1, totalHeight, 2 * index + 1, alpha, beta, false, leaves));
        return maxValue;
    } else { // minimizing move
        int minValue = INT_MAX;
        minValue = min(minValue, minimax(currentDepth + 1, totalHeight, 2 * index, alpha, beta, true, leaves));
        if (beta <= alpha) {
            return minValue; // Prune the remaining branches
        }
        minValue = min(minValue, minimax(currentDepth + 1, totalHeight, 2 * index + 1, alpha, beta, true, leaves));
        return minValue;
    }
}

int main() {
    int number_of_leaf;
    cout << "Enter the number of leaf (must be a power of 2): ";
    cin >> number_of_leaf;

    cout << "Enter the leaves:\n";
    vector<int> leaves(number_of_leaf);

    for (int i = 0; i < number_of_leaf; i++) {
        cin >> leaves[i];
    }

    bool isMax;
    cout << "Press 1 if maximizer plays the first move\nPress 0 if minimizer plays the first move\n: ";
    cin >> isMax;

    int totalHeight = log2(number_of_leaf);
    int alpha = INT_MIN;
    int beta = INT_MAX;

    cout << "The answer is: ";
    cout << minimax(0, totalHeight, 0, alpha, beta, isMax, leaves) << "\n";

    return 0;
}
