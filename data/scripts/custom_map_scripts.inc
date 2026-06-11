
.align 2
BondOfEire_Campfire_MapScripts::
.byte 0

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
