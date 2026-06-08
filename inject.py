import json

# ---------- layouts.json ----------
with open("data/layouts/layouts.json", "r") as f:
    data = json.load(f)

layout_list = data["layouts"]

new_layout = {
    "id": "LAYOUT_FLASHBACK_ROOM",
    "width": 5,
    "height": 5,
    "border": "METADATA_BORDER_GENERAL",
    "blockdata": "data/layouts/FlashbackRoom/map.bin",
    "layouts_table_label": "FlashbackRoom"
}

if not any(l.get("id") == "LAYOUT_FLASHBACK_ROOM" for l in layout_list):
    layout_list.append(new_layout)
    with open("data/layouts/layouts.json", "w") as f:
        json.dump(data, f, indent=4)
    print("Layout added.")
else:
    print("Layout already exists.")

# ---------- map_groups.json ----------
with open("data/maps/map_groups.json", "r") as f:
    groups = json.load(f)

order = groups["group_order"]
if "FlashbackRoom" not in order:
    pos = order.index("InsideOfTruck") if "InsideOfTruck" in order else len(order)-1
    order.insert(pos+1, "FlashbackRoom")

littleroot = groups["gMapGroup_IndoorLittleroot"]
if "MAP_FLASHBACK_ROOM" not in littleroot:
    pos = littleroot.index("LittlerootTown_ProfessorBirchsLab") if "LittlerootTown_ProfessorBirchsLab" in littleroot else len(littleroot)-1
    littleroot.insert(pos+1, "MAP_FLASHBACK_ROOM")

with open("data/maps/map_groups.json", "w") as f:
    json.dump(groups, f, indent=4)

print("Map group updated.")
