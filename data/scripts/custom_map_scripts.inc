.align 2
BondOfEire_LittlerootTown_MapScripts::
.byte 0

.align 2
BondOfEire_BrendansHouse_1F_MapScripts::
.byte 0

.align 2
BondOfEire_BrendansHouse_2F_MapScripts::
.byte 0

.align 2
BondOfEire_MaysHouse_1F_MapScripts::
.byte 0

.align 2
BondOfEire_MaysHouse_2F_MapScripts::
.byte 0

.align 2
BondOfEire_Campfire_MapScripts::
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
