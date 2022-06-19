# uptime(1) completion

complete -f -c uptime
complete -c uptime -s p -l pretty --description "Print in a human-readable format"
complete -c uptime -s s -l since --description "Print time uptime is calculated from"
complete -c uptime -s h -l help --description "Show help message and quit"
complete -c uptime -s V -l version --description "Show version number and quit"