T = int(raw_input())

for test_case in xrange(T):
    A, B = map(int, raw_input().split(' '))
    probs = map(float, raw_input().split(' '))
    keys = B + 2
    success = 1

    for i in xrange(A + 1):
        keys = min(keys, (A - i + B - i + 1) + (1 - success) * (B + 1))

        if i < A:
            success *= probs[i]

    print "Case #{0}: {1}".format(test_case + 1, keys)
