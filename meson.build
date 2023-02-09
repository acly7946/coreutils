project(
	'Coreutils',
	'c',
	version: '0.6.4',
	license: 'MIT',
	meson_version: '>=0.53.0',
)

summary({
	'bash-completions': get_option('bash-completions'),
	'fish-completions': get_option('fish-completions'),
	'zsh-completions': get_option('zsh-completions'),
	'man-pages': get_option('man-pages'),
}, bool_yn: true)

subproject('dirname')
subproject('mkdir')
subproject('tty')
subproject('uname')
subproject('uptime')
subproject('yes')