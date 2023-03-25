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
				for (auto& element : js) {
					auto obj = element.get<SettingObj>();
					RE::GameSettingCollection::GetSingleton()->InsertSetting(obj.setting);
				}
			} catch (const json::exception& ex) {
				ERROR("Caught expection when parsing file \"{}\":\n {}", fileName, ex.what());
			}
		}
	}

}