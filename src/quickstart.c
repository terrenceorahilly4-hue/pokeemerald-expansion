#include "global.h"
#include "config/general.h"
#include "constants/global.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "graphics.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "config/quickstart.h"
#include "quickstart.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "event_data.h"


#define TAG_SKIP_INTRO 2000

static const u32 gQuickstartHudGfx[] = INCGFX_U32("graphics/quickstart/quickstart_hud.png", ".4bpp.smol");
#if FIRERED
static const u16 gQuickstartHudPal[] = INCGFX_U16("graphics/quickstart/firered.pal", ".gbapal");
#elif LEAFGREEN
static const u16 gQuickstartHudPal[] = INCGFX_U16("graphics/quickstart/leafgreen.pal", ".gbapal");
#else
static const u16 gQuickstartHudPal[] = INCGFX_U16("graphics/quickstart/emerald.pal", ".gbapal");
#endif

static const struct OamData sQuickstartHudOam = {
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .priority = 0,
    .paletteNum = 0,
};

static const struct SpriteTemplate sQuickstartHudTemplate = {
    .tileTag = TAG_SKIP_INTRO,
    .paletteTag = TAG_SKIP_INTRO,
    .oam = &sQuickstartHudOam,
    .anims = gDummySpriteAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_QuickstartHud = {
    .data = gQuickstartHudGfx,
    .size = 0x200,
    .tag = TAG_SKIP_INTRO
};
static const struct SpritePalette sSpritePalette_QuickstartHud = {
    .data = gQuickstartHudPal,
    .tag = TAG_SKIP_INTRO
};

static inline enum Gender SetQuickstartPlayerGender()
{
    switch (QUICKSTART_GENDER)
    {
        case GENDER_MALE:
            return MALE;
        case GENDER_FEMALE:
            return FEMALE;
        case GENDER_RANDOM:
        default:
            return RandomPercentage(RNG_NONE, 50) ? FEMALE : MALE;
    }
}

static void CB2_SkipToNewGame(void)
{
#if IS_FRLG
    static const u8 sText_PlayerMale[] = _("RED");
    static const u8 sText_PlayerFemale[] = _("LEAF");
    static const u8 sText_Rival[] = _("BLUE");
#else
    static const u8 sText_PlayerMale[] = _("BRENDAN");
    static const u8 sText_PlayerFemale[] = _("MAY");
#endif  // IS_FRLG

    if (!UpdatePaletteFade())
    {
        gSaveBlock2Ptr->playerGender = SetQuickstartPlayerGender();
        const u8* textPtr = gSaveBlock2Ptr->playerGender == FEMALE ? sText_PlayerFemale : sText_PlayerMale;
        StringCopy_PlayerName(gSaveBlock2Ptr->playerName, textPtr);

#if IS_FRLG
        StringCopy_PlayerName(gSaveBlock1Ptr->rivalName, sText_Rival);
#endif  // IS_FRLG

        ResetSpriteData();
        FreeAllSpritePalettes();
        ResetTasks();
        FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK);
        FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK);
        VarSet(VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1);
        VarSet(VAR_LITTLEROOT_HOUSES_STATE_MAY, 1);

    FlagSet(FLAG_SYS_POKEMON_GET);
    FlagSet(FLAG_SYS_POKEDEX_GET);
    FlagSet(FLAG_ADVENTURE_STARTED);

    // Hide all vanilla intro NPCs permanently
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_TWIN);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BIRCH);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_RIVAL);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM);
    FlagSet(FLAG_HIDE_PLAYERS_HOUSE_DAD);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN);

    // Advance intro states to disable any remaining vanilla triggers
    // Fast-forward map script states to bypass vanilla events
    VarSet(VAR_LITTLEROOT_INTRO_STATE, 7);          // 7 = Intro sequence fully complete
    VarSet(VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2); // 2 = Mom TV event complete
    VarSet(VAR_LITTLEROOT_HOUSES_STATE_MAY, 2);     // 2 = May's intro complete
    VarSet(VAR_LITTLEROOT_TOWN_STATE, 4);           // 4 = Town is fully open, no blockers
        SetWarpDestination(MAP_GROUP(MAP_FLASHBACK_ROOM), MAP_NUM(MAP_FLASHBACK_ROOM), 0, -1, -1);
        SetMainCallback2(CB2_NewGame);
    }
}

static void LoadQuickstartSpritsheetAndPal(void)
{
    LoadCompressedSpriteSheet(&sSpriteSheet_QuickstartHud);
    LoadSpritePalette(&sSpritePalette_QuickstartHud);
}

void CreateQuickstartHud(void)
{
    s16 x = QUICKSTART_HUD_X;
    s16 y = QUICKSTART_HUD_Y;

    LoadQuickstartSpritsheetAndPal();
    CreateSprite(&sQuickstartHudTemplate, x, y, 0);
}

void Quickstart(void)
{
    if (!gPaletteFade.active)
    {
        FadeOutBGM(4);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        SetMainCallback2(CB2_SkipToNewGame);
    }
}

