KoalaToolbox
============

This repository isn't (yet) a framework, nore a library. It just a compilation of
some (hopely) usefull C++ classes

In this compilation, you'll find some subdirectories :

- Factory : this subdir provide template classes which aims to allows Factory
design pattern for (derived) objects created with any kind of parameter list

- Signal : a simple, easy to use signal / slot system

Please read the README file into each subdirectory to know more about its content

Directory organisation
----------------------
Each subdirectory will be organized in the same way, to help you to get
only what you want in this toolbox.  Here is the usual tree structure,
given thate "root_dir" is one of the first level subdirectory:

* root_dir : one directory for one tool
    * doxygen: Contains some doxygen specific configuration and text files
    * examples : Some tools are coming with
    * extlib : sometimes, i make use of extern libraries (eg: catch for
      testing).  This directory will containt such external libraries
    * lib : Contains each library used by the tool, each one being in its
      own subdirectory
        * &lt;libname&gt;: for each library used by the tool, there is a
           subdirectory named by the library name, and containing
          * include subdirectory, for public headers and
          * src subdirectory, for implementation files
    * tests : contains unit tests directory for providen tools.  For each
      library in lib subdirectory, you'll find a subdirectory in tests
      subdir, containing unit tests specifics to that lib.

Generic usage
-------------

There are two ways to use my tools:

One simple way is to use each tool as a simple, single library by just
copying the lib/&lt;libname&gt; subdirectory, including
the CMakeLists.t in to your own project tree, and by adding this
subdirectory in the parent directory CMakeLists.txt using the command
`add_subdirectory(libname)`

Or, you can group multiple tools in a single, more complex library.

To do this, just copy the include and src directories for the tools you
want to use in your project.

For each tool, copy the &lt;toolname&gt;.cmake file in the same directory.

You the should have a directory structure like

* &lt;project_tree&gt;
    * CMakeLists.txt
    * tool1.cmake
    * tool2.cmake
    * ...
    * toolN.cmake
        * include
            * all header files should be here
        * src
            * all implementation files should be here

Just include *.cmake to your CMakeLists.txt with the `include(toolN.cmake)`
command.

Providen *.cmake file will populate `KTB_HEADERS` and `KTB_SRCS` (if needed)
with all files providen by different tools.

Just make use of those two variables in your `add_binary` or your `add_library`
command.

NOTE:
-----
Each tool will populate a CACHE &lt;toolname in uppercase&gt;_INCLUDE_DIRS
variable that you can use to access to different headers subdirectories.
