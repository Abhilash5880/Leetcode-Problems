int climbStairs(int n) 
{
    int x,y,sum;
    
    x=1;     //DP[1]
    y=2;     //DP[2]
    
    if(n>3)
    {
        for(int i=0;i<n-2;i++)
        {
            // DP[n]=DP[N-1]+DP[N-2]

            sum=x+y;
            x=y;
            y=sum;
        }
        return sum;
    }
    return (n == 1) ? 1 : (n == 2) ? 2 : 3;
    
}