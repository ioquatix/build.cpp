//usr/bin/clang++ -O3 -std=c++14 "$0" -o build.bootstrap && ./build.bootstrap; exit

#include <string>
#include <vector>

namespace Build
{
	using Path = std::string;
	using Paths = std::vector<std::string>;
	
	class Package
	{
	public:
		Package(std::string name) {}
	};
	
	struct Environment
	{
		char * const * envp;
	};
	
	struct Task
	{
		const Environment & environment;
		
		template <typename RuleT, typename... ArgumentsT>
		auto invoke(ArgumentsT && ...arguments) const {
			RuleT rule(environment, *this);
			
			return rule(std::forward<ArgumentsT>(arguments)...);
		}
	};
	
	struct Rule
	{
		Rule(const Environment & environment, const Task & task) : environment(environment), task(task) {}
		
		const Environment & environment;
		const Task & task;
	};
}

#include "source/Build/CopyFile.hpp"
#include "source/Build/CopyFiles.hpp"
#include "source/Build/CopyHeaders.hpp"

#include "source/Build/Compile/Executable.hpp"

// #include "package/Build/Files.cpp"
// #include "package/Build/HelloWorld.cpp"

int main(int argc, char *const argv[], char *const envp[]) {
	Build::Environment environment{envp};
	Build::Task task{environment};
	
	task.invoke<Build::Compile::Executable>(Build::Paths{"build.cpp"}, "build");
}

// State compile_files(Paths source_files) {
// 	for (auto & source_file : source_files)
// 		compile_file(source_file);
// }
// 
// State static_library(Paths source_files) {
// 	auto object_files = compile_files(source_files);
// 
// 	auto archive = link_objects(object_files)
// 
// 	return archive;
// }
