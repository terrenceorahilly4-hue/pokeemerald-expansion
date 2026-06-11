import json, sys

files = {
    "Littleroot Town": "data/maps/LittlerootTown/map.json",
    "Brendan's House 1F": "data/maps/LittlerootTown_BrendansHouse_1F/map.json",
    "Brendan's House 2F": "data/maps/LittlerootTown_BrendansHouse_2F/map.json",
    "May's House 1F": "data/maps/LittlerootTown_MaysHouse_1F/map.json",
    "May's House 2F": "data/maps/LittlerootTown_MaysHouse_2F/map.json",
}

errors = 0

for name, path in files.items():
    with open(path, 'r') as f:
        data = json.load(f)
    # Check for flag "0" objects (except custom Mum)
    for obj in data.get("object_events", []):
        if obj["flag"] == "0":
            if obj.get("script") == "BrendansHouse_1F_EventScript_CustomMum":
                continue  # this is our custom Mum, allowed
            print(f"ERROR: {name} has object with flag '0' but not custom Mum:")
            print(f"  graphics_id={obj['graphics_id']}, script={obj.get('script')}, local_id={obj.get('local_id')}")
            errors += 1
    # Check duplicate local_ids
    local_ids = [obj.get("local_id") for obj in data.get("object_events", []) if "local_id" in obj]
    if len(local_ids) != len(set(local_ids)):
        print(f"ERROR: {name} has duplicate local_id values: {local_ids}")
        errors += 1
    # Check multiple MOM graphics (should be exactly 1 in Brendan's 1F, 0 elsewhere)
    mom_count = sum(1 for obj in data["object_events"] if obj["graphics_id"] == "OBJ_EVENT_GFX_MOM")
    if name == "Brendan's House 1F":
        if mom_count != 1:
            print(f"ERROR: Brendan's House 1F should have exactly 1 MOM object, found {mom_count}")
            errors += 1
    else:
        if mom_count > 0:
            print(f"WARNING: {name} has {mom_count} MOM objects (may be intentional but check)")

if errors == 0:
    print("All intro maps passed validation.")
else:
    print(f"\n{errors} error(s) found. Fix them before committing.")
    sys.exit(1)
