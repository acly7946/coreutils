# tty(1) completion

complete -f -c tty
complete -c tty -s s -l silent --description "Print nothing, only return exit status"
complete -c tty -s h -l help --description "Show help message and quit"
complete -c tty -s V -l version --description "Show version number and quit"