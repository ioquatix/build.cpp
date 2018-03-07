
namespace Build
{
	struct CopyHeaders : public Rule
	{
		using Rule::Rule;
		
		Path include_prefix() const
		{
			return "include";
			//return Path(environment["INSTALL_PREFIX"]) + "include";
		}
		
		void operator()(Paths headers, Path prefix) const
		{
			task.invoke<CopyFiles>(headers, prefix);
		}
		
		void operator()(Paths headers) const
		{
			return task.invoke<CopyFiles>(headers, include_prefix());
		}
	};
};
