
namespace Build
{
	struct CopyFile : public Rule
	{
		using Rule::Rule;
		
		void operator()(Path source_file, Path destination_path) const
		{
			task.invoke<System::MakePath>(destination_path);
			task.invoke<System::CopyFile>(source_file, destination_path);
		}
	};
};
