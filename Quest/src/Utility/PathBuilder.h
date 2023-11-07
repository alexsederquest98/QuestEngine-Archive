#pragma once

#include "Core/Base.h"
#include <cstdlib>
#include <string>
#include <sstream>

namespace Quest
{
	static const std::string BuildPath(std::string relative_path)
	{
		const std::string quest_root = std::getenv("QUEST_ENGINE_ROOT");
		std::stringstream ss;
		ss << quest_root << "/Quest/assets/" << relative_path;
		return ss.str();
	}
}