N = 1000010

class Trie:
    def __init__(self):
        self.tr = [[0, 0] for _ in range(N)]
        self.idx = 0
        self.cnt = [0] * N

    def insert(self, s, id):
        p = 0
        for u in s:
            ch = int(u)
            if self.tr[p][ch] == 0:
                self.idx += 1
                self.tr[p][ch] = self.idx
            p = self.tr[p][ch]
            self.cnt[p] += 1

    def query(self, s):
        p = 0
        length = 0
        for u in s:
            ch = int(u)
            if self.tr[p][ch] != 0:
                p = self.tr[p][ch]
                length += 1
            else:
                break
        return length

    def remove(self, s):
        p = 0
        for u in s:
            ch = int(u)
            tmp = self.tr[p][ch]
            self.cnt[self.tr[p][ch]] -= 1
            if self.cnt[self.tr[p][ch]] == 0:
                self.tr[p][ch] = 0
            p = tmp

def Hex2Proto(s):
    res = ""
    for i in range(2, len(s)):
        num = 0
        if s[i].isdigit():
            num = int(s[i])
        else:
            num = ord(s[i]) - ord('A') + 10
        tmp = ""
        for j in range(4):
            tmp += str(num & 1)
            num >>= 1
        res += tmp[::-1]
    return res

def Proto2Binary(s):
    res = ""
    for i in range(len(s) - 1, -1, -8):
        for j in range(i - 6, i + 1):
            res += s[j]
    res = res[::-1]
    while len(res) > 0 and res[-1] == '0':
        res = res[:-1]
    res = res[::-1]
    return res

def solve():
    n = int(input())

    vec = ["0"]
    idx = 0
    s = 0

    mp = {}

    for _ in range(n):
        x, y = input().split()
        x = int(x)

        if x == 1:
            mp[y] = mp.get(y, 0) + 1
            Proto_y = Hex2Proto(y)
            Binary_y = Proto2Binary(Proto_y)

            s = T.query(Binary_y)
            T.insert(Binary_y, idx + 1)
            vec.append(Binary_y)

            print(mp[y], s)
        else:
            if y in mp and mp[y] > 0:
                mp[y] -= 1
                Proto_y = Hex2Proto(y)
                Binary_y = Proto2Binary(Proto_y)
                T.remove(Binary_y)

T = Trie()
solve()
