#pragma once
#include "nlohmann/json.hpp"

namespace GameSettingExtender
{
	using json = nlohmann::json;

	struct SettingObj
	{
		RE::Setting* setting;

		SettingObj(const std::string& a_key, const json& j);
	};

}