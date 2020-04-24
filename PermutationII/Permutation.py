class Solution:

    def dfs(self, nums, cur_ls, cur_left, ret):
        if(len(cur_ls) == len(nums)):
            return cur_ls

        n = 0
        while (n < len(cur_left)):
            cur_ls.append(cur_left[n])
            while(n != len(cur_left)-1 and )



    def permuteUnique(self, nums):
        nums = list(sorted(nums))
        ret = self.dfs(nums, [])

        for n in range(len(nums)):
