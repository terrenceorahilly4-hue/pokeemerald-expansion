.align 2

BOND_CiaransHouse_2F_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, BOND_CiaransHouse_2F_OnFrame
.byte 0

BOND_CiaransHouse_2F_OnFrame:
map_script_2 VAR_BOND_CLIFF_STATE, 0, BOND_CiaransHouse_2F_EventScript_ColdOpen
.2byte 0

BOND_CiaransHouse_2F_EventScript_ColdOpen::
lockall

@ 1. THE VOID
fadescreen FADE_TO_BLACK
delay 60

@ Title Cards
msgbox BOND_CiaransHouse_2F_Text_Studio, MSGBOX_DEFAULT
closemessage
delay 40

msgbox BOND_CiaransHouse_2F_Text_Title, MSGBOX_DEFAULT
closemessage
delay 60

@ The Call
msgbox BOND_CiaransHouse_2F_Text_TheCall, MSGBOX_DEFAULT
closemessage
delay 30

@ 2. THE AWAKENING
playse SE_M_HEAL_BELL
fadescreen FADE_TO_WHITE
delay 60
fadescreen FADE_FROM_WHITE
delay 30

@ 3. THE TRANCE
applymovement OBJ_EVENT_ID_PLAYER, BOND_CiaransHouse_2F_Movement_TranceExit
waitmovement 0

@ 4. BLACKOUT
fadescreen FADE_TO_BLACK
delay 45

setvar VAR_BOND_CLIFF_STATE, 1
warp MAP_BOND_CLIFF, 10, 10
waitstate
releaseall
end

BOND_CiaransHouse_2F_Movement_TranceExit:
walk_slow_down
walk_slow_left
walk_slow_down
step_end

BOND_CiaransHouse_2F_Text_Studio:
.string "          T-Rex Studio Presents$"

BOND_CiaransHouse_2F_Text_Title:
.string "         POKéMON: BOND OF ÉIRE$"

BOND_CiaransHouse_2F_Text_TheCall:
.string "...Do you hear it?\n"
.string "The echo in the wind...\p"
.string "Find me.$"
