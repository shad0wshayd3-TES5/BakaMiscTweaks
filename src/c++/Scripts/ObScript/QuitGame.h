#pragma once

namespace Scripts::ObScript
{
	class QuitGame
	{
	public:
		static void Install()
		{
			if (auto func = RE::SCRIPT_FUNCTION::LocateConsoleCommand("QuitGame"))
			{
				func->executeFunction = Execute;
			}
		}

	private:
		static bool Execute(const RE::SCRIPT_PARAMETER*, RE::SCRIPT_FUNCTION::ScriptData*, RE::TESObjectREFR*, RE::TESObjectREFR*, RE::Script*, RE::ScriptLocals*, double&, std::uint32_t&)
		{
			if (auto ConsoleLog = RE::ConsoleLog::GetSingleton())
			{
				ConsoleLog->Print("Bye.\n");
			}

			// clang-format off
			std::thread(
				[&]()
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
					if (auto Main = RE::Main::GetSingleton())
					{
						Main->quitGame = true;
					}
				}).detach();
			// clang-format on

			return true;
		}
	};
}
