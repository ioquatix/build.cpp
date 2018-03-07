
namespace Build
{
	struct CopyFile : public Rule
	{
		operator()(Path source_file, Path destination_path)
		{
			task.invoke<System::MakePath>(destination_path);
			task.invoke<System::CopyFile>(source_file, destination_path);
		}
	};
};
