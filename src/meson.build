#libpiggery = static_library(
#    'piggery', # library name
#    'piggery.cpp', # source files to be compiled
#    include_directories : inc, # previously declared include directories in root :code:`meson.build`
#    install : true) # :code:`libuuid` will be part of project installation

piggery = executable(
    'piggeryexe', # executable name
    'main.cpp', # source files to be compiled
    'piggery.cpp', # source files to be compiled
    include_directories : inc, # previously declared include directories in root :code:`meson.build`
    install : true) # :code:`uuidgen` executable be part of project installation

runtests = executable(
    'runtests', # test executable name
    'main_test.cpp', # tests source files to be compiled
    'piggery.cpp', # source files to be compiled
    include_directories : inc)  # declared include directories in root :code:`meson.build`

# test execution
#test('Piggery tests', runtests)

# we can specify other test execution passing arguments or environment variables
#test('Piggery test with args and env', testexe, args : ['arg1', 'arg2'], env : ['FOO=bar'])

