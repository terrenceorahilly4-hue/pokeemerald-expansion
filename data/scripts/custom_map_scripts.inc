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

BondOfEire_EventScript_Mum::
lock
faceplayer
msgbox BondOfEire_Text_Mum, MSGBOX_DEFAULT
waitmessage
release
end

BondOfEire_Text_Mum:
.string "Ciarán, your father would be so proud.$"
