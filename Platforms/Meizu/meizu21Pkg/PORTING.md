# meizu21 firmware platform

The platform targets Meizu 21 (M461Q), Qualcomm SM8650. Derived from the
sheng (Xiaomi Pad 6S Pro, SM8550) board package: register bases match SM8550,
the SM8650 differences (CPU 1+5+2, Adreno 750, GMU 750.1) live in
UniXNU-sm8650-common.

## Memory and firmware inputs (REQUIRED)

The sheng memory map reconciled 34 Linux DTS reservations with 27 stock
memory-map regions. For meizu21 the equivalent inputs still have to be
collected:

- REQUIRED: Meizu 21 official fastboot archive (URL, SHA-256, MD5, bytes)
  and its extracted `uefiplat.cfg` SHA-256.
- REQUIRED: memory map from the stock firmware / Linux DTS reservations
  (memory, PIL gaps, display/Demura, DBI dump, CPU vectors).
- The 3 MiB FD at `0xa7100000` follows the sheng/houji SM8650 layout;
  verify against the Meizu 21 ABL UEFI window before the first boot.

## Display and interrupts

- Meizu 21 stock panel: 6.55" 2340x1080 AMOLED (Samsung diamond). The
  framebuffer PCDs are placeholders from the spec sheet; confirm the
  ABL-supplied geometry on first boot.
- `MEIZU21_VENDOR_HW = 0` (Mu drivers only) is the default; the previous
  stage's display keeps scanning out so the UniXNU menu is visible without
  vendor hardware drivers. Panel initialization needs hardware verification.
- Interrupt masking follows the sheng GIC-Spurious patch from the shared
  resources; verify IPCC INTIDs against SM8650 on first boot.

## UniXNU integration

UniXNU supplies the application package and registrar. DarwinBoot loads the
XNU kernel and ADT sidecar. UniXNU-meizu21 selects board firmware and
boot-image parameters. UniXNU-sm8650-common supplies shared XNU platform
operations.

`UniXNURamDiskDxe` comes from UniXNU's shared package. `Meizu21BootMemoryDxe`
adds DRAM within the board's mapping limits; both are listed in the platform
DSC and firmware volume.

Build through the UniXNU resolver using [Building.md](../../../Building.md).

## Verification report

Pending: record firmware configuration and source revisions, build result,
container inspection, device boot, GOP output, and interrupt behavior once
the firmware inputs and a boot path are available.
