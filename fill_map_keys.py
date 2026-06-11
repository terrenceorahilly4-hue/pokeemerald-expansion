import json

defaults = {
    "allow_cycling": False,
    "allow_escaping": False,
    "allow_running": True,
    "show_map_name": True,
    "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
    "connections": []
}
outdoor_defaults = {
    "allow_cycling": True,
    "allow_escaping": False,
    "allow_running": True,
    "show_map_name": True,
    "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
    "connections": []
}
maps = {
    "data/maps/BondOfEire_BrendansHouse_1F/map.json": False,
    "data/maps/BondOfEire_BrendansHouse_2F/map.json": False,
    "data/maps/BondOfEire_MaysHouse_1F/map.json": False,
    "data/maps/BondOfEire_MaysHouse_2F/map.json": False,
    "data/maps/BondOfEire_LittlerootTown/map.json": True
}

for path, outdoor in maps.items():
    with open(path, 'r') as f:
        d = json.load(f)
    use = outdoor_defaults if outdoor else defaults
    for k, v in use.items():
        if k not in d:
            d[k] = v
    with open(path, 'w') as f:
        json.dump(d, f, indent=2)
print("All missing keys filled.")
