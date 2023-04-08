#include "SettingObj.h"

namespace GameSettingExtender
{
	SettingObj::SettingObj(const std::string& a_key, const json& j)
	{
		setting = new RE::Setting(a_key);

		using TYPE = RE::Setting::Type;

		auto type = setting->GetType();
		switch (type) {
		case TYPE::kBool:
			setting->SetBool(j.get<bool>());
			break;
		case TYPE::kCharacter:
			setting->SetCharacter(j.get<std::int8_t>());
			break;
		case TYPE::kUnsignedCharacter:
			setting->SetUnsignedCharacter(j.get<std::uint8_t>());
			break;
		case TYPE::kInteger:
			setting->SetInteger(j.get<std::int32_t>());
			break;
		case TYPE::kUnsignedInteger:
			setting->SetUnsignedInteger(j.get<std::uint32_t>());
			break;
		case TYPE::kFloat:
			setting->SetFloat(j.get<float>());
			break;
		case TYPE::kString:
			setting->SetString(j.get<std::string>());
			break;
		case TYPE::kColorRGB:
			setting->SetColor(j.get<std::uint32_t>());
			break;
		case TYPE::kColorRGBA:
			setting->SetColorA(j.get<std::uint32_t>());
			break;
		default:
			ERROR("\"Expection! Invaild Game Setting Type Created!\"");
			break;
		}
	}

}