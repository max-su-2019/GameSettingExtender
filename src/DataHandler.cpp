#include "DataHandler.h"

namespace GameSettingExtender
{
	DataHandler::DataHandler() {}

	void DataHandler::InsertGameSettings()
	{
		auto GSEFilesName = DKUtil::Config::GetAllFiles("Data\\SKSE\\Plugins\\GameSettingExtender"sv, ".json"sv, {}, "_GSE"sv);
		for (const auto& fileName : GSEFilesName) {
			INFO("Parsing GSE Data In \"{}\"", fileName);
			try {
				auto js = json::parse(std::ifstream(fileName));
				for (auto& [key, value] : js.items()) {
					auto setting = ParseSettingFromJS(key, value);
					if (setting)
						RE::GameSettingCollection::GetSingleton()->InsertSetting(setting);
					else
						ERROR("Expection! Invaild Game Setting Type Created in File \"{}!\"", fileName);
				}
			} catch (const json::exception& ex) {
				ERROR("Caught expection when parsing file \"{}\":\n {}", fileName, ex.what());
			}
		}
	}

	RE::Setting* DataHandler::ParseSettingFromJS(const std::string& a_key, const json& j)
	{
		auto setting = new RE::Setting(a_key);

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
			delete (setting);
			return nullptr;
		}

		return setting;
	}

}