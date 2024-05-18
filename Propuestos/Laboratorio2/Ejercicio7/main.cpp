#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define SIZE(c) int((c).size())
#define all(c) (c).begin(), (c).end()

const int n = 3;

void sortSubsets(vector<vector<int>>&);
void generateSubsetsRecursive(int, int, vector<int>&, vector<vector<int>>&);
vector<vector<int>> generateSubsets(int);
void printSubsets(vector<vector<int>>&);

int main() {
    vector<vector<int>> subsets = generateSubsets(n);
    sortSubsets(subsets);
    printSubsets(subsets);
    return 0;
}

vector<vector<int>> generateSubsets(int n) {
    vector<vector<int>> subsets;
    vector<int> subset;
    generateSubsetsRecursive(0, n, subset, subsets);
    return subsets;
}

void generateSubsetsRecursive(int k, int n, vector<int>& subset, vector<vector<int>>& subsets) {
    if(k == n) {
        // process subset
        if(SIZE(subset) == 0) return;
        vector<int> tmp(SIZE(subset));
        for(int i = 0; i < SIZE(tmp); i++)
            tmp[i] = subset[i];
        subsets.push_back(tmp);
    } else {
        generateSubsetsRecursive(k + 1, n, subset, subsets);
        subset.push_back(k + 1);
        generateSubsetsRecursive(k + 1, n, subset, subsets);
        subset.pop_back();
    }
}

void sortSubsets(vector<vector<int>>& subsets) {
    sort(all(subsets),
        [](const vector<int>& a, const vector<int>& b) {
            return (SIZE(a) == SIZE(b))? a < b : SIZE(a) < SIZE(b);
        }
    );
}

void printSubsets(vector<vector<int>>& subsets) {
    for(const vector<int>& s: subsets) {
        for(const int& e: s)
            cout << e << " ";
        cout << "\n";
    }
}
