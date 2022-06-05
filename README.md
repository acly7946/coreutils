# Coreutils
Some of the core unix utilities

| Utility |  TODO   |   WIP   |  DONE   |
| ------- | ------- | ------- | ------- |
| uname   |         | &check; |         |

## Building

Dependencies:
* C compiler \*
* meson \*
* ninja \*
* scdoc (optional: man pages)\*

_\* Compile-time dep_

``` sh
# Copy using button here →
git clone "https://github.com/acly7946/coreutils.git"
cd coreutils/
meson build/
ninja -C build/
```
``` sh
sudo ninja -C build/ install # To install
```
``` sh
sudo ninja -C build/ uninstall # To uninstall
```