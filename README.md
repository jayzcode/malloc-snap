# malloc-snap
Snapcraft Example: Snap to malloc precise memory.

**To compile:**
```
./gensnap.sh
```

**Resulting snap:**
```
$ ls -l
total 16
-rwxrwxrwx 1 ubuntu ubuntu   434 May 10 17:20 gensnap.sh
-rw-r--r-- 1 ubuntu ubuntu 12288 May 23 11:02 myapp_0.20.0_amd64.snap
drwxrwxr-x 3 ubuntu ubuntu    50 May 23 11:02 parts
drwxrwxr-x 5 ubuntu ubuntu    41 May 23 11:02 prime
drwxrwxrwx 2 ubuntu ubuntu    28 May 23 10:19 snap
drwxrwxrwx 2 ubuntu ubuntu   118 May 11 11:08 src-dir
drwxrwxr-x 3 ubuntu ubuntu    17 May 23 11:02 stage
$
```

**Snap installation:**
```
sudo snap install myapp_0.20.0_amd64.snap --dangerous --devmode
```

**List snap:**
```
$ snap list
Name       Version        Rev    Tracking       Publisher   Notes
core18     20220428       2409   latest/stable  canonical✓  base
core20     20220329       1434   latest/stable  canonical✓  base
lxd        4.0.9-8e2046b  22753  4.0/stable/…   canonical✓  -
myapp      0.20.0         x1     -              -           devmode
snapcraft  6.1            7201   latest/stable  canonical✓  classic
snapd      2.55.3         15534  latest/stable  canonical✓  snapd
uc-image   4.11.12        92     latest/stable  ondra       -
$
```

**Testing installed snap:**
```
$ myapp -h
Usage: myapp [OPTION]...
                -h, --help              display this help and exit
                -g, --greeting=TEXT     use TEXT as the greeting message
                -m, --memory=NUM        use NUM to allocate NUM MB memory

$ myapp -m 100
Allocating memory of size = 100 MB (104857600 B)
pagesize=4096 B
number of pages=25600

Memory Usage before allocation
              total        used        free      shared  buff/cache   available
Mem:          64318         865       49201           0       14251       63453
Swap:             0           0           0

Memory Usage after allocation
              total        used        free      shared  buff/cache   available
Mem:          64318         965       49101           0       14251       63352
Swap:             0           0           0

Press Any Key to Continue...

```
