#using dictionary and sorting
'''class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums.sort()
        frequency={}
        for i in nums:
            if i in frequency:
                frequency[i]+=1
            else:
                frequency[i]=1
        
        sorted_by_freq = sorted(frequency.items(), key=lambda item: item[1], reverse=True)
        
        final_list=[]
        for i in range(k):
            final_list.append(sorted_by_freq[i][0])
        
        return final_list
            '''
        