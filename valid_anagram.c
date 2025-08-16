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

/* 0ms logic
c
bool isAnagram(char* s, char* t) {
    int lenS = strlen(s), lenT = strlen(t);
    if (lenS != lenT) return false;

    int count[26] = {0};
    for (int i = 0; i < lenS; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
} */