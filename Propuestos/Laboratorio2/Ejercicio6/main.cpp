#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define all(c) (c).begin(), (c).end()

const int n = 3;

vector<vector<int>> generatePermutations(int n);
void printPermutations(vector<vector<int>>&);

int main() {
    vector<vector<int>> permutations = generatePermutations(n);
    printPermutations(permutations);
    return 0;
}

vector<vector<int>> generatePermutations(int n) {
    vector<vector<int>> permutations;
    vector<int> permutation(n);
    for(int i = 0; i < n; i++)
        permutation[i] = i + 1;
    do {
        vector<int> tmp(n);
        for(int i = 0; i < n; i++)
            tmp[i] = permutation[i];
        permutations.push_back(tmp);
    } while(next_permutation(all(permutation)));
    return permutations;
}

void printPermutations(vector<vector<int>>& permutations) {
    for(vector<int>& p: permutations) {
        for(int& e: p)
            cout << e << " ";
        cout << "\n";
    }
}
