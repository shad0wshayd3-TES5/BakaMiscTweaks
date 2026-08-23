namespace Tweaks
{
	class hkMagicEffectDescription
	{
	private:
		static void* Append(void* a_this, const char*)
		{
			return _Append(a_this, "<br>");
		}

		inline static REL::THook _Append{ REL::ID(51906), 0xC5, Append };
	};
}

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* a_SKSE)
{
	SKSE::Init(a_SKSE, { .trampoline = true });
	return true;
}
