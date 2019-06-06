#libpiggery = static_library(
#    'piggery', # library name
#    'piggery.cpp', # source files to be compiled
#    include_directories : inc, # previously declared include directories in root :code:`meson.build`
#    install : true) # :code:`libuuid` will be part of project installation

src = [
    'category.cpp',
    'piggery.cpp',
    'piggybank.cpp'
    ]

sqlite3dep = dependency('sqlite3')

piggery = executable(
    'piggery', # executable name
    'main.cpp', # source files to be compiled
    src,
    include_directories : inc, # previously declared include directories in root :code:`meson.build`
    dependencies : sqlite3dep,
    install : true) # :code:`uuidgen` executable be part of project installation

runtests = executable(
    'runtests', # test executable name
    'main_test.cpp', # tests source files to be compiled
    src,
    include_directories : inc,  # declared include directories in root :code:`meson.build`
    dependencies : sqlite3dep)

# test execution
test('Piggery tests', runtests)

# we can specify other test execution passing arguments or environment variables
#test('Piggery test with args and env', testexe, args : ['arg1', 'arg2'], env : ['FOO=bar'])

