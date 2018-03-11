
#pragma once

#include "../Link/Archive.hpp"
#include "File.hpp"

namespace Build
{
	namespace Compile
	{
		struct Archive : public Rule
		{
			using Rule::Rule;
			
			Task::State operator()(Paths source_files, Path library_file) const
			{
				Paths object_files;
				
				for (auto & source_file : source_files) {
					auto object_file = source_file + ".o";
					
					task.invoke<File>(source_file, object_file);
					
					object_files.push_back(object_file);
				}
				
				task.invoke<Link::Archive>(object_files, library_file);
				
				return {{source_files}, {library_file}};
			}
		};
	}
}
