# Contributing to Pokémon: Bond of Éire

Thank you for contributing to Bond of Éire! This document explains everything you
need to get started, regardless of your OS or experience level.

---

## Table of Contents
1. [Project Overview](#project-overview)
2. [Setting Up Your Build Environment](#setting-up-your-build-environment)
3. [Branching & Workflow](#branching--workflow)
4. [Naming Conventions](#naming-conventions)
5. [Testing Your Changes](#testing-your-changes)
6. [Submitting a Pull Request](#submitting-a-pull-request)
7. [Asset Contribution Guidelines](#asset-contribution-guidelines)
8. [Code of Conduct](#code-of-conduct)

---

## Project Overview

Pokémon: Bond of Éire is a GBA ROM hack built on
[pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion).
It is a fan-made project set in an Ireland-inspired region. You can read the
full Story & Feature Bible in the repository Wiki.

---

## Setting Up Your Build Environment

### Prerequisites (all platforms)
- Git
- devkitARM (part of [devkitPro](https://devkitpro.org/wiki/Getting_Started))
- Python 3.x
- GNU make

### Windows
1. Install [devkitPro for Windows](https://github.com/devkitPro/installer/releases)
   and select `GBA Development` during setup.
2. Use **MSYS2** (bundled with devkitPro) for all shell commands.
3. Clone the repo inside MSYS2:
   ```bash
   git clone https://github.com/terrenceorahilly4-hue/pokeemerald-expansion.git
   cd pokeemerald-expansion
   git checkout echo-bond-foundation


