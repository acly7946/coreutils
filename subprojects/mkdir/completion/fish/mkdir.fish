# mkdir(1) completion

complete -f -c mkdir
complete -c mkdir -s m -l mode --description "Set permissions for new directory"
complete -c mkdir -s p -l parent --description "Make parent directories if they don't exist"
complete -c mkdir -s h -l help --description "Show help message and quit"
complete -c mkdir -s V -l version --description "Show version number and quit"