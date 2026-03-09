# K15 Max Vial Extra Layers Implementation Plan

> **For Claude:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Expose four additional blank Vial-editable layers for `keychron/k15_max/ansi_encoder/rgb:vial`, expanding the keymap from 4 layers to 8.

**Architecture:** Keep the change scoped to the target Vial keymap. Raise the dynamic keymap layer count in the keymap-local build config, then extend the layer enum, keymap table, and encoder map with four transparent fallback layers so Vial can edit them without changing the default firmware behavior.

**Tech Stack:** QMK firmware, Vial keymap configuration, C

---

### Task 1: Expand the Vial layer capacity

**Files:**
- Modify: `keyboards/keychron/k15_max/ansi_encoder/rgb/keymaps/vial/rules.mk`

**Step 1: Update the Vial build flags**

Add:

```make
OPT_DEFS += -DDYNAMIC_KEYMAP_LAYER_COUNT=8
```

**Step 2: Verify the keymap-local rules remain minimal**

Check that existing `VIA_ENABLE`, `VIAL_ENABLE`, `VIALRGB_ENABLE`, and `LTO_ENABLE` entries are preserved.

### Task 2: Add four blank layers to the Vial keymap

**Files:**
- Modify: `keyboards/keychron/k15_max/ansi_encoder/rgb/keymaps/vial/keymap.c`

**Step 1: Extend the layer enum**

Add four new layer identifiers after `WIN_FN`.

**Step 2: Add four transparent layer definitions**

Create layer entries whose positions are all `KC_TRNS` / `_______` so Vial exposes blank editable layers without preassigned behavior.

**Step 3: Extend the encoder map**

Add entries for the new layers so the encoder map indexes remain aligned with the new layer count.

### Task 3: Verify the target firmware builds

**Files:**
- Verify: `keychron/k15_max/ansi_encoder/rgb:vial`

**Step 1: Run the keyboard build**

Run:

```bash
make keychron/k15_max/ansi_encoder/rgb:vial
```

**Step 2: Confirm success**

Expected: build exits 0 and produces the target firmware artifact with no layer-related compile errors.
