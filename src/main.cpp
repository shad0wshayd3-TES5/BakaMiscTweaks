class Tweaks
{
public:
	class MagicEffectDescription
	{
	public:
		static void Install()
		{
			REL::Relocation<std::uintptr_t> target{ REL::ID(51906), 0xC5 };

			auto& trampoline = SKSE::GetTrampoline();
			thunk = trampoline.write_call<5>(target.address(), func);
		}

	private:
		static void* func(void* a_this, const char*)
		{
			return thunk(a_this, "<br>");
		}

		inline static REL::Relocation<decltype(func)> thunk;
	};
};

SKSEPluginLoad(const SKSE::LoadInterface* a_SKSE)
{
	SKSE::Init(a_SKSE, true);
	SKSE::AllocTrampoline(16);

	Tweaks::MagicEffectDescription::Install();

	return true;
}
