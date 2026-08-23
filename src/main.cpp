namespace Hooks
{
	class hkCreateDirectory_Mods
	{
	private:
		static std::int32_t CreateDirectory(const char* a_name, void*)
		{
			if (!_stricmp(a_name, "Creations") || !_stricmp(a_name, "Mods"))
				return 0;
			return _CreateDirectory(a_name, nullptr);
		}

		inline static REL::THook _CreateDirectory{ REL::ID(443417), 0x06, CreateDirectory };
	};

	class hkCreateDirectory_ShaderCache
	{
	private:
		static std::int32_t CreateDirectory(const char*, void*)
		{
			return 0;
		}

		inline static REL::THook _CreateDirectory{ REL::ID(77226), 0x9DE, CreateDirectory };
	};
}

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
