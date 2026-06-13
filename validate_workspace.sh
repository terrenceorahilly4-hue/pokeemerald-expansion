#!/bin/bash
# ==============================================================================
# 🛡️ POKÉMON BOND OF ÉIRE - AUTOMATED WORKSPACE INTEGRITY SHIELD
# ==============================================================================
echo "========================================================"
echo "🔮 Running T-Rex Studio Project Pre-Flight Workspace Audit..."
echo "========================================================"
FAIL=0

# 1. Typo Redirect Sweeper
for ghost in "=" ">" "1" "2"; do
    if [ -f "$ghost" ]; then
        echo "⚠️ Ghost file anomaly detected: '$ghost'. Auto-vaporizing..."
        rm -f "$ghost"
    fi
done

# 2. Header Isolation Sentinel
echo -n "🔍 Checking C header files for illegal assembly syntax... "
if grep -rnE "^\s*\.(equ|byte|word|short|global|extern)" include/ include/constants/ 2>/dev/null; then
    echo -e "\n❌ CRITICAL CRASH RISK: Assembly directives slipped into C headers!"
    echo "Check the files listed above and replace them with standard #define syntax."
    FAIL=1
else
    echo "PASSED."
fi

# 3. Double Inclusion Trap
echo -n "🔍 Checking Master Index inclusion bounds... "
inc_count=$(grep -c "custom_map_scripts.inc" data/event_scripts.s 2>/dev/null)
if [ "$inc_count" -gt 1 ]; then
    echo -e "\n❌ CRITICAL LINKER FAILURE: 'custom_map_scripts.inc' is included $inc_count times in data/event_scripts.s."
    FAIL=1
elif [ "$inc_count" -eq 0 ]; then
    echo -e "\n❌ CRITICAL LINKER FAILURE: 'custom_map_scripts.inc' is not connected to data/event_scripts.s."
    FAIL=1
else
    echo "PASSED."
fi

# 4. Map Script Quarantine Check
echo -n "🔍 Auditing custom map isolation profiles... "
rogue_maps=$(grep -rl "\.include" data/maps/BOND_*/scripts.inc 2>/dev/null)
if [ ! -z "$rogue_maps" ]; then
    echo -e "\n❌ CRITICAL NAMESPACE CORRUPTION: Rogue .include found in map files:"
    echo "$rogue_maps"
    FAIL=1
else
    echo "PASSED."
fi

# 5. EOF Parser Guard
echo -n "🔍 Verifying trailing file newline anchors... "
if [ -f "data/scripts/custom_map_scripts.inc" ]; then
    last_char=$(tail -c 1 data/scripts/custom_map_scripts.inc 2>/dev/null)
    if [ "$last_char" != "" ]; then
        echo -e "\n⚠️ Missing trailing newline in custom_map_scripts.inc. Automatically appending... "
        printf "\n" >> data/scripts/custom_map_scripts.inc
    fi
    echo "PASSED."
else
    echo "SKIPPED (File Missing)."
fi

# Final Evaluation Pass
echo "========================================================"
if [ "$FAIL" -eq 1 ]; then
    echo "🛑 AUDIT FAILED: Structural defects must be resolved before pushing."
    echo "========================================================"
    exit 1
else
    echo "✅ WORKSPACE IS CLEAN: Safe to proceed with system compilation."
    echo "========================================================"
    exit 0
fi
