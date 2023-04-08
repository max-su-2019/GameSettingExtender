#pragma once
#include "DKUtil/Config.hpp"
#include "nlohmann/json.hpp"

namespace GameSettingExtender
{
	using namespace DKUtil::Alias;
	using json = nlohmann::json;

	class DataHandler : public dku::model::Singleton<DataHandler>
	{
		friend dku::model::Singleton<DataHandler>;

		DataHandler();

	public:
		void InsertGameSettings();

	private:
		RE::Setting* ParseSettingFromJS(const std::string& a_key, const json& j);
	};

}