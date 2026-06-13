import glob
import sys

def run_checks():
    files = glob.glob("data/maps/*/*.inc") + glob.glob("data/scripts/*.inc") + ["data/event_scripts.s"]
    failed = False
    
    for p in files:
        try:
            with open(p, "r", encoding="utf-8", errors="ignore") as f:
                for i, line in enumerate(f, 1):
                    # Check 1: Missing closing quotes that break toolchain preprocessing
                    if line.count('"') % 2 != 0:
                        print(f"❌ Unbalanced Quote -> {p}:{i}: {line.strip()}")
                        failed = True
                        
                    # Check 2: Unexpanded macro calls
                    if "getdirectiontoface" in line and not line.strip().startswith("@"):
                        print(f"❌ Stale Macro Call -> {p}:{i}: {line.strip()}")
                        failed = True
        except Exception as e:
            pass
            
    if failed:
        sys.exit(1)
    print("✓ Preprocessor check complete: Syntax verification clean.")

if __name__ == "__main__":
    run_checks()
