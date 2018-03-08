//
//  Environment.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 8/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include <map>
#include <string>
#include <memory>

#include <typeindex>

namespace Build
{
	class Environment
	{
	public:
		Environment() {}
		
		struct Wrapper
		{
			virtual ~Wrapper() {}
		};
		
		template <typename ValueT>
		struct Wrapped : public Wrapper
		{
			ValueT value;
		};
		
		template <typename ValueT>
		ValueT & fetch() const
		{
			// TODO fix this nasty hack.
			auto && key = typeid(ValueT);
			auto && iterator = _values.lower_bound(key);
			
			if (iterator == _values.end() || _values.key_comp()(key, iterator->first)) {
				auto wrapped = new Wrapped<ValueT>();
				
				_values.insert(iterator, {key, (Wrapper*)wrapped});
				
				return wrapped->value;
			} else {
				auto && iterator = _values.find(key);
				
				auto & wrapped = dynamic_cast<Wrapped<ValueT> &>(*iterator->second);
				
				return wrapped.value;
			}
		}
		
	private:
		mutable std::map<std::type_index, Wrapper *> _values;
	};
}