
namespace Build
{
	struct CopyFiles : public Rule
	{
		operator()(Paths source_files, Path prefix)
		{
			for (auto & path : source_files) {
				auto destination_path = prefix + path.relative_path;
				
				if (path.is_directory()) {
					task.invoke<System::MakePath>(destination_path);
				} else {
					task.invoke<CopyFile>(source_file, destination_path);
				}
			}
		}
	};
};
