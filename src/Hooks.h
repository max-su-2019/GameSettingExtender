#pragma once
#include "DKUtil/Hook.hpp"

namespace GameSettingExtender
{
	using namespace DKUtil::Alias;

	class GetGSCmdFix
	{
		static constexpr OpCode NOP = 0x90;
		static constexpr OpCode CrashNop[8]{ NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP };

		// 1-5-97-0 0x2f2280
		static constexpr std::uint64_t FuncID = 21549;
		static constexpr std::ptrdiff_t crashOffset = 0x1D6;

	public:
		static void Install()
		{
			const auto funcAddr = REL::ID(FuncID).address();
			DKUtil::Hook::WriteData(funcAddr + crashOffset, &CrashNop, sizeof(CrashNop));
			INFO("{} Done!", __FUNCTION__);
		}

	private:
		GetGSCmdFix() = delete;
		~GetGSCmdFix() = delete;
	};
}