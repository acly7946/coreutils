# rmdir(1) completion

_rmdir()
{
	local cur short long
	_get_comp_words_by_ref cur

	short=(
		-h
		-p
		-v
		-V
	)

	long=(
		--ignore-fail-on-non-empty
		--parents
		--help
		--verbose
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
complete -F _rmdir rmdir