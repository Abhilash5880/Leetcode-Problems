
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {

    int A=0;
    int B=0;

    while(A<nums.size() && B<nums.size())
    {
        if((A==0 && B==0) || (nums[A]==0 && nums[B]==0))
        {
            A++; //initialize by moving A first
        }

        else if(nums[B]==0 && nums[A]!=0)
        {
            int temp=nums[B];
            nums[B]=nums[A];
            nums[A]=temp;
            A++;
            B++;
        }

        else if((nums[B]!=0 && nums[A]==0) || ((nums[B]!=0 && nums[A]!=0)))
        {
            A++;
            B++;
        }

    }
        
    }
};