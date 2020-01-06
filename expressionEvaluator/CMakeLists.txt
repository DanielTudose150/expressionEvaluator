cmake_minimum_required(VERSION 3.15)
project(expressionEvaluator)

set(CMAKE_CXX_STANDARD 14)

add_executable(expressionEvaluator main.cpp tipuri/listeDouble.h tipuri/listeString.h tipuri/stivaDouble.h tipuri/stivaDouble.cpp tipuri/stivaString.h tipuri/stivaString.cpp tipuri/coada.cpp tipuri/coada.h evaluator/evaluator.cpp evaluator/evaluator.h)