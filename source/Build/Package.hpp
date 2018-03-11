//
//  Package.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 8/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Target.hpp"
#include "Task.hpp"

#include <map>

namespace Build
{
	class Package
	{
	public:
		Package();
		virtual ~Package();
		
		Path root_path;
		
		template <typename BuilderT>
		void target(std::string name, BuilderT builder) {
			auto target = targets[name];
			
			builder(target);
		}
		
		std::map<std::string, Target> targets;
	};
}
