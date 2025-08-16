#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>

// Comparison function for qsort
int compare_chars(const void* a, const void* b) {
    int val1 = *(const char *)a;
    int val2 = *(const char *)b;
    return val1 - val2;
}

/*
int main() {
    char word[] = "example";
    size_t n = strlen(word);

    printf("Original word: %s\n", word);

    // Use qsort to sort the characters
    qsort(word, n, sizeof(char), compare_chars);

    printf("Sorted word: %s\n", word);

    return 0;
}
*/
bool isAnagram(char* s, char* t) 
{
    
    //if length is not matching then they are not anagrams
    if (strlen(s) != strlen(t)) 
    {
        return false;
    }
    qsort(s, strlen(s), sizeof(char), compare_chars);
    qsort(t, strlen(t), sizeof(char), compare_chars);
    if(strcmp(s,t)==0)
    {
        return true;
    }
    return false;
}