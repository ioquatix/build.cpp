
namespace Build
{
	struct CopyHeaders : public Rule
	{
		Path include_prefix()
		{
			return Path(environment["INSTALL_PREFIX"]) + "include";
		}
		
		operator()(Paths headers, Path prefix = include_prefix())
		{
			task.invoke<CopyFiles>(headers, prefix);
		}
	};
};
