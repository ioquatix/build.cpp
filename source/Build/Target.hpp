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
			_dependencies.push_back(name);
		}
		
		template <typename BuilderT>
		void provides(const std::string & name, BuilderT builder)
		{
			auto && provision = _provisions[name];
			
			builder(provision);
		}
		
		void provides(const std::string & name)
		{
			auto && provision = _provisions[name];
		}
		
		void alias(std::string name, std::string alias)
		{
			
		}
		
		void build(std::function<void(Task & task)> function)
		{
			_function = function;
		}
		
		void invoke(Task & task)
		{
			_function(task);
		}
		
	private:
		std::function<void(Task & task)> _function;
		
		std::vector<std::string> _dependencies;
		std::map<std::string, Environment> _provisions;
	};
}
