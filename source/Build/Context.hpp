//
//  Context.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 8/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Package.hpp"

namespace Build
{
	class Context
	{
	public:
		Context();
		virtual ~Context();
		
		template <typename BuilderT>
		void package(std::string name, BuilderT builder) {
			auto package = packages[name];
			
			builder(package);
		}
		
		std::map<std::string, Package> packages;
	};
}


