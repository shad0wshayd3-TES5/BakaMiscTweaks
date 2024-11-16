namespace Tweaks
{
	namespace MagicEffectDescription
	{
		static REL::Relocation<void*(void*, const char*)> thunk;

		static void* func(void* a_this, const char*)
		{
			return thunk(a_this, "<br>");
		}
		
		static void Install()
		{
			static REL::Relocation target{ REL::ID(51906), 0xC5 };
			thunk = target.write_call<5>(func);
		}
	}

	static void Install()
	{
		MagicEffectDescription::Install();
	}
}

namespace
{
	void MessageCallback(SKSE::MessagingInterface::Message* a_msg)
	{
		switch (a_msg->type)
		{
		case SKSE::MessagingInterface::kPostLoad:
		{
			Tweaks::Install();
			break;
		}
		default:
			break;
		}
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* a_SKSE)
{
	SKSE::Init(a_SKSE, true);
	SKSE::AllocTrampoline(16);
	SKSE::GetMessagingInterface()->RegisterListener(MessageCallback);

	return true;
}
