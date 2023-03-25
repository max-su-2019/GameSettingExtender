#pragma once
#include "DKUtil/Config.hpp"
#include "SettingObj.h"

namespace GameSettingExtender
{
	using namespace DKUtil::Alias;

	class DataHandler : public dku::model::Singleton<DataHandler>
	{
		friend dku::model::Singleton<DataHandler>;
		friend void from_json(const json& j, SettingObj& obj);

		DataHandler();

	public:
		void InsertGameSettings();
	};

}