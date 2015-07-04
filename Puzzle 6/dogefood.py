__author__ = 'Eric Ahn'

alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'

def check(it):
    a = 0
    b = 0
    for ch in range(0, len(it)):
        a = (a + ord(it[ch])) % 0xff
        b = (b + a) % 0xff
    return b << 8 | a

def every_even(it):
    ret = []
    for ch in range(0, len(it)):
        if i % 2 == 0:
            ret.append(it[ch])
    return ''.join(ret)

with open('even.txt') as f:
    evens = frozenset(f.read().splitlines())
with open('left.txt') as f:
    lefts_t = f.read().splitlines()
with open('right.txt') as f:
    rights = f.read().splitlines()

le = []
re = []

lt = set()
rt = set()

for i in evens:
    lt.add(i[:3])
    rt.add(i[3:])

for i in lefts_t:
    t = every_even(i)
    if t in lt:
        le.append((i, t))

for i in rights:
    t = every_even(i[:-1])
    if t in rt:
        re.append((i, t))

k = 0

for i in le:
    for j in re:
        s = i[1] + j[1]
        if s in evens:
            print i[0]+j[0]
            k += 1

print '{} {} {}'.format(len(le), len(re), k)
