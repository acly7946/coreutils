valgrind = find_program('valgrind', required: false, disabler: true)
add_test_setup('valgrind',
	exe_wrapper:
	[
		valgrind,
		'--tool=memcheck',
		'--leak-check=full',
		'--gen-suppressions=all',
		'--error-exitcode=1',
	],
	timeout_multiplier: 10
)

test('Valgrind memcheck (uptime)', uptime, suite: 'valgrind')
test('Valgrind memcheck (uptime -p)', uptime, args: ['-p'], suite: 'valgrind')
test('Valgrind memcheck (uptime -s)', uptime, args: ['-s'], suite: 'valgrind')