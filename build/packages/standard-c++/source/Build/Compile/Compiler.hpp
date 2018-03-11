
#pragma once

#include <string>
#include <vector>

namespace Build
{
	namespace Compile
	{
		struct Compiler
		{
			std::string path = "/usr/bin/clang++";
			std::vector<std::string> flags;
			
			void add_include_path(std::string path)
			{
				flags.push_back("-I");
				flags.push_back(path);
			}
		};
	}
}
