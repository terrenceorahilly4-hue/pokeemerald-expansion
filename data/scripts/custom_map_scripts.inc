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
setvar VAR_0x8004, 0
special EchoBond_Get
copyvar VAR_0x8000, VAR_RESULT
msgbox BondOfEire_Campfire_Text_BondLevel, MSGBOX_DEFAULT
setvar VAR_0x8005, 5
special EchoBond_Increment
BondOfEire_Campfire_Text_BondLevel:
.string "The campfire crackles warmly.\nRockruff feels a little closer to you.$"
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
