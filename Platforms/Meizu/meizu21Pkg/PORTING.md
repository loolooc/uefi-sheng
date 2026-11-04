# meizu21 firmware platform

The platform targets Meizu 21 (M461Q), Qualcomm SM8650. Derived from the
sheng (Xiaomi Pad 6S Pro, SM8550) board package: register bases match SM8550,
the SM8650 differences (CPU 1+5+2, Adreno 750, GMU 750.1) live in
UniXNU-sm8650-common.

## Memory and firmware inputs (partially collected)

Firmware input status (2026-11-04):

- COLLECTED: Meizu 21 Flyme 12.6.0.0A OTA archive (device id 198) located and
  its payload manifest parsed. The following UEFI partition images were
  extracted over HTTP ranges from the payload (SHA-256 verified against the
  manifest, see UniXNU-meizu21 `board.toml [firmware.partitions]`):
  - abl (270336 B, ELF) - contains a UEFI FV (signature `_FVH` at 0x1028)
  - xbl (1105920 B, ELF) - main UEFI firmware
  - xbl_config, uefisecapp, imagefv, devcfg
- COLLECTED: Memory map input from the official Flyme 12.6.0.0A vendor_boot
  DTB (extracted from the OTA payload): 35 stock reserved-memory regions from
  0x80000000 (gunyah_hyp) through 0xffe00000 (llcc_lpi), including xbl_aop,
  smem, qdss, mpss, cdsp/adspslpi, tz, trust_ui/oem VM and hwfence. Written to
  UniXNU-meizu21 `dts/meizu21.dts`. Linux mainline sm8650.dtsi reservations
  remain cached for cross-checking. The UEFI memory map (MemoryMapLib) should
  mirror these reservations plus the 3 MiB FD window.
- COLLECTED: stock `uefiplat.cfg` extracted from the uefi partition FV
  (uefi.img, hash a48d3ee3...): Version 3, MaxMemoryRegions=74,
  SharedIMEMBaseAddr=0x14680000, DloadCookieAddr=0x01FD9000, NumCpus=8,
  EnableMultiThreading=1, SecurityFlag=0xC4, DefaultBDSBootApp=LinuxLoader,
  ShmBridgememSize=0xA00000. Saved at UniXNU-meizu21/firmware/uefiplat.cfg.
- NOT REQUIRED: stock DXE driver binaries. The UniXNU UEFI port uses the
  open-source EDK2 baseline with self-written drivers (cf. the houji port:
  HoujiRamDiskDxe, HoujiRootRAMDxe, NoCapsuleRuntimeDxe in uefi/overlay); the
  stock uefi.img DXE containers (types 0x8A/0x93) are encrypted and would
  only matter for a stock-firmware-based (VENDOR_HW=1) build.
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
