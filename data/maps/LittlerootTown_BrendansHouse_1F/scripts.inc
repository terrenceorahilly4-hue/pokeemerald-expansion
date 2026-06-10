LittlerootTown_BrendansHouse_1F_MapScripts::
.byte 0

BrendansHouse_1F_EventScript_CustomMum::
lock
faceplayer
msgbox BrendansHouse_1F_Text_CustomMum, MSGBOX_DEFAULT
waitmessage
release
end

BrendansHouse_1F_Text_CustomMum:
.string "MOM: Ciarán, your father would be\n"
.string "so proud of you.\p"
.string "Come home safe, love.$"
