# uname(1) completion

_uname()
{
	local cur short long
	_get_comp_words_by_ref cur prev

	short=(
		-a
		-m
		-n
		-r
		-s
		-v
		-h
		-V
	)

	long=(
		--all
		--machine
		--nodename
		--kernel-release
		--kernel-name
		--kernel-version
		--help
		--version
	)

	if [[ $cur == --* ]]; then
		COMPREPLY=($(compgen -W "${long[*]}" -- "$cur"))
	elif [[ $cur == -* ]]; then
		COMPREPLY=($(compgen -W "${short[*]}" -- "$cur"))
		COMPREPLY+=($(compgen -W "${long[*]}" -- "$cur"))
	else
		COMPREPLY=($(compgen -W "${short[*]}" -- "$cur"))
		COMPREPLY+=($(compgen -W "${long[*]}" -- "$cur"))
		COMPREPLY+=($(compgen -c -- "$cur"))
	fi

} &&
complete -F _uname uname