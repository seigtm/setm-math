from conans import ConanFile, CMake


class SetmMathTest(ConanFile):
    name = "SetmMathTest"
    version = "2.1.0"
    author = "Baranov Konstantin (seigtm@gmail.com)"
    description = "Testing setm::math library."
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "visual_studio"

    requires = \
        "SetmMath/[~1.0.0]"

    build_requires = \
        "gtest/[1.11]"

    def imports(self):
        self.copy("*.dll", "", "bin")

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
