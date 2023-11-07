#pragma once

#include "Core/Base.h"
#include <cstdlib>
#include <string>
#include <sstream>

namespace Quest
{
	const std::string BuildPath(std::string_view relative_path)
	{
		const std::string quest_root = std::getenv("QUEST_ENGINE_ROOT");
		QE_CORE_WARN("{0}", quest_root);
		std::stringstream ss;
		ss << quest_root << "/Quest/assets/" << relative_path;
		return ss.str();
	}
}