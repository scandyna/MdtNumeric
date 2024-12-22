cmake_minimum_required(VERSION 3.15)

project(MdtNumericTest)

find_package(MdtCMakeModules REQUIRED)
find_package(Mdt0 REQUIRED COMPONENTS Numeric)


include(MdtAddTest)

enable_testing()

mdt_add_test(
  NAME NumericTest
  TARGET numericTest
  DEPENDENCIES Mdt0::Numeric
  SOURCE_FILES
    main.cpp
)
