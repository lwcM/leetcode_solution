class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        def gogo(s):
            tmp = s[0]
            cnt = 1
            ret = ''
            for i in xrange(1, len(s)):
                if s[i] != tmp:
                    ret += str(cnt) + tmp
                    tmp = s[i]
                    cnt = 1
                else:
                    cnt += 1
            return ret + str(cnt) + tmp
                    
        s = '1'
        for _ in xrange(n-1):
            s = gogo(s)
        return s
        
        
