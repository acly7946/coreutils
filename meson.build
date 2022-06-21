project(
	'Coreutils',
	'c',
	version: '0.4.5',
	license: 'MIT',
	meson_version: '>=0.59.0',
)

summary({
	'bash-completions': get_option('bash-completions'),
	'fish-completions': get_option('fish-completions'),
	'zsh-completions': get_option('zsh-completions'),
	'man-pages': get_option('man-pages'),
}, bool_yn: true)

subproject('mkdir')
subproject('uname')
subproject('uptime')
subproject('yes')