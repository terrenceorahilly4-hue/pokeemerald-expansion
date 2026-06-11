#ifndef GUARD_ECHO_BOND_H
#define GUARD_ECHO_BOND_H

#include "global.h"

#define ECHO_BOND_MAX 100

void EchoBond_Get(void);
void EchoBond_Set(void);
void EchoBond_Increment(void);
u8 GetEchoBondValue(u8 partyIndex);

#endif // GUARD_ECHO_BOND_H
