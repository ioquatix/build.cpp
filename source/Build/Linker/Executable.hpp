
#include "../System/Execute.hpp"

namespace Build
{
	namespace Linker
	{
		struct Executable : public Rule
		{
			using Rule::Rule;
			
			void operator()(Paths object_files, Path executable_path) const
			{
				task.invoke<System::Execute>(
					"/usr/bin/clang++", "-o", executable_path.c_str(), object_files[0].c_str()
				);
			}
		};
	}
}
