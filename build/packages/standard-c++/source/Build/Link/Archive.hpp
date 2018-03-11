
#pragma once

#include "../System/Execute.hpp"
#include "Linker.hpp"

namespace Build
{
	namespace Link
	{
		struct Archive : public Rule
		{
			using Rule::Rule;
			
			Task::State operator()(Paths object_files, Path library_file) const
			{
				auto linker = environment.fetch<Linker>();
				
				task.invoke<System::Execute>(
					linker.path(environment).c_str(), linker.flags(environment), library_file.c_str(), object_files
				);
				
				return {{object_files}, {library_file}};
			}
		};
	}
}
