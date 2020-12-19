# xlayout
Get current keyboard layout in Linux

Based on [the
code](https://gist.github.com/fikovnik/ef428e82a26774280c4fdf8f96ce8eeb) of
[Filip Krikava](https://gist.github.com/fikovnik)

You may need to install some packages: 
```
apt install gcc x11proto-dev
```
Compile:
```
gcc -I/usr/include xlayout.c -lX11 -lxkbfile -o xlayout
```

