
#include "../System/Execute.hpp"

namespace Build
{
	namespace Linker
	{
		struct StaticLibrary : public Rule
		{
			using Rule::Rule;
			
			void operator()(Paths object_files, Path library_file) const
			{
				task.invoke<System::Execute>(
					"/usr/bin/ar", "-cr", library_file.c_str(), object_files[0].c_str()
				);
			}
		};
	}
}
