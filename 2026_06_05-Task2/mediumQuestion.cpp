#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        // Start from 1 since ans[0] is always 0
        for (int i = 1; i <= n; i++) {
            // i >> 1 is the same as i / 2
            // i & 1 is the same as i % 2 (gets the last bit)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};

// A quick helper function to print vectors neatly to the console
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

// The main function your compiler needs to start the program
int main() {
    // 1. Create an instance of your Solution class
    Solution mySolution;

    // 2. Set up the test cases
    int n1 = 2;
    int n2 = 5;

    // 3. Run the solution
    vector<int> result1 = mySolution.countBits(n1);
    vector<int> result2 = mySolution.countBits(n2);

    // 4. Print the results
    cout << "--- Counting Bits Tests ---" << endl;
    
    cout << "Test 1 (n = " << n1 << ")\nOutput:   ";
    printVector(result1);
    cout << "\nExpected: [0, 1, 1]\n\n";

    cout << "Test 2 (n = " << n2 << ")\nOutput:   ";
    printVector(result2);
    cout << "\nExpected: [0, 1, 1, 2, 1, 2]\n" << endl;

    return 0;
}