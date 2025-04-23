#include "SpellScriptLoader.h"

class spell_custom_speed_buff : public AuraScript
{
    PrepareAuraScript(spell_custom_speed_buff)

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (GetOwner())
            if (GetOwner()->IsPlayer())
            {
                Player* player = GetOwner()->ToPlayer();
                if (!player->IsInCombat())
                    player->AddAura(GetSpellInfo()->Effects[0].MiscValue, player);
            }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_custom_speed_buff::HandlePeriodic, EFFECT_ALL, SPELL_AURA_ANY);
    }
};

void AddSC_custom_spell_scripts()
{
    RegisterSpellScript(spell_custom_speed_buff);
}
