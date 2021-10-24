from conans import ConanFile, CMake, tools


class SetmMath(ConanFile):
    name = "SetmMath"
    version = "1.0.0"
    author = "Baranov Konstantin (seigtm@gmail.com)"
    description = "setm::math library package."
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "visual_studio"

    requires = \
        "boost/[1.77.0]"

    def _configure(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.definitions['CMAKE_BUILD_TYPE'] = "Debug" if self.settings.build_type == "Debug" else "Release"
        cmake.configure(source_folder=self.source_folder)
        return cmake

    def build(self):
        cmake = self._configure()
        cmake.build()

    def package(self):
        cmake = self._configure()
        cmake.install()

    def package_info(self):
        self.cpp_info.includedirs = ["include", "include/setm"]
        self.cpp_info.libs = tools.collect_libs(self)
