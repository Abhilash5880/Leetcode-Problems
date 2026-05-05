class Solution {
public:
    int getSum(int a, int b) {
        
        while (b != 0) {
            int carry = (a & b) << 1;  // 🔹 carry where both bits are 1
            a = a ^ b;                 // 🔹 sum without carry
            b = carry;                // 🔹 move carry to next iteration
        }
        
        return a;
    }
};