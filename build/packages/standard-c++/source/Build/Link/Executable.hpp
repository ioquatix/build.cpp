
#pragma once

#include "../System/Execute.hpp"

namespace Build
{
	namespace Link
	{
		struct Executable : public Rule
		{
			using Rule::Rule;
			
			Task::State operator()(Paths object_files, Path executable_path) const
			{
				task.invoke<System::Execute>(
					"/usr/bin/clang++", "-o", executable_path.c_str(), object_files
				);
				
				return {{object_files}, {executable_path}};
			}
		};
	}
}
