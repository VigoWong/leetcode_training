class Solution:
    def stringShift(self, s, shift):
        pos = 0
        for sh in shift:
            if sh[0]:
                pos += sh[1]
            else:
                pos -= sh[1]
        ret = ''
        ret += s[pos+1:]
        ret += s[:pos+1]
        return ret

if __name__ == '__main__':
    s = "abc    "
    shift = [[0,1],[1,2]]
    so = Solution()
    a = so.stringShift(s, shift)
    print(a)