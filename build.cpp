//usr/bin/clang++ -Wall -std=c++14 "$0" -o bin/build && bin/build; exit

#include "source/Build/Context.cpp"
#include "source/Build/Package.cpp"
#include "source/Build/Target.cpp"
#include "source/Build/Environment.cpp"
#include "source/Build/Task.cpp"
#include "source/Build/Rule.cpp"

#include "build/packages/variant/build/package.hpp"
#include "build/packages/standard-c++/build/package.hpp"
#include "build/package.hpp"

Build::Context make_context() {
	using namespace Build;
	
	Context context;
	
	#include "build/packages/variant/build/package.cpp"
	#include "build/packages/standard-c++/build/package.cpp"
	#include "build/package.cpp"
	
	return context;
}

int main(int argc, char *const argv[], char *const envp[]) {
	auto context = make_context();
	
	std::vector<std::string> arguments(argv, argv+argc);
	
	//environment = context.resolve(arguments);
	
	return 0;
}
