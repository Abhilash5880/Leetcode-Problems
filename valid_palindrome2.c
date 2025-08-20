/*#include <string.h>
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
}*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char* onlyAlpha(char* str) 
{
    int read_idx, write_idx = 0;

    for (int i = 0; str[read_idx] != '\0'; read_idx++) {
        if (isalpha(str[read_idx])) {
            str[write_idx] = str[read_idx];
            write_idx++;
        }
    }
    str[write_idx] = '\0'; // Add null terminator

    printf("Resulting String: %s\n", str);
    
    return str;
}

bool isPalindrome(char * s)
{
    if(s == NULL)
    {
        return true;
    }
    char* str1="";
    str1=onlyAlpha(s);
    if(strlen(str1)%2==0)
    {
        int left=0;
        int right=strlen(str1)-1;
        bool palin=true;

        while(left<=((strlen(str1)%2)-1) && right<= ((strlen(str1)%2)+1))
        {
            if(str1[left]==str1[right])
            {
                palin=true;
            }
            else
            {
                palin=false;
                return palin;
            }
            left++;
            right--;
        }
        return true;
    }
    if(strlen(str1)%2!=0)
    {
        int left=0;
        int right=strlen(str1)-1;
        bool palin=true;

        while(left<=(strlen(str1)%2) && right<= ((strlen(str1)%2)+2))
        {
            if(str1[left]==str1[right])
            {
                palin=true;
            }
            else
            {
                palin=false;
                return palin;
            }
            left++;
            right--;
        }
        return true;
    }
}
