from collections import defaultdict
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows, ds, dg = 0, 0, defaultdict(int), defaultdict(int)
        
        for s, g in zip(secret, guess):
            if s == g:
                bulls += 1
                continue
            ds[s] += 1
            dg[g] += 1

        for s in ds:
            if s in dg:
                cows += min(ds[s],dg[s])

        return f'{bulls}A{cows}B'

s = Solution()
print(s.getHint("1807", "7810"))