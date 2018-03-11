//
//  Many.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 11/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include <functional>
#include <vector>

namespace Build
{
	template <typename ValueT, typename... ArgumentsT>
	struct Many
	{
		typedef std::function<ValueT(ArgumentsT...)> FunctionT;

		struct Element
		{
			ValueT value;
			FunctionT function = nullptr;

			Element(const ValueT & value) : value(value) {}
			Element(FunctionT function) : function(function) {}

			ValueT operator()(ArgumentsT... arguments) const
			{
				if (this->function)
					return this->function(arguments...);
				else
					return this->value;
			}
		};

		std::vector<Element> elements;

		Many(std::initializer_list<Element> list) : elements(list) {}

		std::vector<ValueT> operator()(ArgumentsT... arguments) const
		{
			std::vector<ValueT> result;

			for (auto && element : elements) {
				result.push_back(element(arguments...));
			}

			return result;
		}

		void flatten(ArgumentsT... arguments)
		{
			for (auto && element : elements) {
				element.flatten(arguments...);
			}
		}

		auto & operator<<(ValueT value)
		{
			this->elements.push_back({value});
			
			return *this;
		}

		auto & operator<<(FunctionT function)
		{
			this->elements.push_back({function});
			
			return *this;
		}
	};
}
