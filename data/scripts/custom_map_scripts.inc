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
setvar VAR_0x8004, 0
setvar VAR_0x8005, 5
special EchoBond_Increment
release
end

BondOfEire_Campfire_Text_BondLevel:
.string "The campfire crackles warmly.\nRockruff feels a little closer to you.$"

BrendansHouse_1F_EventScript_Mum::
.byte 0
