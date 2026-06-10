import json

def hide_all(file_path):
    with open(file_path, 'r') as f:
        data = json.load(f)
    for obj in data['object_events']:
        obj['flag'] = 'FLAG_UNUSED_0x020'
    with open(file_path, 'w') as f:
        json.dump(data, f, indent=2)

def setup_brendans_house(file_path):
    with open(file_path, 'r') as f:
        data = json.load(f)
    for obj in data['object_events']:
        if obj['graphics_id'] == 'OBJ_EVENT_GFX_MOM':
            obj['flag'] = '0'
            obj['script'] = 'BrendansHouse_1F_EventScript_CustomMum'
        else:
            obj['flag'] = 'FLAG_UNUSED_0x020'
    with open(file_path, 'w') as f:
        json.dump(data, f, indent=2)

hide_all('data/maps/LittlerootTown/map.json')
hide_all('data/maps/LittlerootTown_MaysHouse_1F/map.json')
hide_all('data/maps/LittlerootTown_MaysHouse_2F/map.json')
hide_all('data/maps/LittlerootTown_BrendansHouse_2F/map.json')
setup_brendans_house('data/maps/LittlerootTown_BrendansHouse_1F/map.json')
print("JSONs successfully updated.")
