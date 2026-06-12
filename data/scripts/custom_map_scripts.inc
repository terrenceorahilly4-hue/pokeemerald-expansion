.align 2
BOND_RinnuaTown_MapScripts::
.byte 0

BOND_CiaransHouse_1F_MapScripts::
BOND_CiaransHouse_2F_MapScripts::
BOND_NeighboursHouse_1F_MapScripts::
BOND_NeighboursHouse_2F_MapScripts::
BOND_AnTineBheo_MapScripts::
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
    .string "The campfire crackles warmly.
Rockruff feels a little closer to you.$"
"
BrendansHouse_1F_EventScript_Mum::

BOND_RinnuaTown_EventScript_Sign::
msgbox BOND_RinnuaTown_Text_Sign, MSGBOX_SIGN
end

BOND_RinnuaTown_Text_Sign:
.string "Rinnua Town\nWhere the cliffs meet the sea.$"

CableClub_EventScript_WirelessClubAttendant_Frlg::
release
end

CableClub_EventScript_DirectCornerAttendant_Frlg::
release
end

@ --- TEMPORARY TEST SCRIPTS (remove after validation) ---

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
.string "A thin trail of smoke rises\n"
.string "from An Tine Bheo, the old\l"
.string "campfire clearing.\p"
.string "Go there now?$"

BOND_Campfire_DebugScript::
lock
faceplayer
setvar VAR_0x8004, 0
special EchoBond_Get
copyvar VAR_0x8000, VAR_RESULT
msgbox BOND_Campfire_DebugText, MSGBOX_DEFAULT
    waitmessage
release
end

BOND_Campfire_DebugText:
.string "Echo Bond (lead Pokémon): {STR_VAR_1}$"
