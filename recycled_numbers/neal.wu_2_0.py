T = int(raw_input())

for test_case in xrange(T):
    A, B = map(int, raw_input().split(' '))
    mapping = dict()

    for n in xrange(A, B + 1):
        str = `n`
        most = '0'

        for i in xrange(10):
            str = str[1:] + str[0]
            most = max(most, str)

        if most not in mapping:
            mapping[most] = 0

        mapping[most] += 1

    total = 0

    for i in mapping:
        total += mapping[i] * (mapping[i] - 1) // 2

    print "Case #{0}: {1}".format(test_case + 1, total)
