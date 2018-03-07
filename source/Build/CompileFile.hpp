
#include "System/Execute.hpp"

namespace Build
{
	struct CompileFile : public Rule
	{
		using Rule::Rule;
		
		void operator()(Path source_file, Path destination_path) const
		{
			task.invoke<System::Execute>(
				"clang", "-o", destination_path.c_str(), source_file.c_str()
			);
		}
	};
};
