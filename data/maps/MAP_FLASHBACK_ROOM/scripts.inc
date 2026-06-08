FlashbackRoom_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, FlashbackRoom_OnTransition
    .byte 0

FlashbackRoom_OnTransition::
    call FlashbackRoom_EventScript_Intro
    end

FlashbackRoom_EventScript_Intro::
    msgbox FlashbackRoom_Text_StudioCard, MSGBOX_DEFAULT
    closemessage
    delay 60
    msgbox FlashbackRoom_Text_TitleCard, MSGBOX_DEFAULT
    closemessage
    delay 90
    playse SE_THUNDER
    delay 40
    msgbox FlashbackRoom_Text_Storm1, MSGBOX_DEFAULT
    closemessage
    delay 30
    msgbox FlashbackRoom_Text_Storm2, MSGBOX_DEFAULT
    closemessage
    delay 30
    msgbox FlashbackRoom_Text_Rowan1, MSGBOX_DEFAULT
    closemessage
    delay 30
    msgbox FlashbackRoom_Text_Rowan2, MSGBOX_DEFAULT
    closemessage
    delay 30
    msgbox FlashbackRoom_Text_Rowan3, MSGBOX_DEFAULT
    closemessage
    delay 90
    msgbox FlashbackRoom_Text_Narration1, MSGBOX_DEFAULT
    closemessage
    delay 60
    msgbox FlashbackRoom_Text_Narration2, MSGBOX_DEFAULT
    closemessage
    delay 90
    msgbox FlashbackRoom_Text_WakeUp, MSGBOX_DEFAULT
    closemessage
    fadescreen 1
    delay 20
    warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 6, 8
    waitstate
    releaseall
    end

FlashbackRoom_Text_StudioCard:
    .string "T-Rex Studio presents...$"

FlashbackRoom_Text_TitleCard:
    .string "POKéMON: BOND OF ÉIRE$"

FlashbackRoom_Text_Storm1:
    .string "The sea was angry that night...\n"
    .string "The kind of angry that\n"
    .string "swallows ships whole.$"

FlashbackRoom_Text_Storm2:
    .string "The cliffs of Éire.\p"
    .string "Three years ago.$"

FlashbackRoom_Text_Rowan1:
    .string "ROWAN: Ciarán.\p"
    .string "Remember what I told you.$"

FlashbackRoom_Text_Rowan2:
    .string "ROWAN: A bond isn't something\n"
    .string "you catch.\p"
    .string "It finds you.$"

FlashbackRoom_Text_Rowan3:
    .string "ROWAN: When it does...\n"
    .string "don't let go.$"

FlashbackRoom_Text_Narration1:
    .string "Your father didn't come home.\p"
    .string "The sea remembers.$"

FlashbackRoom_Text_Narration2:
    .string "......$"

FlashbackRoom_Text_WakeUp:
    .string "You wake up.$"
