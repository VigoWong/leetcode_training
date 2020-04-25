class Solution:

    def dfs(self, visit, cur_ls, nums, ret):
        if(len(cur_ls) == len(nums)):
            ret.append(cur_ls)

        else:
            for n in range(len(nums)):
                if not visit[n]:
                    visit[n] = 1
                    self.dfs(visit, cur_ls+[nums[n]], nums, ret)
                    visit[n] = 0

    def permuteUnique(self, nums):
        nums = list(sorted(nums))
        visit = [0] * len(nums)
        cur_ls = []
        ret = []
        self.dfs(visit, cur_ls, nums, ret)
        return ret


if __name__ == '__main__':
    s = Solution()
    print(s.permuteUnique([1, 2, 3]))
