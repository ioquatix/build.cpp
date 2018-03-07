
#include "../System/Execute.hpp"

namespace Build
{
	namespace Compile
	{
		struct File : public Rule
		{
			using Rule::Rule;
			
			void operator()(Path source_file, Path destination_path) const
			{
				task.invoke<System::Execute>(
					"/usr/bin/clang++", "-o", destination_path.c_str(), "-std=c++14", "-c", source_file.c_str()
				);
			}
		};
	}
}
