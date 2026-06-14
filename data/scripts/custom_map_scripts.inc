.align 2
BOND_RinnuaTown_MapScripts::
.byte 0

.align 2
BOND_CiaransHouse_1F_MapScripts::
.byte 0

.align 2
BOND_CiaransHouse_2F_MapScripts::
.byte 0

.align 2
BOND_NeighboursHouse_1F_MapScripts::
.byte 0

.align 2
BOND_NeighboursHouse_2F_MapScripts::
.byte 0

.align 2
BOND_AnTineBheo_MapScripts::
.byte 0

.align 2
.byte 0

BondOfEire_EventScript_Mum::
lock
faceplayer
msgbox BondOfEire_Text_Mum, MSGBOX_DEFAULT
waitmessage
release
end

BondOfEire_Text_Mum:
.string "Ciarán, your father would be so proud.$"

BondOfEire_Campfire_EventScript_Campfire::
lock
faceplayer
setvar VAR_0x8004, 0
special EchoBond_Get
copyvar VAR_0x8000, VAR_RESULT
msgbox BondOfEire_Campfire_Text_BondLevel, MSGBOX_DEFAULT
waitmessage
setvar VAR_0x8004, 0
setvar VAR_0x8005, 5
special EchoBond_Increment
release
end

BondOfEire_Campfire_Text_BondLevel:
.string "The campfire crackles warmly.\nRockruff feels a little closer to you.$"

BOND_RinnuaTown_EventScript_Sign::
msgbox BOND_RinnuaTown_Text_Sign, MSGBOX_SIGN
end

BOND_RinnuaTown_Text_Sign:
.string "Rinnua Town\nWhere the cliffs meet the sea.$"

BOND_TestWarp_Campfire::
msgbox BOND_TestWarp_Campfire_Text, MSGBOX_YESNO
compare VAR_RESULT, NO
goto_if_eq BOND_TestWarp_Campfire_End
warpsilent MAP_BOND_AN_TINE_BHEO, 0
waitstate
release
end

BOND_TestWarp_Campfire_End::
release
end

BOND_TestWarp_Campfire_Text:
.string "A thin trail of smoke rises\nfrom An Tine Bheo, the old\lcampfire clearing.\pGo there now?$"

BOND_Campfire_DebugScript::
lock
faceplayer
setvar VAR_0x8004, 0
special EchoBond_Get
msgbox BOND_Campfire_DebugText, MSGBOX_DEFAULT
waitmessage
release
end

BOND_Campfire_DebugText:
.string "Echo Bond system active.$"

BrendansHouse_1F_EventScript_Mum::
release
end

CableClub_EventScript_WirelessClubAttendant_Frlg::
release
end

CableClub_EventScript_DirectCornerAttendant_Frlg::
release
end



BOND_RinnuaTown_EventScript_HouseSign1::
msgbox BOND_RinnuaTown_Text_HouseSign1, MSGBOX_SIGN
end
.string "Ó Briain Residence\nEst. 1987.$"

BOND_RinnuaTown_EventScript_HouseSign2::
msgbox BOND_RinnuaTown_Text_HouseSign2, MSGBOX_SIGN
end
.string "Rinnua Community Board\lNotice: New Trainer\lregistration open at the Lab.$"

BOND_RinnuaTown_EventScript_HouseSign3::
msgbox BOND_RinnuaTown_Text_HouseSign3, MSGBOX_SIGN
end
.string "The Ó Murchadha family.\nMind the dog.$"

BOND_RinnuaTown_Text_HouseSign1:
.string "Ó Briain Residence\nEst. 1987.$"

BOND_RinnuaTown_Text_HouseSign2:
.string "Rinnua Community Board\lNotice: New Trainer\lregistration open at the Lab.$"

BOND_RinnuaTown_Text_HouseSign3:
.string "The Ó Murchadha family.\nMind the dog.$"

BOND_RinnuaTown_EventScript_RoadBlockedTrigger::
lockall
applymovement LOCALID_ROADBLOCK, BOND_Movement_RoadBlocked_StepForward
waitmovement LOCALID_ROADBLOCK
msgbox BOND_RinnuaTown_Text_RoadBlocked, MSGBOX_DEFAULT
waitmessage
applymovement OBJ_EVENT_ID_PLAYER, BOND_Movement_RoadBlocked_PlayerStepBack
waitmovement OBJ_EVENT_ID_PLAYER
applymovement LOCALID_ROADBLOCK, BOND_Movement_RoadBlocked_StepBack
waitmovement LOCALID_ROADBLOCK
setvar VAR_RINNUA_TOWN_STATE, 1
releaseall
end

BOND_Movement_RoadBlocked_PlayerStepBack:
walk_down
step_end

BOND_Movement_RoadBlocked_StepForward:
walk_right
step_end

BOND_Movement_RoadBlocked_StepBack:
walk_left
step_end

BOND_RinnuaTown_Text_RoadBlocked:
.string "You’re not thinking of going out there\nalone, are you? The wild Pokémon\lon the north road have been restless.\lNo one’s allowed past without a partner.$"

BOND_RinnuaTown_EventScript_RoadBlockedDummy::
release
end

BOND_RinnuaTown_EventScript_LabSign::
msgbox BOND_RinnuaTown_Text_LabSign, MSGBOX_SIGN
end

BOND_RinnuaTown_Text_LabSign:
.string "Rinnua Town Research Lab\nClosed for renovations.$"

BOND_RinnuaTown_EventScript_WeatherNPC::
lock
faceplayer
msgbox BOND_RinnuaTown_Text_Weather, MSGBOX_DEFAULT
waitmessage
release
end

BOND_RinnuaTown_Text_Weather:
.string "That sea breeze never gets old.\nYou can taste the salt on your\plips long after you leave this town.$"

BOND_RinnuaTown_EventScript_BondHintNPC::
lock
faceplayer
msgbox BOND_RinnuaTown_Text_BondHint, MSGBOX_DEFAULT
waitmessage
release
end

BOND_RinnuaTown_Text_BondHint:
.string "The old ones say Pokémon can feel\nwhat you feel. Not like reading\lyour mind -- more like knowing\lyour heart.$"

BOND_Cliff_EventScript_Encounter::
    lockall
    faceplayer
    playmoncry SPECIES_ROCKRUFF, CRY_MODE_ENCOUNTER
    msgbox BOND_Cliff_Text_EncounterThesis, MSGBOX_DEFAULT
    waitmessage
    waitmoncry
    @ Give the player Rockruff (Level 5, No Item)
    givemon SPECIES_ROCKRUFF, 5, ITEM_NONE
    compare VAR_RESULT, 2
    goto_if_eq BOND_Cliff_EventScript_PartyFull
    playfanfare MUS_OBTAIN_ITEM
    msgbox BOND_Cliff_Text_ObtainedRockruff, MSGBOX_DEFAULT
    waitmessage
    waitfanfare
    @ Echo Bond tracking initialized
    setvar VAR_ECHO_BOND_LEVEL, 60
    setvar VAR_BOND_CLIFF_STATE, 1
    @ Hide the wild overworld sprite forever
    setflag FLAG_HIDE_BOND_CLIFF_ROCKRUFF
    removeobject 1
    @ Trigger the follower engine to put Rockruff behind player
    setflag FLAG_SYS_FOLLOWER_READY
    @ setfollower 1, 1
    releaseall
    end

BOND_Cliff_EventScript_PartyFull::
    msgbox BOND_Cliff_Text_PartyFull, MSGBOX_DEFAULT
    waitmessage
    releaseall
    end

BOND_Cliff_Text_EncounterThesis:
    .string "Rockruff steps forward on the windy cliff.\nNo cage. No battle. Pure trust.$"

BOND_Cliff_Text_ObtainedRockruff:
    .string "Rockruff joined your team!$"

BOND_Cliff_Text_PartyFull:
    .string "You have no room for Rockruff...$"
