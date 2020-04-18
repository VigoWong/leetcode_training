class Solution:
    def longestPalindrome(self, s):
        if len(s) == 0:
            return s
        else:
            expand = ''
            max_len = 0
            for i in range(len(s)):
                for j in range(i+1 ,len(s)+1):
                    if s[i:j] == s[i:j][::-1] and len(s[i:j]) > max_len:
                        max_len = len(s[i:j])
                        expand = s[i:j]
            return expand

if __name__ == '__main__':
    s = Solution()
    a = 'abcbatyttry'
    print(s.longestPalindrome(a))



