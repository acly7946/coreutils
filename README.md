# Coreutils
An implementation of the core unix utilities. This project does not aim to be GNU compatible. It is written for learning purposes and is not intended for daily use.

<details>
	<summary>Status</summary>

|  Utility  | Not started | In Progress | Working |
| --------- | :---------: | :---------: | :-----: |
| ar        |   &check;   |             |         |
| at        |   &check;   |             |         |
| awk       |   &check;   |             |         |
| basename  |   &check;   |             |         |
| batch     |   &check;   |             |         |
| bc        |   &check;   |             |         |
| cat       |   &check;   |             |         |
| chgrp     |   &check;   |             |         |
| chmod     |   &check;   |             |         |
| chown     |   &check;   |             |         |
| cksum     |   &check;   |             |         |
| cmp       |   &check;   |             |         |
| comm      |   &check;   |             |         |
| command   |   &check;   |             |         |
| cp        |   &check;   |             |         |
| crontab   |   &check;   |             |         |
| csplit    |   &check;   |             |         |
| cut       |   &check;   |             |         |
| date      |   &check;   |             |         |
| dd        |   &check;   |             |         |
| df        |   &check;   |             |         |
| diff      |   &check;   |             |         |
| dirname   |             |             | &check; |
| du        |   &check;   |             |         |
| echo      |   &check;   |             |         |
| ed        |   &check;   |             |         |
| env       |   &check;   |             |         |
| expand    |   &check;   |             |         |
| expr      |   &check;   |             |         |
| false     |   &check;   |             |         |
| file      |   &check;   |             |         |
| find      |   &check;   |             |         |
| fold      |   &check;   |             |         |
| gencat    |   &check;   |             |         |
| getconf   |   &check;   |             |         |
| getopts   |   &check;   |             |         |
| grep      |   &check;   |             |         |
| hash      |   &check;   |             |         |
| head      |   &check;   |             |         |
| iconv     |   &check;   |             |         |
| id        |   &check;   |             |         |
| join      |   &check;   |             |         |
| kill      |   &check;   |             |         |
| ln        |   &check;   |             |         |
| locale    |   &check;   |             |         |
| localedef |   &check;   |             |         |
| logger    |   &check;   |             |         |
| logname   |   &check;   |             |         |
| lp        |   &check;   |             |         |
| ls        |   &check;   |             |         |
| m4        |   &check;   |             |         |
| mailx     |   &check;   |             |         |
| man       |   &check;   |             |         |
| mesg      |   &check;   |             |         |
| mkdir     |             |   &check;   |         |
| mkfifo    |   &check;   |             |         |
| mv        |   &check;   |             |         |
| newgrp    |   &check;   |             |         |
| nice      |   &check;   |             |         |
| nohup     |   &check;   |             |         |
| od        |   &check;   |             |         |
| paste     |   &check;   |             |         |
| patch     |   &check;   |             |         |
| pathchk   |   &check;   |             |         |
| pax       |   &check;   |             |         |
| pr        |   &check;   |             |         |
| printf    |   &check;   |             |         |
| ps        |   &check;   |             |         |
| pwd       |   &check;   |             |         |
| read      |   &check;   |             |         |
| renice    |   &check;   |             |         |
| rm        |   &check;   |             |         |
| rmdir     |   &check;   |             |         |
| sed       |   &check;   |             |         |
| sh        |   &check;   |             |         |
| sleep     |   &check;   |             |         |
| sort      |   &check;   |             |         |
| split     |   &check;   |             |         |
| strings   |   &check;   |             |         |
| stty      |   &check;   |             |         |
| tabs      |   &check;   |             |         |
| tail      |   &check;   |             |         |
| tee       |   &check;   |             |         |
| test      |   &check;   |             |         |
| touch     |   &check;   |             |         |
| tput      |   &check;   |             |         |
| tr        |   &check;   |             |         |
| true      |   &check;   |             |         |
| tsort     |   &check;   |             |         |
| tty       |   &check;   |             |         |
| umask     |   &check;   |             |         |
| unalias   |   &check;   |             |         |
| uname     |             |   &check;   |         |
| unexpand  |   &check;   |             |         |
| uniq      |   &check;   |             |         |
| uptime    |             |             | &check; |
| uudecode  |   &check;   |             |         |
| uuencode  |   &check;   |             |         |
| wait      |   &check;   |             |         |
| wc        |   &check;   |             |         |
| who       |   &check;   |             |         |
| write     |   &check;   |             |         |
| xargs     |   &check;   |             |         |
| yes       |             |             | &check; |

</details>

## Building

Dependencies:

* GCC/Clang \*
* meson (>=0.59.0) \*
* ninja \*
* scdoc (optional: man pages) \*

	_\* Compile-time dependency_

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

Alternatively, each utility can be built on it's own
``` sh
cd uptime/
meson build/
ninja -C build/
```