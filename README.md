# Coreutils
An implementation of the core unix utilities. This project does not aim to be GNU compatible. It is written for learning purposes and is not intended for daily use.

<details>
	<summary>Status</summary>

| Utility | Not started | In Progress | Working |
| ------- | :---------: | :---------: | :-----: |
| cut     |   &check;   |             |         |
| ls      |   &check;   |             |         |
| uname   |             |   &check;   |         |
| uptime  |             |             | &check; |
| yes     |             |             | &check; |
</details>

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