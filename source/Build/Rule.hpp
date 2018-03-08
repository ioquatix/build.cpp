//
//  Rule.hpp
//  This file is part of the "Build" project and released under the MIT License.
//
//  Created by Samuel Williams on 8/3/2018.
//  Copyright, 2018, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Task.hpp"

namespace Build
{
	struct Rule
	{
		Rule(const Environment & environment, const Task & task) : environment(environment), task(task) {}
		
		const Environment & environment;
		const Task & task;
	};
}
