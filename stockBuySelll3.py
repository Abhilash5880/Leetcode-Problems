def maxProfit(prices):
    if not prices:
        return 0
        
    # Initialize variables
    buy1_cost = float('inf')
    profit1 = 0
    buy2_cost = float('inf')
    profit2 = 0
    
    for price in prices:
        # 1. Minimize cost of first stock
        buy1_cost = min(buy1_cost, price)
        
        # 2. Maximize profit of first transaction
        profit1 = max(profit1, price - buy1_cost)
        
        # 3. Minimize effective cost of second stock 
        # (Price - Profit of first trade)
        buy2_cost = min(buy2_cost, price - profit1)
        
        # 4. Maximize total profit
        profit2 = max(profit2, price - buy2_cost)
        
    return profit2

# Test
prices = [4, 7, 2, 9, 1, 5, 3, 8, 6, 4, 7]
print(maxProfit(prices)) # Output: 14