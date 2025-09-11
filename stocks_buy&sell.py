'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
'''
#solution works but time limit exceeded - not accepted
'''class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit=0
        for i in range(len(prices),1):
            
            for j in range(i+1,len(prices),1):
                if(prices[i]<prices[j]):
                    if(profit<prices[j]-prices[i]):
                        profit=prices[j]-prices[i]
                else:
                    continue
        
        return profit
'''
# Beats : 70%(time complexity) 35% (space complexity)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_price = prices[0]
        profit = 0

        for p in prices[1:]:
            if buy_price > p:
                buy_price = p
            
            profit = max(profit, p - buy_price)
        
        return profit
            