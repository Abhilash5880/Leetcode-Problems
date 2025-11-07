#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Use stdbool for the bool type

// Function Declaration: MUST be defined outside and declared before its first use
bool visit(char** board, char* word, int start, int x, int y, 
           int R, int C, bool** visited);

// Main function to check if the word exists on the board
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    // R = Row count (boardSize), C = Column count (*boardColSize)
    int R = boardSize;
    int C = *boardColSize;
    int W_len = (int)strlen(word);
    
    // 1. Length Check
    if (W_len > R * C) {
        return false;
    }

    // 2. Allocate and initialize the 2D visited array
    bool** visited = (bool**)malloc(R * sizeof(bool*));
    if (visited == NULL) return false;
    
    for (int i = 0; i < R; i++) {
        // Use calloc to allocate C elements and initialize them to 0 (false)
        visited[i] = (bool*)calloc(C, sizeof(bool));
        if (visited[i] == NULL) {
            // Memory cleanup on failure
            for (int k = 0; k < i; k++) free(visited[k]);
            free(visited);
            return false;
        }
    } // <-- MISSING BRACE FIXED HERE

    // 3. Character Count Check
    int counts[256] = {0}; // Local array for counts

    // Count board characters
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            counts[(unsigned char)board[i][j]]++;
        }
    }

    // Check word characters against board counts
    for (int i = 0; i < W_len; i++) {
        if (--counts[(unsigned char)word[i]] < 0) {
            // Free memory before returning false
            for (int k = 0; k < R; k++) free(visited[k]);
            free(visited);
            return false; 
        }
    }

    // 4. Start DFS from every cell
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // Remove the semicolon after the if condition!
            if (visit(board, word, 0, i, j, R, C, visited)) {
                // Free memory before returning success
                for (int k = 0; k < R; k++) free(visited[k]);
                free(visited);
                return true;
            }
        }
    }

    // 5. Cleanup and final return
    for (int k = 0; k < R; k++) free(visited[k]);
    free(visited);
    
    return false; // Word not found
}

// Helper function to recursively search for the word
bool visit(char** board, char* word, int start, int x, int y, 
           int R, int C, bool** visited) {
    
    // Base case 1: Word completely found
    if (start == strlen(word)) {
        return true;
    }

    // Base case 2: Check for out-of-bounds, already visited, or character mismatch
    if (x < 0 || x >= R || y < 0 || y >= C || visited[x][y] || word[start] != board[x][y]) {
        return false;
    }

    // Mark current cell as visited
    visited[x][y] = true;

    // Recursive search in four directions
    bool found = visit(board, word, start + 1, x + 1, y, R, C, visited) // Down
              || visit(board, word, start + 1, x - 1, y, R, C, visited) // Up
              || visit(board, word, start + 1, x, y + 1, R, C, visited) // Right
              || visit(board, word, start + 1, x, y - 1, R, C, visited); // Left
    
    // Backtrack: Unmark current cell
    visited[x][y] = false;

    return found;
}