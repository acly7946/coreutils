# dirname(1) completion

complete -f -c dirname
complete -c dirname -s z -l zero --description "Do not print new line after each result"
complete -c dirname -s h -l help --description "Show help message and quit"
complete -c dirname -s V -l version --description "Show version number and quit"