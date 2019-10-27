cmake_minimum_required (VERSION 3.10)
include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable (Argon
	"Argon.cpp" "Lexer.cpp"
	"Token.cpp" "Parser.cpp"
	"Node.cpp" "Value.cpp" 
	"Evaluator.cpp" "Facts.cpp"
	"Util.cpp")
