testexe = executable(
    'testexe', # test executable name 
    'main_test.cpp', # tests source files to be compiled
    include_directories : inc,  # declared include directories in root :code:`meson.build`
    link_with : libuuid) # link test executable with previously declared shared library :code:`libuuid`

# test execution 
test('Piggery test', testexe)

# we can specify other test execution passing arguments or environment variables
#test('Piggery test with args and env', testexe, args : ['arg1', 'arg2'], env : ['FOO=bar'])
