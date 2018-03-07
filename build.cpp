//usr/bin/clang++ -O3 -std=c++11 "$0" -o build && ./build; exit

namespace Build
{
	class Package
	{
	public:
		Package(std::string name) {}
	};
	
	class Environment
	{
	public:
		Environment(char * const envp[])
		{
		}
	};
	
	class Task
	{
		const Environment & environment;
		
		template <typename RuleT, typename ArgumentsT...>
		typename RuleT::ResultT invoke(ArgumentsT... arguments) {
			RuleT rule(environment);
			
			return rule(arguments...);
		}
	};
	
	struct Rule
	{
		const Environment & environment;
	};
}

#include "source/Build/CopyFile.hpp"
#include "source/Build/CopyFiles.hpp"
#include "source/Build/CopyHeaders.hpp"

#include "packages/Build/Files.cpp"
#include "packages/Build/HelloWorld.cpp"

int main(int argc, char *const argv[], char *const envp[]) {
	Build::Task task(argc, argv, envp);
	
	return task.run();
}
