
#pragma once

#include <string>
#include <vector>

namespace Build
{
	struct Variant
	{
		std::string name = "debug";
		
		std::string platform_path = "build/platforms/linux-debug";
		
		std::string build_prefix = "build/cache/linux-debug";
		
		std::vector<std::string> compiler_flags{"-O0", "-g", "-Wall"};
		std::vector<std::string> linker_flags{"-g"};
	};
}
