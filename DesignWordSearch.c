
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> // Need this for strlen



typedef struct WordDictionary {
    bool end;
    struct WordDictionary* child[26];
} WordDictionary;


WordDictionary* wordDictionaryCreate() 
{
   WordDictionary* root = (WordDictionary*)malloc(sizeof(WordDictionary));
    
    if (root == NULL) return NULL; 

    root->end = false;

    for (int i = 0; i < 26; i++) 
    {
        root->child[i] = NULL;
    }

    return root;

}

void wordDictionaryAddWord(WordDictionary* obj, char* word)
{
    int idx=0;
    WordDictionary* node=obj;
    for(int i=0; i<strlen(word); i++)
    {
        idx=word[i]-'a';
        if(!node->child[idx])
        {
            node->child[idx]=wordDictionaryCreate();
        }
        node=node->child[idx];
    }
    node->end=true;
}

bool wordDictionarySearch(WordDictionary* obj, char* word) 
{

    int idx=0;
    WordDictionary* node=obj;
    for(int i=0;i<strlen(word); i++)
    {
        idx=word[i]-'a';
        if(word[i]=='.')
        {
            return true;
        }
        
        else if(!node->child[idx])
        {
            return false;
        }
        else
        {
            node=node->child[idx];
        }
    }
    
    // FIX 1: Check the 'end' flag of the final node
    return node->end;     
}



void wordDictionaryFree(WordDictionary* obj)
{
    if (obj == NULL) return;

    // FIX 3: Recursively free all children
    for(int i = 0; i < 26; i++)
    {
        if (obj->child[i])
        {
            wordDictionaryFree(obj->child[i]); // Recursive call
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
//////////////////////////////////////////////////

/*typedef struct {
    
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
    
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
    
}

void wordDictionaryFree(WordDictionary* obj) {
    
}


 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/