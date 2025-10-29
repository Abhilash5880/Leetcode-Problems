import sys

def solve():
    
    try:
        line = sys.stdin.readline().split()
        if not line:
            return
        
        N = int(line[0])
        T = int(line[1])
        
       
        durations = []
        for _ in range(N):
            line = sys.stdin.readline().strip()
            if line:
                durations.append(int(line))
            
    except:
        return


    durations.sort(reverse=True)
    

    result = True
    
 
    for i in range(N):
       
        required_time = (N - 1 - i) * T
        
        
        if durations[i] <= required_time:
            result = False
            break
            

    if result:
        print("YES")
    else:
        print("NO")
solve()
