# Short project description
Display system information to the user based on the option he chooses from a console menu

# Development tools and platforms
The project was made to build on two platforms : Windows and Linux/Unix (tested on Ubuntu distribution)

Development tools used:
IDE: QtCreator 4.11.1

a) WINDOWS: V. 10.0
Compiler: Mcrosoft C++
Debugger: CDB 10.0.17
Build process manager: Cmake 13.15.2 

b) UBUNTU: V. 18.04
Compiler: gcc 7.5.0
Debugger: GDB 8.10
Build process manager: Cmake 3.10.2 - looks like the default one in Ubuntu 18.04

# To build the project, clone anywhere on your PC
Clone address: https://github.com/melaniaoncea/DiagnosticsApp 
The project will be public.
Open it using an appropriate IDE/development tools : Cmake, no less than version 10,
a platform specific compiler (in my case, gcc for Ubuntu and Microsoft C++ from Visual Studio
on Windows).

# Future improvements
- improve install paths, do not leave them as they are by default so the project will have a unitary structure no matter on what platform is built
- add unit tests using GoogleTest or other framwork. I had QtTest installed, but it does not work with standard C++.
- fetch data from the system for all categories and remove hardcoded data

# Some notes: normally I would not add the same header in a header file as well as in the source of that header, but I read that,
 in cross platform developmnet, one shouldn't rely on some other included file having the desired include. As this was my first project of this sort, I was not sure what that meant 
 so I might have fallen in the other extreme, of including too often. I think that the note was made for headers that are not built by the programmer.

# Some modern c++14 features used:
 - function return type deduction
 
# Other c++11 features
 - initializer lists
 - parenthesized initialization
 - auto data type

# Added class diagram to easyly see the architecture of the program found in resources folder
  Sample of a screen capture of the running app.

