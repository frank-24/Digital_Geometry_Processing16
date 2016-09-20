ENGN 2501 2016 Digital Geometry Processing
Assignment 1

First of all, configure your development environment.

In this directory, in addition to this README file, you should find
the following subdirectories:

  assets, bin, build, lib, src

The assets subdirectory should contain the following four files,
which you should not modify:


  bunny-mesh-mat.wrl
  bunny-mesh-npf.wrl
  bunny-opts.wrl
  bunny.icns

The bin, build, and lib subdirectories should be empty.
The build process will populate those directories.
You can always delete the contents of those directories and start over.
If you use CMAKE to generate project files, you will files those files
in the build directory. If you use Qt Creator, qmake will create a new
build directory with a longer name.

The src subdirectory contains the following subdirectories:

  core, gui, io, util, wrl

The src directory and each of this subdirectories also contain a
CMakeLists.txt file used by CMAKE, and a *.pro file used by
qmake. Don't modify this files unless you add new files to the
hierarchy.

In Assignment 1, your work will be restricted to the following files

src/gui/GuiStrings.hpp
src/core/Faces.hpp
src/core/Faces.cpp
src/io/LoaderStl.hpp
src/io/LoaderStl.cpp
src/io/SaverStl.hpp
src/io/SaverStl.cpp

1) Before compiling the application for the first time, edit the file
   src/gui/GuiStrings.hpp

In my version, this files contains the definition of the following strings

#define BUNNY_OPTS_WRL \
  "/Users/taubin/Teaching/DGP/2016/software/DGP2016/assets/bunny-opts.wrl"
#define BUNNY_MESH_WRL \
  "/Users/taubin/Teaching/DGP/2016/software/DGP2016/assets/bunny-mesh-npf.wrl"
#define APP_TITLE \
  "DGP2016-A1 Gabriel Taubin"

Replace the first two with the full path to the files assets/bunny-opts.wrl
and assets/bunny-mesh-npf.wrl

Replace my name by your name in the last string.

2) Run CMAKE or Qt Creator to create projects files for the
application, and make sure that it compiles without errors.

3) Verify that you can load and display the two sample bunny files from
the FILE menu buttons

4) Verify that you can load and display the the files from the assets
directory from the FILE->Load menu button

5) Using the FILE-Save menu button, save the files with different
names, and verify that you can reload the files that you have created
using the FILE-Load button.

6) Implement the core/Faces class. For this you have to edit the
following two files

  core/Faces.hpp
  core/Faces.cpp

7) Implement the io/SaverStl class to save triangle meshes in ASCII
STL format. Use the Faces class in your implementation. For this you
have to edit the following two files

  io/SaverStl.hpp
  io/SaverStl.cpp

Read the comments in the files for further instructions

9) Test your implementation by loading the "bunny-mesh-npf.wrl" file
and saving it to a file named "bunny.stl" If you are using a Mac, you
can verify that you had created a a correct file in Finder. Otherwise,
install the MeshLab application or some other polygon mesh
viewer/editor.

8) Implement the io/LoaderStl class to read ASCII STL files. For this
you have to edit the following two files

  io/LoaderStl.hpp
  io/LoaderStl.cpp

10) Test your implementation by loading the file "bunny.stl" that you
created in the previous step. Save the resulting file again in STL
format and in WRL format, and verify that you can reload the files
that you generate.

11) Download some ASCII STL files from the internet, and verify that
you can load them, and save them both in STL format and in WRL format.

13) To submit your work, compress the whole src directory using the
ZIP application as follows:

  a) locate and remove any temporary files created by your editor
  b) rename your src directory to "src-YourLastName". For example,
     in my case I would rename the src directory to src-Taubin
  c) compress the renamed src directory to a file named src-YourLastName.zip
  d) make sure that if you unzip the compressed file in a new loaction,
     you can reconstrucr the src-YourLastName directory with all the subdirectories
  e) upload the src-YourLastName.zip file to Canvas
