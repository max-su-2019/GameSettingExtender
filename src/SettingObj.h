#pragma once
#include "nlohmann/json.hpp"

namespace GameSettingExtender
{
	using json = nlohmann::json;

	struct SettingObj
	{
		RE::Setting* setting;
	};

	void from_json(const json& j, SettingObj& obj);
}