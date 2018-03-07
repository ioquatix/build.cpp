
#pragma once

#include "Execute.hpp"

namespace Build
{
	namespace System
	{
		struct MakePath : public Rule
		{
			using Rule::Rule;
			
			void operator()(const Path & path) const
			{
				task.invoke<Execute>("mkdir", "-p", path.c_str());
			}
		};
	};
};
