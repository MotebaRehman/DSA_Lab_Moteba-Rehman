#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

//Task 7
vector<int> findAllIndices(int arr[], int n, int key) {
    vector<int> indices;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}

//Task 8
int naivePatternMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return -1;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) return i;
    }
    return -1;
}

//Test Functions
void testFindAllIndices() {
    cout << "Testing Task 7: Find All Indices\n";

    int arr1[] = {1, 2, 3, 2, 4};
    vector<int> res1 = findAllIndices(arr1, 5, 2);
    assert(res1.size() == 2);
    cout << "Test 1 passed\n";

    int arr2[] = {1, 3, 5};
    vector<int> res2 = findAllIndices(arr2, 3, 4);
    assert(res2.empty());
    cout << "Test 2 passed\n";

    int arr3[] = {};
    vector<int> res3 = findAllIndices(arr3, 0, 1);
    assert(res3.empty());
    cout << "Test 3 passed\n\n";
}

void testPatternMatch() {
    cout << "Testing Task 8: Naive Pattern Matching\n";

    string text = "hello world";
    assert(naivePatternMatch(text, "hello") == 0);
    cout << "Test 1 passed\n";

    assert(naivePatternMatch(text, "world") == 6);
    cout << "Test 2 passed\n";

    assert(naivePatternMatch(text, "abc") == -1);
    cout << "Test 3 passed\n";

    assert(naivePatternMatch(text, "") == -1);
    cout << "Test 4 passed\n\n";
}

int main() {
    testFindAllIndices();
    testPatternMatch();
    cout << "All tests completed successfully!\n";
    return 0;
}