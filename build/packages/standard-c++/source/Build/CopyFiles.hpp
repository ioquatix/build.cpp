
#pragma once

namespace Build
{
	struct CopyFiles : public Rule
	{
		using Rule::Rule;
		
		Task::State operator()(Paths source_files, Path prefix) const
		{
			Task::State state;
			
			for (auto & path : source_files) {
				auto destination_path = prefix + path; //path.relative_path;
				
				//if (path.is_directory()) {
				//	task.invoke<System::MakePath>(destination_path);
				//} else {
					state += task.invoke<CopyFile>(path, destination_path);
				//}
			}
			
			return state;
		}
	};
}
