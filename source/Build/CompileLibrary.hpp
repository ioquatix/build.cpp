
#include "Linker/StaticLibrary.hpp"
#include "CompileFile.hpp"

namespace Build
{
	struct CompileLibrary : public Rule
	{
		using Rule::Rule;
		
		void operator()(Paths source_files, Path library_file) const
		{
			Paths object_files;
			
			for (auto & source_file : source_files) {
				auto object_file = source_file + ".o";
				
				task.invoke<CompileFile>(source_file, object_file);
				
				object_files.push_back(object_file);
			}
			
			task.invoke<Linker::StaticLibrary>(object_files, library_file);
		}
	};
}
