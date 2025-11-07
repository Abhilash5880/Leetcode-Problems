#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> // Need this for strlen



typedef struct Trie {
    bool end;
    struct Trie* child[26];
} Trie;


Trie* trieCreate() 
{
    Trie* root = (Trie*)malloc(sizeof(Trie));
    
    if (root == NULL) return NULL; 

    root->end = false;

    for (int i = 0; i < 26; i++) 
    {
        root->child[i] = NULL;
    }

    return root;

}

void trieInsert(Trie* obj, char* word) 
{
    int idx=0;
    Trie* node=obj;
    for(int i=0; i<strlen(word); i++)
    {
        idx=word[i]-'a';
        if(!node->child[idx])
        {
            node->child[idx]=trieCreate();
        }
        node=node->child[idx];
    }
    node->end=true;
}

bool trieSearch(Trie* obj, char* word) 
{

    int idx=0;
    Trie* node=obj;
    for(int i=0;i<strlen(word); i++)
    {
        idx=word[i]-'a';
        if(!node->child[idx])
        {
            return false;
        }
        node=node->child[idx];
    }
    
    // FIX 1: Check the 'end' flag of the final node
    return node->end;     
}

bool trieStartsWith(Trie* obj, char* prefix) 
{
     int idx=0;
    Trie* node=obj;
    for(int i=0;i<strlen(prefix); i++)
    {
        idx=prefix[i]-'a';
        if(!node->child[idx])
        {
            return false;
        }
        node=node->child[idx];
    }
    
    // FIX 2: Return true only after the loop completes
    return true;    
}

void trieFree(Trie* obj) 
{
    if (obj == NULL) return;

    // FIX 3: Recursively free all children
    for(int i = 0; i < 26; i++)
    {
        if (obj->child[i])
        {
            trieFree(obj->child[i]); // Recursive call
        }
    }
    
    // FIX 3: Free the current node itself
    free(obj);
    
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/