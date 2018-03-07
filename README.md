# Build.cpp

`Build.cpp` is a self-hosted package driven build tool primarily aimed at C++ projects, but general enough for any kind of dependency graph processing.

In the root of your project `build.hpp`:

```c++
#include <Build/Package.hpp>

package("MyProject", defaults("c++14", "project"));

auto source = root/"source";
headers(source.glob("**/*.{h,hpp}"));

auto parsers = ragel("source/**/*.rl");
library(source.glob("**/ *.{cpp}"), parsers);

auto test = root/"test";
tests(test.glob("**/*.cpp"));

auto test = root/"bin";
run(bin.glob("*.cpp"));

configuration(
	Source("git://github.com"),
	Require("system"),
	Require("unit-tests"),
	Require("language-c++14"),
);

```

Then run:

```
./build.cpp library/MyProject
./build.cpp test/MyProject
./build.cpp run/MyProject
```
