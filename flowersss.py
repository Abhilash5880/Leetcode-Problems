class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        
        L=len(flowerbed)
        planted=0
        for i in range(L):
            
            if(flowerbed[i]==1):
                continue
            
            if((i==(L-1) and i==0) or (i==0 and  i<=(L-1)  and flowerbed[i+1]==0)):
                #starting mei edge case ke liye
                flowerbed[i]=1
                planted+=1
    
            if(flowerbed[i]==0 and (i+1)<L and flowerbed[i-1]==flowerbed[i+1]==0):
                    #middle cases ke liye...not edge cases
                    flowerbed[i]=1
                    planted+=1
            

            elif(i==(L-1) and flowerbed[i-1]==0):
                #last mei edge case ke liye
                flowerbed[i]=1
                planted+=1
        print(flowerbed)
        if(planted>=n):
            return True
        else:
            return False

