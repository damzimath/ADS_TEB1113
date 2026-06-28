#include <iostream>
#include <string>
#include <cctype> // Required for isalnum() and tolower()

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare the characters in lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move both pointers inward
            left++;
            right--;
        }
        
        return true;
    }
};

// Your compiler needs this main() function to start the program!
int main() {
    // 1. Create an instance of your Solution class
    Solution mySolution;

    // 2. Set up the test strings
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    string test3 = " ";

    // 3. Print the results
    // Note: 'boolalpha' tells C++ to print "true" or "false" instead of "1" or "0"
    cout << boolalpha; 
    
    cout << "Test 1: " << mySolution.isPalindrome(test1) << " (Expected: true)" << endl;
    cout << "Test 2: " << mySolution.isPalindrome(test2) << " (Expected: false)" << endl;
    cout << "Test 3: " << mySolution.isPalindrome(test3) << " (Expected: true)" << endl;

    return 0;
}