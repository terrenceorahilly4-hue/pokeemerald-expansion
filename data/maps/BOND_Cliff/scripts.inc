.align 2

BOND_Cliff_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, BOND_Cliff_OnFrame
.byte 0

BOND_Cliff_OnFrame:
map_script_2 VAR_BOND_CLIFF_STATE, 1, BOND_Cliff_EventScript_CinematicIntro
.2byte 0

BOND_Cliff_EventScript_CinematicIntro::
lockall

playse SE_M_GUST
fadescreen FADE_FROM_BLACK
delay 120 

applymovement OBJ_EVENT_ID_PLAYER, BOND_Cliff_Movement_LookAround
waitmovement 0
delay 40

playse SE_PIN
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
waitmovement 0
delay 40

applymovement 1, BOND_Cliff_Movement_RockruffApproach
waitmovement 0
delay 30

msgbox BOND_Cliff_Text_EchoBond, MSGBOX_DEFAULT
closemessage

setvar VAR_ECHO_BOND_LEVEL, 60 
givemon SPECIES_ROCKRUFF, 5, ITEM_NONE
playbgm MUS_ROUTE101, 0
playfanfare MUS_LEVEL_UP
message BOND_Cliff_Text_Joined
waitmessage
waitfanfare
closemessage

setflag FLAG_RECEIVED_ROCKRUFF
removeobject 1
setflag FLAG_HIDE_BOND_CLIFF_ROCKRUFF
setflag FLAG_SYS_FOLLOWER_READY
setvar VAR_BOND_CLIFF_STATE, 2

releaseall
end

BOND_Cliff_Movement_LookAround:
face_left
delay_16
face_right
delay_16
face_down
step_end

BOND_Cliff_Movement_RockruffApproach:
walk_slow_down
walk_slow_down
step_end

BOND_Cliff_Text_EchoBond:
.string "A wild ROCKRUFF steps out.\n"
.string "A bond forged in trust needs no cage.$"

BOND_Cliff_Text_Joined:
.string "ROCKRUFF has chosen your side!$"
