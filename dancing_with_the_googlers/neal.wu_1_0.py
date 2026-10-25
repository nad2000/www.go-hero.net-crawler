T = int(raw_input())

for test_case in xrange(T):
    line = map(int, raw_input().split(' '))
    N = line[0]
    S = line[1]
    P = line[2]
    scores = line[3:]

    more, surprise = 0, 0

    for i in xrange(N):
        if scores[i] >= P + 2 * max(P - 1, 0):
            more += 1
        elif scores[i] >= P + 2 * max(P - 2, 0):
            surprise += 1

    print "Case #{0}: {1}".format(test_case + 1, more + min(surprise, S))
