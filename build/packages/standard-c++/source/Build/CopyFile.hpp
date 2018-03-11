
#pragma once

#include "System/MakePath.hpp"
#include "System/CopyFile.hpp"

namespace Build
{
	struct CopyFile : public Rule
	{
		using Rule::Rule;
		
		Task::State operator()(Path source_file, Path destination_path) const
		{
			auto state = task.invoke<System::MakePath>(destination_path);
			state += task.invoke<System::CopyFile>(source_file, destination_path);
			
			return state;
		}
	};
}
