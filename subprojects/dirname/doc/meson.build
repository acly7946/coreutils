scdoc = dependency('scdoc', native: true, required: get_option('man-pages'))

if scdoc.found()
	scdoc_prog = find_program(scdoc.get_variable(pkgconfig: 'scdoc'), native: true)
	mandir = get_option('mandir')
	man_files = [
		'dirname.1.scd',
	]

	foreach filename : man_files
		topic = filename.split('.')[-3].split('/')[-1]
		section = filename.split('.')[-2]
		output = '@0@.@1@'.format(topic, section)

		custom_target(
			output,
			input: filename,
			output: output,
			command: scdoc_prog,
			install: true,
			feed: true,
			capture: true,
			install_dir: '@0@/man@1@'.format(mandir, section)
		)
	endforeach
endif