#include <string.h>
#include <ctype.h> // For isalnum and tolower
#include <stdbool.h> // For bool type

bool isPalindrome(char * s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare alphanumeric characters (case-insensitive)
        if (left < right && tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        // Move pointers inwards
        left++;
        right--;
    }

    return true;
}