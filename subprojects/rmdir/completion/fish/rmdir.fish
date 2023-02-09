# rmdir(1) completion

complete -f -c rmdir
complete -c rmdir -l ignore-fail-on-non-empty --description "Do not fail on non-empty directorie"
complete -c rmdir -s p -l parents --description "Remove parent directories"
complete -c rmdir -s h -l help --description "Show help message and quit"
complete -c rmdir -s V -l verbose --description "Verbose output"
complete -c rmdir -s V -l version --description "Show version number and quit"
