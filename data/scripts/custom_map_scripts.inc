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

@ Custom Mum dialogue
BrendansHouse_1F_EventScript_CustomMum::
lock
faceplayer
msgbox BrendansHouse_1F_Text_CustomMum, MSGBOX_DEFAULT
waitmessage
release
end

BrendansHouse_1F_Text_CustomMum:
.string "Your custom Mum dialogue here$"
