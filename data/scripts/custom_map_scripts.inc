.ifndef BOND_CUSTOM_SCRIPTS_ASSEMBLED
.set BOND_CUSTOM_SCRIPTS_ASSEMBLED, 1

BOND_RinnuaTown_Text_BondHint::
.string "The old ones say Pokémon can feel\n"
.string "what you feel. Not like reading\n"
.string "your mind - more like knowing\n"
.string "your heart.$"

BOND_Cliff_EventScript_RockruffEncounter::
lockall
goto_if_set FLAG_RECEIVED_ROCKRUFF, BOND_Cliff_EventScript_AlreadyReceived
msgbox BOND_Cliff_Text_RockruffThesis, MSGBOX_DEFAULT
waitmessage
givemon SPECIES_ROCKRUFF, 5, ITEM_NONE
compare VAR_RESULT, 0
goto_if_eq BOND_Cliff_EventScript_ReceiveParty
compare VAR_RESULT, 1
goto_if_eq BOND_Cliff_EventScript_ReceivePC
goto BOND_Cliff_EventScript_NoSpace
end

BOND_Cliff_EventScript_ReceiveParty::
setflag FLAG_RECEIVED_ROCKRUFF
msgbox BOND_Cliff_Text_PartyReceive, MSGBOX_DEFAULT
waitmessage
releaseall
end

BOND_Cliff_EventScript_ReceivePC::
setflag FLAG_RECEIVED_ROCKRUFF
msgbox BOND_Cliff_Text_PCReceive, MSGBOX_DEFAULT
waitmessage
releaseall
end

BOND_Cliff_EventScript_AlreadyReceived::
msgbox BOND_Cliff_Text_AlreadyBonded, MSGBOX_DEFAULT
waitmessage
releaseall
end

BOND_Cliff_EventScript_NoSpace::
msgbox BOND_Cliff_Text_NoSpace, MSGBOX_DEFAULT
waitmessage
releaseall
end

BOND_Cliff_Text_RockruffThesis:
.string "A wild Rockruff watches you closely.\n"
.string "No Poké Ball is thrown.\p"
.string "A bond forged in trust needs no cage.$"

BOND_Cliff_Text_PartyReceive:
.string "Rockruff joined Ciarán's party!$"

BOND_Cliff_Text_PCReceive:
.string "Rockruff was sent to the PC system!$"

BOND_Cliff_Text_AlreadyBonded:
.string "The coastal wind blankets the cliffs...$"

BOND_Cliff_Text_NoSpace:
.string "Your party and storage are full.$"


BOND_RinnuaTown_MapScripts::
    .byte 0

BOND_CiaransHouse_1F_MapScripts::
    .byte 0

BOND_CiaransHouse_2F_MapScripts::
    .byte 0

BOND_NeighboursHouse_1F_MapScripts::
    .byte 0

BOND_NeighboursHouse_2F_MapScripts::
    .byte 0

BOND_AnTineBheo_MapScripts::
    .byte 0

BOND_RinnuaTown_EventScript_RoadBlockedDummy::
BOND_RinnuaTown_EventScript_WeatherNPC::
BOND_RinnuaTown_EventScript_BondHintNPC::
BOND_RinnuaTown_EventScript_RoadBlockedTrigger::
BOND_RinnuaTown_EventScript_Sign::
BOND_RinnuaTown_EventScript_HouseSign1::
BOND_RinnuaTown_EventScript_HouseSign2::
BOND_RinnuaTown_EventScript_HouseSign3::
BOND_RinnuaTown_EventScript_LabSign::
BondOfEire_EventScript_Mum::
BondOfEire_Campfire_EventScript_Campfire::
BOND_Campfire_DebugScript::
    lockall
    msgbox BOND_Cliff_Text_AlreadyBonded, MSGBOX_DEFAULT
    releaseall
    end

.endif @ BOND_CUSTOM_SCRIPTS_ASSEMBLED
