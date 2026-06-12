BOND_Cliff_MapScripts::
.byte 0

BOND_Cliff_EventScript_RockruffEncounter::
lockall
msgbox BOND_Cliff_Text_RockruffThesis, MSGBOX_DEFAULT
waitmessage
release
end

BOND_Cliff_Text_RockruffThesis:
.string "A wild Rockruff watches you closely.\n"
.string "A bond forged in trust needs no cage.$"
