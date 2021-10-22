from conans import ConanFile, CMake


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
        cmake.definitions['CMAKE_BUILD_TYPE'] = "Debug" if self.settings.build_type == "Debug" else "Release"
        cmake.configure()
        return cmake

    def build(self):
        cmake = self._configure()
        cmake.build()

    def package(self):
        cmake = self._configure()
        cmake.install()

    def package_info(self):
        if self.settings.os == "Windows":
            if self.settings.compiler == "Visual Studio":
                self.cpp_info.libs = ["SetmMath.lib"]
            else:
                self.cpp_info.libs = ["SetmMath.dll"]
        else:
            self.cpp_info.libs = ["SetmMath.so"]

    # Maybe trash, delete it later:
    # def package(self):
    #     self.copy("*")
    #     cmake = CMake(self)
    #     cmake.install()

    # def package_info(self):
    #     self.cpp_info.libs = self.collect_libs()
