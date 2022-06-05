# uname(1) completion

complete -f -c uname
complete -c uname -s a -l all --description "Print all information"
complete -c uname -s m -l machine --description "Print machine name"
complete -c uname -s n -l nodename --description "Print node name"
complete -c uname -s r -l kernel-release --description "Print kernel release"
complete -c uname -s s -l kernel-name --description "Print kernel name"
complete -c uname -s v -l kernel-version --description "Print kernel version"
complete -c uname -s h -l help --description "Show help message and quit"
complete -c uname -s V -l version --description "Show version number and quit"