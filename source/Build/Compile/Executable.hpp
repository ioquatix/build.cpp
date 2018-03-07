
#include "../Link/Executable.hpp"
#include "File.hpp"

namespace Build
{
	namespace Compile
	{
		struct Executable : public Rule
		{
			using Rule::Rule;
			
			void operator()(Paths source_files, Path executable_path) const
			{
				Paths object_files;
				
				for (auto & source_file : source_files) {
					auto object_file = source_file + ".o";
					
					task.invoke<File>(source_file, object_file);
					
					object_files.push_back(object_file);
				}
				
				task.invoke<Link::Executable>(object_files, executable_path);
			}
		};
	}
}