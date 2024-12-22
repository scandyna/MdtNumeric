from conan import ConanFile
from conan.tools.env import VirtualBuildEnv
from conan.tools.cmake import CMakeToolchain, CMakeDeps, CMake, cmake_layout
from conan.tools.files import copy
import os

# This recipe is only to install dependencies to build MdtNumeric
# The recipes to create packages are in packaging/conan/ subfolder
class MdtNumericConan(ConanFile):
  name = "mdtnumeric"
  license = "LGPL-3.0-or-later"
  url = "https://gitlab.com/scandyna/mdtnumeric"
  description = "Set of helpers for basic numeric operations."
  settings = "os", "compiler", "build_type", "arch"
  options = {"shared": [True, False]}
  default_options = {"shared": True}
  generators = "CMakeDeps", "VirtualBuildEnv"

  # See: https://docs.conan.io/en/latest/reference/conanfile/attributes.html#short-paths
  #short_paths = True

  def set_version(self):
    if not self.version:
      self.version = "0.0.0"

  def requirements(self):
    self.requires("mdtcmakeconfig/0.1.0@scandyna/testing")

  def build_requirements(self):
    self.test_requires("mdtcmakemodules/0.20.0@scandyna/testing")

  def export_sources(self):
    source_root = os.path.join(self.recipe_folder, "../../../")
    copy(self, "CMakeLists.txt", source_root, self.export_sources_folder)
    copy(self, "COPYING", source_root, self.export_sources_folder)
    copy(self, "COPYING.LESSER", source_root, self.export_sources_folder)
    copy(self, "libs/CMakeLists.txt", source_root, self.export_sources_folder)
    copy(self, "libs/Numeric/*", source_root, self.export_sources_folder)

  def layout(self):
    cmake_layout(self)

  def generate(self):
    tc = CMakeToolchain(self)
    tc.variables["FROM_CONAN_PROJECT_VERSION"] = self.version
    tc.generate()

  def build(self):
    cmake = CMake(self)
    cmake.configure()
    cmake.build()

  def package(self):
    cmake = CMake(self)
    cmake.install()

  def package_info(self):
    self.cpp_info.set_property("cmake_file_name", "Mdt0Numeric")
    self.cpp_info.set_property("cmake_target_name", "Mdt0::Numeric")
    self.cpp_info.libs = ["Mdt0Numeric"]
