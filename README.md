# Coreutils
Some of the core unix utilities

| Utility |  TODO   |   WIP   |  DONE   |
| ------- | :-----: | :-----: | :-----: |
| cut     | &check; |         |         |
| ls      | &check; |         |         |
| uname   |         | &check; |         |
| yes     |         | &check; |         |

## Building

Dependencies:
* GCC/Clang \*
* meson (>=0.59.0) \*
* ninja \*
* scdoc (optional: man pages)\*

_\* Compile-time dep_

``` sh
# Copy using button there -->
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