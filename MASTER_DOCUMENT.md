
---

## 12. DEVELOPER INFRASTRUCTURE & PRE‑PUSH VALIDATION

### 12.1 Git Authentication Token
GitHub no longer accepts passwords for HTTPS Git operations.
1. Visit https://github.com/settings/tokens
2. Generate a classic token with scopes: `repo` (all) and `workflow`.
3. Copy the token (shown once).
4. Set the remote URL in Termux:
git remote set-url origin https://<TOKEN>@github.com/terrenceorahilly4-hue/pokeemerald-expansion.git
5. Test with `git push`.

### 12.2 Two‑Layer Git Hooks

#### Pre‑Commit Hook (`.git/hooks/pre-commit`)
Runs automatically on every `git commit`. Catches:
1. Missing `.section .text` in any `.inc` file included by `data/event_scripts.s`.
2. Stale auto‑generated headers (commit rejection).
3. Assembly `.equ` in C headers (violates Golden Rule #10).
4. Custom maps not registered in `data/map_groups.json`.
5. Custom script labels without the `BOND_` prefix.
6. Duplicate special indices in `data/specials.inc`.
7. Non‑BOND specials placed after BOND specials (Golden Rule #6).

If any check fails, the commit is aborted.

#### Pre‑Push Hook (`.git/hooks/pre-push`)
Runs after all new commits pass pre‑commit. Executes a full `make -j$(nproc) pokeemerald.gba`. If the build fails, the push is refused and the developer must fix the error locally.

### 12.3 Installing the Hooks
From the repo root, paste the hook scripts using `cat` and `chmod +x` (see `docs/INFRASTRUCTURE.md` for exact code). No interactive editor needed.

### 12.4 Skipping Hooks (Emergency Only)
- Pre‑commit: `git commit --no-verify`
- Pre‑push: `git push --no-verify`

Use only when the hook itself is broken and a fix is pending.

