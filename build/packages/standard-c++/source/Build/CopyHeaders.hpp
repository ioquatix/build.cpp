
#pragma once

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
		
		auto operator()(Paths headers, Path prefix) const
		{
			return task.invoke<CopyFiles>(headers, prefix);
		}
		
		auto operator()(Paths headers) const
		{
			return task.invoke<CopyFiles>(headers, include_prefix());
		}
	};
}
