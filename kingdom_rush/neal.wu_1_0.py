T = int(raw_input())

for test_case in xrange(T):
    N = int(raw_input())
    a = [0] * N
    b = [0] * N
    done1 = [False] * N
    done2 = [False] * N

    for i in xrange(N):
        a[i], b[i] = map(int, raw_input().split(' '))

    stars = 0
    times = 0

    while sum(done2) < N:
        times += 1
        loop_done = False
        
        for i in xrange(N):
            if not done2[i] and stars >= b[i]:
                stars += 2 if not done1[i] else 1
                done2[i] = True
                loop_done = True
                break

        if loop_done:
            continue

        best_b = 0

        for i in xrange(N):
            if not done1[i] and not done2[i] and stars >= a[i]:
                best_b = max(best_b, b[i])

        for i in xrange(N):
            if not done1[i] and not done2[i] and stars >= a[i] and b[i] == best_b:
                stars += 1
                done1[i] = True
                loop_done = True
                break

        if loop_done:
            continue

        break

    print "Case #{0}: {1}".format(test_case + 1, times if sum(done2) == N else "Too Bad")
