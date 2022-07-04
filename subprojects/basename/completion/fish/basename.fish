# basename(1) completion

complete -f -c basename
complete -c basename -s z -l zero --description "Do not print new line after each result"
complete -c basename -s h -l help --description "Show help message and quit"
complete -c basename -s V -l version --description "Show version number and quit"