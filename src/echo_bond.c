#include "global.h"
#include "echo_bond.h"
#include "script.h"
#include "event_data.h"

void EchoBond_Get(void)
{
    u8 index = gSpecialVar_0x8004;
    if (index >= PARTY_SIZE)
    {
        gSpecialVar_Result = 0;
        return;
    }
    gSpecialVar_Result = gSaveBlock1Ptr->echoStrength[index];
}

void EchoBond_Set(void)
{
    u8 index = gSpecialVar_0x8004;
    u16 value = gSpecialVar_0x8005;
    if (index >= PARTY_SIZE)
        return;
    gSaveBlock1Ptr->echoStrength[index] = (value > ECHO_BOND_MAX) ? ECHO_BOND_MAX : (u8)value;
}

void EchoBond_Increment(void)
{
    u8 index = gSpecialVar_0x8004;
    u16 amount = gSpecialVar_0x8005;
    u16 newVal;
    if (index >= PARTY_SIZE)
        return;
    newVal = (u16)gSaveBlock1Ptr->echoStrength[index] + amount;
    gSaveBlock1Ptr->echoStrength[index] = (newVal > ECHO_BOND_MAX) ? ECHO_BOND_MAX : (u8)newVal;
}

u8 GetEchoBondValue(u8 partyIndex)
{
    if (partyIndex >= PARTY_SIZE)
        return 0;
    return gSaveBlock1Ptr->echoStrength[partyIndex];
}
