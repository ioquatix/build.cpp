//
//  Target.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 8/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Task.hpp"
#include "Environment.hpp"

#include <vector>
#include <string>

namespace Build
{
	class Target
	{
	public:
		Target();
		virtual ~Target();
		
		void depends(std::string name)
		{
			dependencies.push_back(name);
		}
		
		template <typename BuilderT>
		void provides(const std::string & name, BuilderT builder)
		{
			provisions[name] = builder;
		}
		
		void provides(const std::string & name)
		{
			auto && provision = provisions[name];
		}
		
		void alias(std::string name, std::string alias)
		{
			
		}
		
		void build(std::function<void(Task & task)> function)
		{
			this->function = function;
		}
		
		void invoke(Task & task)
		{
			function(task);
		}
		
		std::function<void(Task & task)> function;
		
		std::vector<std::string> dependencies;
		std::map<std::string, std::function<void(Environment &)>> provisions;
	};
}
