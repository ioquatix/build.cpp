
#pragma once

#include "Execute.hpp"

namespace Build
{
	namespace System
	{
		struct CopyFile : public Rule
		{
			using Rule::Rule;
			
			void operator()(const Path & source_file, const Path & destination_path) const
			{
				task.invoke<Execute>("cp", source_file.c_str(), destination_path.c_str());
			}
		};
	}
}
