
#pragma once

#include <string>

namespace Build
{
	namespace Link
	{
		struct Linker
		{
			Environment::One<std::string> path{"/usr/bin/ar"};
			
			Environment::One<std::string> executable_prefix{"bin/"};
			Environment::One<std::string> library_prefix{"lib/"};
			
			Environment::Many<std::string> flags{{"-cr"}};
			
			void add_local_library(std::string name)
			{
				flags << [name](const Environment & environment){
					return environment.fetch<Linker>().library_prefix(environment) + '/' + name;
				};
			}
		};
	}
}
