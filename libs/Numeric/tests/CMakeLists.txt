# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

include(MdtAddTest)


mdt_add_test(
  NAME LimitsTest
  TARGET limitsTest
  DEPENDENCIES Mdt::Numeric Mdt::Catch2Main
  SOURCE_FILES
    src/LimitsTest.cpp
)

mdt_add_test(
  NAME BasicConversionTest
  TARGET basicConversionTest
  DEPENDENCIES Mdt::Numeric Mdt::Catch2Main
  SOURCE_FILES
    src/BasicConversionTest.cpp
)

mdt_add_test(
  NAME BasicConversionErrorTest
  TARGET basicConversionErrorTest
  DEPENDENCIES Mdt::Numeric Mdt::Catch2Main
  SOURCE_FILES
    src/BasicConversionErrorTest.cpp
)
