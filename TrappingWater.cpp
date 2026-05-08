class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int l = 0;
        int r = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while (l < r)
        {
            // 🔹 Update maximum walls seen so far
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            // 🔹 Left side is guaranteed computable
            if (leftMax < rightMax)
            {
                // Water trapped at left index
                water += leftMax - height[l];

                // Move inward
                l++;
            }
            else
            {
                // Water trapped at right index
                water += rightMax - height[r];

                // Move inward
                r--;
            }
        }

        return water;
    }
};