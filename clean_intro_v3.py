import json

def set_flag_zero_objects(file_path, new_flag, keep_mum=False):
    with open(file_path, 'r') as f:
        data = json.load(f)
    for obj in data['object_events']:
        if obj['flag'] == '0':
            if keep_mum and obj.get('script') == 'BrendansHouse_1F_EventScript_CustomMum':
                continue
            obj['flag'] = new_flag
    with open(file_path, 'w') as f:
        json.dump(data, f, indent=2)

NEW_FLAG = 'FLAG_HIDE_INTRO_NPC'

set_flag_zero_objects('data/maps/LittlerootTown/map.json', NEW_FLAG)
set_flag_zero_objects('data/maps/LittlerootTown_MaysHouse_1F/map.json', NEW_FLAG)
set_flag_zero_objects('data/maps/LittlerootTown_MaysHouse_2F/map.json', NEW_FLAG)
set_flag_zero_objects('data/maps/LittlerootTown_BrendansHouse_2F/map.json', NEW_FLAG)
set_flag_zero_objects('data/maps/LittlerootTown_BrendansHouse_1F/map.json', NEW_FLAG, keep_mum=True)

# Ensure Mum has custom script and flag 0
with open('data/maps/LittlerootTown_BrendansHouse_1F/map.json', 'r+') as f:
    data = json.load(f)
    for obj in data['object_events']:
        if obj['graphics_id'] == 'OBJ_EVENT_GFX_MOM':
            obj['script'] = 'BrendansHouse_1F_EventScript_CustomMum'
            obj['flag'] = '0'
    f.seek(0)
    json.dump(data, f, indent=2)
    f.truncate()

print("Done.")
