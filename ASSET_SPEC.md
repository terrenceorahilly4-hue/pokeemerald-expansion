# Asset Specification — Bond of Éire

## Tileset PNGs
| Property | Value |
|----------|-------|
| Tile size | 16×16 px |
| Colour mode | Indexed PNG (palette mode) |
| Max colours per palette | 16 |
| Colour 0 | Transparent (background) |
| Sheet layout | Tiles arranged left-to-right, top-to-bottom |
| File format | .png only |

## Palette
Use the project master palette (`graphics/palettes/eire_outdoor.pal`).
New tilesets may introduce 1 new 16-colour sub-palette if necessary —
discuss with the maintainer before creating one.

## Delivery Process
1. Create a branch: `feature/eire-<tileset-name>`
2. Add your files to `graphics/tilesets/overworld/eire/<tileset_name>/`
3. Include a `preview.png` showing tiles in a rough test map (or mockup)
4. Open a PR against `echo-bond-foundation`
5. Fill in the PR template — include screenshots

## Integration (maintainer does this)
After merging the PNG, the maintainer will:
1. Register the tileset in `data/tilesets/`
2. Create a test map to verify rendering
3. Commit the integration on the same or a follow-up branch
