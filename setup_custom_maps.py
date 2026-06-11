import json, os

maps = {
    "BondOfEire_LittlerootTown": {
        "id": "MAP_BOND_OF_EIRE_LITTLEROOT_TOWN",
        "name": "BondOfEire_LittlerootTown",
        "layout": "LAYOUT_LITTLEROOT_TOWN",
        "map_type": "MAP_TYPE_TOWN",
        "outdoor": True,
        "warps": [
            {"x":14,"y":8,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_MAYS_HOUSE_1F","dest_warp_id":1},
            {"x":5,"y":8,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_BRENDANS_HOUSE_1F","dest_warp_id":1},
            {"x":7,"y":16,"elevation":0,"dest_map":"MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB","dest_warp_id":0}
        ]
    },
    "BondOfEire_BrendansHouse_1F": {
        "id": "MAP_BOND_OF_EIRE_BRENDANS_HOUSE_1F",
        "name": "BondOfEire_BrendansHouse_1F",
        "layout": "LAYOUT_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F",
        "map_type": "MAP_TYPE_INDOOR",
        "outdoor": False,
        "warps": [
            {"x":9,"y":8,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_LITTLEROOT_TOWN","dest_warp_id":1},
            {"x":8,"y":8,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_LITTLEROOT_TOWN","dest_warp_id":1},
            {"x":8,"y":2,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_BRENDANS_HOUSE_2F","dest_warp_id":0}
        ],
        "has_mum": True
    },
    "BondOfEire_BrendansHouse_2F": {
        "id": "MAP_BOND_OF_EIRE_BRENDANS_HOUSE_2F",
        "name": "BondOfEire_BrendansHouse_2F",
        "layout": "LAYOUT_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F",
        "map_type": "MAP_TYPE_INDOOR",
        "outdoor": False,
        "warps": [
            {"x":7,"y":1,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_BRENDANS_HOUSE_1F","dest_warp_id":2}
        ]
    },
    "BondOfEire_MaysHouse_1F": {
        "id": "MAP_BOND_OF_EIRE_MAYS_HOUSE_1F",
        "name": "BondOfEire_MaysHouse_1F",
        "layout": "LAYOUT_LITTLEROOT_TOWN_MAYS_HOUSE_1F",
        "map_type": "MAP_TYPE_INDOOR",
        "outdoor": False,
        "warps": [
            {"x":1,"y":8,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_LITTLEROOT_TOWN","dest_warp_id":0},
            {"x":2,"y":8,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_LITTLEROOT_TOWN","dest_warp_id":0},
            {"x":2,"y":2,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_MAYS_HOUSE_2F","dest_warp_id":0}
        ]
    },
    "BondOfEire_MaysHouse_2F": {
        "id": "MAP_BOND_OF_EIRE_MAYS_HOUSE_2F",
        "name": "BondOfEire_MaysHouse_2F",
        "layout": "LAYOUT_LITTLEROOT_TOWN_MAYS_HOUSE_2F",
        "map_type": "MAP_TYPE_INDOOR",
        "outdoor": False,
        "warps": [
            {"x":1,"y":1,"elevation":0,"dest_map":"MAP_BOND_OF_EIRE_MAYS_HOUSE_1F","dest_warp_id":2}
        ]
    }
}

for folder, info in maps.items():
    path = f"data/maps/{folder}"
    os.makedirs(path, exist_ok=True)

    map_data = {
        "id": info["id"],
        "name": info["name"],
        "layout": info["layout"],
        "music": "MUS_LITTLEROOT",
        "region": "REGION_HOENN",
        "region_map_section": "MAPSEC_LITTLEROOT_TOWN",
        "requires_flash": False,
        "weather": "WEATHER_NONE",
        "map_type": info["map_type"],
        "allow_cycling": info["outdoor"],
        "allow_escaping": False,
        "allow_running": True,
        "show_map_name": True,
        "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
        "connections": [],
        "object_events": [],
        "warp_events": info["warps"],
        "coord_events": [],
        "bg_events": []
    }

    if info.get("has_mum"):
        map_data["object_events"].append({
            "graphics_id": "OBJ_EVENT_GFX_MOM",
            "x": 2, "y": 6, "elevation": 3,
            "movement_type": "MOVEMENT_TYPE_FACE_RIGHT",
            "movement_range_x": 0, "movement_range_y": 0,
            "trainer_type": "TRAINER_TYPE_NONE",
            "trainer_sight_or_berry_tree_id": "0",
            "script": "BondOfEire_BrendansHouse_1F_EventScript_CustomMum",
            "flag": "0"
        })

    with open(f"{path}/map.json", "w") as f:
        json.dump(map_data, f, indent=2)

    with open(f"{path}/scripts.inc", "w") as f:
        f.write(".byte 0\n")

print("Custom maps created successfully.")
