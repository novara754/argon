# CMakeList.txt : CMake project for Argon, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Argon "Argon.cpp" "Lexer.cpp" "Lexer.h" "Token.cpp" "Token.h")

# TODO: Add tests and install targets if needed.
