//
//  One.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include <functional>

namespace Build
{
	template <typename ValueT, typename... ArgumentsT>
	struct One
	{
		typedef std::function<ValueT(ArgumentsT...)> FunctionT;

		ValueT value;
		FunctionT function = nullptr;
		
		bool assigned = false;

		One(const ValueT & value) : value(value) {}
		One(FunctionT function) : function(function) {}

		ValueT operator()(ArgumentsT... arguments) const {
			if (this->function)
				return this->function(arguments...);
			else
				return this->value;
		}
		
		void operator=(ValueT value)
		{
			assigned = true;

			this->value = value;
			function = nullptr;
		}

		void operator=(FunctionT function)
		{
			assigned = true;
			this->function = function;
		}

		void operator|=(FunctionT function)
		{
			if (!assigned && !this->function)
				this->function = function;
		}
		
		void operator|=(const ValueT & value)
		{
			if (!assigned) {
				this->value = value;
				this->function = nullptr;
			}
		}
	};
}
