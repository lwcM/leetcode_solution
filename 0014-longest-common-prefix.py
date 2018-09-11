class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        ans = ''
        for i in xrange(len(strs[0])):
            same = True
            for j in xrange(len(strs)):
                if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    same = False
                    break
            if same:
                ans += strs[0][i]
            else:
                return ans
        return ans
        
