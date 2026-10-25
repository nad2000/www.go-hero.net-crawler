g = dict()
g[' '] = ' '
g['a'] = 'y'
g['b'] = 'h'
g['c'] = 'e'
g['d'] = 's'
g['e'] = 'o'
g['f'] = 'c'
g['g'] = 'v'
g['h'] = 'x'
g['i'] = 'd'
g['j'] = 'u'
g['k'] = 'i'
g['l'] = 'g'
g['m'] = 'l'
g['n'] = 'b'
g['o'] = 'k'
g['p'] = 'r'
g['q'] = 'z'
g['r'] = 't'
g['s'] = 'n'
g['t'] = 'w'
g['u'] = 'j'
g['v'] = 'p'
g['w'] = 'f'
g['x'] = 'm'
g['y'] = 'a'
g['z'] = 'q'

T = int(raw_input())

for test_case in xrange(T):
    line = raw_input()
    answer = ''

    for i in line:
        answer += g[i]

    print 'Case #{0}: {1}'.format(test_case + 1, answer)
