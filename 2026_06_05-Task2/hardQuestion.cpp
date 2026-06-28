#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[i] will store the max floors we can check with i eggs
        // for the current number of moves.
        vector<int> dp(k + 1, 0);
        int moves = 0;
        
        // Keep adding moves until the max floors we can check with k eggs is >= n
        while (dp[k] < n) {
            moves++;
            // Update backwards to use the values from the previous move (m-1)
            for (int i = k; i > 0; i--) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
        }
        
        return moves;
    }
};

// The main function is required to run the program locally
int main() {
    // 1. Create an instance of your Solution class
    Solution mySolution;

    // 2. Set up the test cases
    int k1 = 1, n1 = 2;
    int k2 = 2, n2 = 6;
    int k3 = 3, n3 = 14;

    // 3. Print the results and compare them to the expected outputs
    cout << "--- Super Egg Drop Tests ---" << endl;
    
    cout << "Test 1 (k=" << k1 << ", n=" << n1 << "): " 
         << mySolution.superEggDrop(k1, n1) << " moves (Expected: 2)" << endl;
         
    cout << "Test 2 (k=" << k2 << ", n=" << n2 << "): " 
         << mySolution.superEggDrop(k2, n2) << " moves (Expected: 3)" << endl;
         
    cout << "Test 3 (k=" << k3 << ", n=" << n3 << "): " 
         << mySolution.superEggDrop(k3, n3) << " moves (Expected: 4)" << endl;

    return 0;
}