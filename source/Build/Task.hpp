//
//  Task.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 8/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Environment.hpp"

#include <string>
#include <vector>
#include <iostream>

namespace Build
{
	using Path = std::string;
	using Paths = std::vector<std::string>;
	
	struct Task
	{
		struct State
		{
			Paths inputs;
			Paths outputs;
			
			State & operator+=(const State & other)
			{
				inputs.insert(inputs.end(), other.inputs.cbegin(), other.inputs.cend());
				outputs.insert(outputs.end(), other.outputs.cbegin(), other.outputs.cend());
				
				return *this;
			}
			
			void inspect() const
			{
				std::cerr << "Inputs:";
				for (auto & input : inputs) {
					std::cerr << ' ' << input;
				}
				std::cerr << std::endl;
				
				std::cerr << "Outputs:";
				for (auto & output : outputs) {
					std::cerr << ' ' << output;
				}
				std::cerr << std::endl;
			}
		};
		
		const Environment & environment;
		
		template <typename RuleT, typename... ArgumentsT>
		auto invoke(ArgumentsT && ...arguments) const {
			RuleT rule{environment, *this};
			
			return rule(std::forward<ArgumentsT>(arguments)...);
		}
	};
}
