class Solution(object):
    def recur(self, sum, target, candidates, cur_ls,ret):
        if(sum > target):
            return
        elif(sum == target):
            cur_ls = sorted(cur_ls)
            if cur_ls not in ret:
                ret.append(cur_ls)
        else:
            for c in candidates:
                self.recur(sum+c, target, candidates, cur_ls+[c],ret)
        return ret

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ret = []
        ret = self.recur(0,target, candidates, [], ret)

        return ret




if __name__ == '__main__':
    ls = [2,3,5]
    target = 8
    c = Solution()
    a = c.combinationSum(ls, target)
    print(a)