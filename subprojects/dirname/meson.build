project(
	'dirname',
	'c',
	version: '1.0.0',
	license: 'MIT',
	meson_version: '>=0.59.0',
	default_options:
	[
		'c_std=c11',
		'warning_level=3'
	]
)

add_project_arguments(
	[
		'-Wundef',
		'-Wvla',
		'-DVERSION="@0@"'.format(meson.project_version()),
	],
	language: 'c'
)

datadir = get_option('datadir')
sysconfdir = get_option('sysconfdir')
prefix = get_option('prefix')

subdir('completion')
subdir('doc')
subdir('src')