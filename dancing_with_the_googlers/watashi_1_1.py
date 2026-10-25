re = input()
for ri in xrange(re):
  tokens = raw_input().split(None, 3)
  n, s, p = map(int, tokens[0: 3])
  t = map(int, tokens[3].split())
  ans = 0
  for i in t:
    if (i + 2) / 3 >= p:
      ans += 1
    elif s > 0 and i >= 2 and (i + 4) / 3 == p:
      ans += 1
      s -= 1
  print "Case #%d: %d" % (ri + 1, ans)
