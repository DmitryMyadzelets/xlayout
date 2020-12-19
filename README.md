# xlayout
Get current keyboard layout in Linux. Based on [the
code](https://gist.github.com/fikovnik/ef428e82a26774280c4fdf8f96ce8eeb) of
[Filip Krikava](https://gist.github.com/fikovnik).
 
```bash
> xlayout
Full name: Italian
Layout name: it
```

## Compilation and Installation

You may need to install some packages for compilation: 
```
apt install gcc x11proto-dev
```
Compile:
```
gcc -I/usr/include xlayout.c -lX11 -lxkbfile -o xlayout
```
Move it to a directory where your shell searces for executables. For instance:
```
echo $PATH
mv xlayout ~/bin/
```

## Usage Tips
Get layout short name:
```bash
xlayout | grep Layout | cut -d' ' -f3
```

## Alternatives
* [xkblayout-state](https://github.com/nonpop/xkblayout-state)
* [xkb-switch](https://github.com/grwlf/xkb-switch)
