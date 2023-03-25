#include "SettingObj.h"

namespace GameSettingExtender
{
	void from_json(const json& j, SettingObj& obj)
	{
		using TYPE = RE::Setting::Type;

		obj.setting = new RE::Setting(j.at("name").get<std::string>());

		auto type = obj.setting->GetType();
		switch (type) {
		case TYPE::kBool:
			obj.setting->SetBool(j.at("value").get<bool>());
			break;
		case TYPE::kCharacter:
			obj.setting->SetCharacter(j.at("value").get<std::int8_t>());
			break;
		case TYPE::kUnsignedCharacter:
			obj.setting->SetUnsignedCharacter(j.at("value").get<std::uint8_t>());
			break;
		case TYPE::kInteger:
			obj.setting->SetInteger(j.at("value").get<std::int32_t>());
			break;
		case TYPE::kUnsignedInteger:
			obj.setting->SetUnsignedInteger(j.at("value").get<std::uint32_t>());
			break;
		case TYPE::kFloat:
			obj.setting->SetFloat(j.at("value").get<float>());
			break;
		case TYPE::kColorRGB:
			obj.setting->SetColor(j.at("value").get<std::uint32_t>());
			break;
		case TYPE::kColorRGBA:
			obj.setting->SetColorA(j.at("value").get<std::uint32_t>());
			break;
		default:
			break;
		}
	}

}