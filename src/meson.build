libpiggery = shared_library(
    'piggery', # library name
    'piggery.cpp', # source files to be compiled
    include_directories : inc, # previously declared include directories in root :code:`meson.build`
    install : true) # :code:`libuuid` will be part of project installation

piggery = executable(
    'piggery', # executable name
    'main.cpp', # source files to be compiled
    include_directories : inc, # previously declared include directories in root :code:`meson.build`
    link_with : libpiggery, # linking executable with shared previously declared shared library :code:`libuuid`
    install : true) # :code:`uuidgen` executable be part of project installation
