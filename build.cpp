//usr/bin/clang++ -O3 -std=c++14 "$0" -o build && ./build; exit

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
	
	class Environment
	{
	public:
		Environment(char * const envp[])
		{
		}
	};
	
	struct Task
	{
		const Environment & environment;
		
		template <typename RuleT, typename... ArgumentsT>
		auto invoke(ArgumentsT... arguments) const {
			RuleT rule(environment, *this);
			
			return rule(arguments...);
		}
	};
	
	struct Rule
	{
		Rule(const Environment & environment, const Task & task) : environment(environment), task(task) {}
		
		const Environment & environment;
		const Task & task;
	};
	
	namespace System
	{
		struct MakePath : public Rule
		{
			using Rule::Rule;
			
			void operator()(const Path & path) const
			{
			}
		};
		
		struct CopyFile : public Rule
		{
			using Rule::Rule;
			
			void operator()(const Path & source_file, const Path & destination_path) const
			{
			}
		};
	}
	
	struct Controller
	{
		int argc;
		char *const * argv;
		char *const * envp;
		
		int run() const {
			Environment environment(envp);
			Task task{environment};
			
			return 0;
		}
	};
}

#include "source/Build/CopyFile.hpp"
#include "source/Build/CopyFiles.hpp"
#include "source/Build/CopyHeaders.hpp"

// #include "package/Build/Files.cpp"
// #include "package/Build/HelloWorld.cpp"

int main(int argc, char *const argv[], char *const envp[]) {
	Build::Controller controller{argc, argv, envp};
		
	return controller.run();
}
