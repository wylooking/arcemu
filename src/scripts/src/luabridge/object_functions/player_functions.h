#pragma once
#include "StdAfx.h"

namespace lua_engine
{
	void bindPlayerMethods(luabridge::module & m)
	{
#define BIND(name) .method(#name, &Player::name)
#define BINDE(name, functor) .method(name, (functor) )
		m	.subclass<Player, Player, Unit>("Player")
			BIND(Gossip_Complete)
			BIND(Gossip_SendPOI)
			BINDE("AdvanceSkillLine", &Player::_AddSkillLine)
			BINDE("AddSkillLine", &Player::_AddSkillLine)
			BINDE("GetSkillLineMax", &Player::_GetSkillLineMax)
			BINDE("GetSkillLineCurrent", &Player::_GetSkillLineCurrent)
			BINDE("RemoveSkillLine", &Player::_RemoveSkillLine)
			BINDE("UpdateMaxSkillLineCounts", &Player::_UpdateMaxSkillCounts)
			BINDE("ModifySkillBonus", &Player::_ModifySkillBonus)
			BINDE("ModifySkillBonusByType", &Player::_ModifySkillBonusByType)
			BINDE("HasSkillLine", &Player::_HasSkillLine)
			BIND(RemoveSpellsFromLine)
			BINDE("RemoveAllSkills", &Player::_RemoveAllSkills)
			BINDE("RemoveLanguages", &Player::_RemoveLanguages)
			BINDE("AddLanguages", &Player::_AddLanguages)
			BINDE("AdvanceAllSkills", &Player::_AdvanceAllSkills)
			BINDE("ModifySkillMaximum", &Player::_ModifySkillMaximum)
			BINDE("LearnSkillSpells", &Player::_LearnSkillSpells)
			BIND(Cooldown_AddStart)
			BIND(Cooldown_Add)
			BIND(Cooldown_AddItem)
			BINDE("Cooldown_CanCast", (bool (Player::*)(SpellEntry*) )&Player::Cooldown_CanCast)
			BIND(SendPacket)
			BIND(SendMessageToSet)

			BIND(GetTaxiPath)
			BIND(GetTaxiState)
			BIND(TaxiStart)
			BIND(SetTaxiPath)
			BIND(SetTaxiPos)
			BIND(SetTaxiState)

			BIND(HasQuests)
			BIND(GetOpenQuestSlot)
			BIND(GetQuestLogForEntry)
			BIND(GetQuestLogInSlot)
			BIND(GetQuestSharer)
			BIND(SetQuestSharer)
			BIND(SetQuestLogSlot)
			BIND(HasFinishedDaily)
			BIND(AddToFinishedQuests)
			BIND(HasFinishedQuest)
			BIND(GetQuestRewardStatus)
			BIND(HasQuestForItem)
			BIND(HasQuestSpell)
			BIND(RemoveQuestSpell)
			BIND(HasQuest)
			BIND(RemoveQuestMob)

			BIND(GetTeam)
			BIND(GetTeamInitial)
			BIND(SetTeam)
			BIND(ResetTeam)
			BIND(IsTeamHorde)
			BIND(IsTeamAlliance)
			BIND(IsInFeralForm)
			
			BIND(GetMaxLevel)
			BIND(GetSelection)
			BIND(GetTarget)
			BIND(SetSelection)
			BIND(SetTarget)

			BIND(HasSpell)
			BIND(addSpell)
			BIND(removeSpell)
			BIND(AddShapeShiftSpell)
			BIND(RemoveShapeShiftSpell)

			//faction
			BIND(ModStanding)
			BIND(GetStanding)
			BIND(GetBaseStanding)
			BIND(SetStanding)
			BIND(SetAtWar)
			//BIND(IsAtWar)
			BIND(GetStandingRank)
			.static_method("GetReputationRankFromStanding", &Player::GetReputationRankFromStanding)
			BIND(SetFactionInactive)
			BIND(GetExaltedCount)

			BIND(GetPVPRank)
			BIND(SetPVPRank)
			BIND(GetMaxPersonalRating)
			BIND(HasTitle)
			BIND(SetKnownTitle)

			BIND(InGroup)
			BIND(IsGroupLeader)
			BIND(HasBeenInvited)
			BIND(SetInviter)
			BIND(GetInviter)

			BIND(IsGroupMember)
			BIND(IsBanned)
			
			BINDE("SetBanned", (void (Player::*)() )&Player::SetBanned)
			BINDE("SetBannedWithReason", (void (Player::*)(string) )&Player::SetBanned)
			//BINDE("SetBannedWithTimeStamp", (void (Player::*)(uint32,string&))&Player::SetBanned)
			BIND(UnSetBanned)
			BIND(GetBanReason)

			BIND(IsInGuild)
			BINDE("GetGuildID", &Player::GetGuildId)
			BINDE("SetGuildID", &Player::SetGuildId)
			BIND(GetGuildRank)
			BIND(SetGuildRank)
			BIND(GetGuildInvitersGuid)
			BIND(SetGuildInvitersGuid)
			BIND(UnSetGuildInvitersGuid)

			BIND(RequestDuel)
			BIND(EndDuel)
			BIND(DuelCountdown)
			BIND(SetDuelStatus)
			BIND(GetDuelStatus)
			BIND(SetDuelState)
			BIND(GetDuelState)
			BIND(GetDuelTeam)
			BIND(SetDuelTeam)

			BIND(SetBindPoint)
			BIND(KillPlayer)
			BIND(ResurrectPlayer)

			BIND(GetShapeShift)
			BIND(SetShapeShift)
			BIND(CanSee)
			BIND(IsVisible)
			BIND(Reset_Spells)
			BIND(Reset_Talents)
			BIND(GetSelectedGo)
			BIND(IsMounted)
			BIND(Dismount)
			BIND(Kick)
			BIND(SoftDisconnect)

			BIND(GetSummonedObject)
			BIND(SetSummonedObject)
			BIND(ClearCooldownsOnLine)
			BIND(ResetAllCooldowns)
			BIND(ClearCooldownForSpell)

			BIND(Phase)
			BIND(ExitInstance)
			BIND(GetAreaID)
			BIND(SetAreaID)
			BIND(EventTeleport)
			BIND(EventTeleportTaxi)
			BINDE("SafeTeleport", (bool (Player::*)(uint32,uint32,float,float,float,float) )&Player::SafeTeleport)
			BIND(GetDungeonDifficulty)
			BIND(GetRaidDifficulty)

			BIND(GetGold)
			BIND(ModGold)
			BIND(HasGold)
			BIND(SetGold)
			BIND(GiveGold)
			BIND(TakeGold)

			BIND(SetFarsightTarget)
			BIND(GetFarsightTarget)
			
			BIND(SetXp)
			BIND(GetXp)
			BIND(SetNextLevelXp)
			
			BIND(SetTalentPoints)
			BIND(ModTalentPoints)
			BIND(GetTalentPoints)

			BIND(SetHonorCurrency)
			BIND(GetHonorCurrency)
			BIND(ModHonorCurrency)

			BIND(GetArenaCurrency)
			BIND(SetArenaCurrency)
			BIND(ModArenaCurrency)

			BIND(SetGlyph)
			BIND(GetGlyph)

			BIND(ResetPvPTimer)
			BIND(StopPvPTimer)
			BIND(PvPToggle)

			BIND(LearnTalent)
			BIND(AddComboPoints)

			BIND(GetTradeTarget)
			BIND(Possess)
			BIND(UnPossess)

			BIND(IsAttacking)
			BIND(PlaySound)
			BIND(GetItemInterface)
			BINDE("Resurrect", &Player::RemoteRevive)
			BINDE("ResurrectPlayer", &Player::RemoteRevive)

			//For assigning gossip menus to players, similar to objmgr.CreateMenuForPlayer
			.property_rw("m_currentgossipmenu", &Player::CurrentGossipMenu );
#undef BIND
#undef BINDE
	}
}