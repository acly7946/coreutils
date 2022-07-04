# basename(1) completion

_basename()
{
	local cur short long
	_get_comp_words_by_ref cur

	short=(
		-z
		-h
		-V
	)

	long=(
		--zero
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
complete -F _basename basename