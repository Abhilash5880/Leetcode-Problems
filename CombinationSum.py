

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
         
        candidates.sort()
        cur=[]
        res=[]
        self.backTracking(candidates,target,0,cur,res)
        return res

    def backTracking (self, candidates: List[int],  remain : int, start : int, cur: List[int], res: List[List[int]]) ->None:


        if remain==0:
            res.append(list(cur))
            return
        
        for i in range(start, len(candidates), 1):
            val=0
            val=candidates[i]
            if(val>remain):break

            cur.append(val)
            self.backTracking(candidates, remain-val, i, cur, res)
            cur.pop()

    

        