
namespace Build
{
	struct CopyFiles : public Rule
	{
		using Rule::Rule;
		
		void operator()(Paths source_files, Path prefix) const
		{
			for (auto & path : source_files) {
				auto destination_path = prefix + path; //path.relative_path;
				
				//if (path.is_directory()) {
				//	task.invoke<System::MakePath>(destination_path);
				//} else {
					task.invoke<CopyFile>(path, destination_path);
				//}
			}
		}
	};
}
