s="ejp mysljylc kd kxveddknmc re jsicpdrysi"+\
  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+\
  "de kr kd eoya kw aej tysr re ujdr lkgc jvqz"
d="our language is impossible to understand"+\
  "there are twenty six factorial possibilities"+\
  "so it is okay if you want to just give upzq"
tr=str.maketrans(s,d)
name="A-small-attempt1"
f = "".join(map(chr,sorted(tr.keys())))
t = "".join(map(chr,sorted(tr.values())))
with open(name+".in") as fi, open(name+".out","w") as fo:
    n = int(fi.readline().strip())
    for i in range(n):
        fo.write("Case #{0}: {1}\n".format(i+1, fi.readline().strip().translate(tr)));
    
