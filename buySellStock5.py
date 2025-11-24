def max_profit(prices: list[int], fee: int) -> int:
    """
    Calculates the maximum profit achievable from multiple stock transactions 
    with a fixed fee, using Dynamic Programming with O(1) space complexity.

    Args:
        prices: A list of integers where prices[i] is the stock price on day i.
        fee: The transaction fee applied to every sell operation.

    Returns:
        The maximum total profit.
    """
    if not prices:
        return 0

    # Initialize DP states (O(1) space optimization):
    
    # cash: Max profit when you DO NOT hold a stock on the current day.
    # Initial state (Day 0): 0 profit, no stock held.
    cash = 0
    
    # hold: Max profit when you DO hold a stock on the current day.
    # Initial state (Day 0): Buy the first stock, profit reduces by the price.
    hold = -prices[0]

    # Iterate through the prices starting from Day 1
    for price in prices[1:]:
        
        # Calculate new states based on the transitions:
        
        # 1. New cash state (max profit without stock):
        #    Option A (No change): cash remains the same (cash_yesterday).
        #    Option B (Sell today): hold_yesterday + current_price - fee.
        #    cash[i] = max(cash[i-1], hold[i-1] + price - fee)
        new_cash = max(cash, hold + price - fee)
        
        # 2. New hold state (max profit with stock):
        #    Option A (No change): hold remains the same (hold_yesterday).
        #    Option B (Buy today): cash_yesterday - current_price.
        #    hold[i] = max(hold[i-1], cash[i-1] - price)
        new_hold = max(hold, cash - price)
        
        # Update states for the next iteration (Day i becomes Day i-1)
        cash = new_cash
        hold = new_hold

    # The maximum profit is always achieved in the 'cash' state (without holding stock)
    return cash