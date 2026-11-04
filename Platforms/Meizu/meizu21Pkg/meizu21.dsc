##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = meizu21
  PLATFORM_GUID                  = 84905094-F6FC-4901-9135-62C1FCBF749A
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/meizu21Pkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = meizu21Pkg/meizu21.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 0

  #
  # 0 = Mu drivers only. The previous stage's display keeps scanning out, so
  #     the boot manager is visible without any vendor hardware driver.
  # 1 = also load the stock vendor hardware drivers (SMEM, clocks, RPMh, UFS,
  #     USB, charger, ...). Their initialization currently blanks the panel.
  #
  MEIZU21_VENDOR_HW                = 0

  #
  # 0 = SM8550-AB
  # 1 = SM8550-AC
  #
  SOC_TYPE                       = 0

!include KailuaPkg/KailuaPkg.dsc.inc

!if ($(USE_CUSTOM_DISPLAY_DRIVER) == 1) && ($(MEIZU21_VENDOR_HW) == 0)
  !error The stock DisplayDxe chain needs MEIZU21_VENDOR_HW = 1
!endif

[PcdsFixedAtBuild]
  #
  # DDR Memory
  #
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x80000000

  #
  # UEFI Stack
  #
  gArmPlatformTokenSpaceGuid.PcdCPUCoresStackBase|0xA760D000
  gArmPlatformTokenSpaceGuid.PcdCPUCorePrimaryStackSize|0x40000

  #
  # SMBIOS
  #
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemManufacturer|"Meizu"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"meizu21"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"meizu21"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"meizu21"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemBoardModel|"meizu21"

  #
  # Simple Frame Buffer
  #
  # Meizu 21 stock panel: 6.55" 2340x1080 AMOLED (Samsung diamond).
  # Placeholder from the official spec sheet; confirm the ABL-supplied
  # framebuffer geometry from the first real boot.
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferWidth|2340
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferHeight|1080
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferColorDepth|32
  # Scale 3 gives 56 lines. The log wraps, so the screen always shows the
  # newest lines; the platform debug level is left unchanged.
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferFontScale|3
  # Pause per log line so a video of the screen shows what loads last.
  gSiliciumPkgTokenSpaceGuid.PcdFrameBufferDelay|30000


  #
  # Platform PEI
  #
  gQcomPkgTokenSpaceGuid.PcdPlatformType|"LA"
!if $(MEIZU21_VENDOR_HW) == 0
  # Intermittent stall right after "MMU: enabled" (int-103 photos): PlatformPeim scanned the stock UEFI's leftover FD window and
  # called into its scheduler protocol. Without the stock vendor drivers nothing reads those HOBs.
  gQcomPkgTokenSpaceGuid.PcdBuildXblHobs|FALSE
!endif

[LibraryClasses]
  #
  # Memory Libraries
  #
  MemoryMapLib|meizu21Pkg/Library/MemoryMapLib/MemoryMapLib.inf

  #
  # QCOM Libraries
  #
  ConfigurationMapLib|meizu21Pkg/Library/ConfigurationMapLib/ConfigurationMapLib.inf

[Components]
  #
  # ACPI Tables
  #
  UniXNUPkg/Application/UniXNU/UniXNU.inf
  UniXNUPkg/Driver/UniXNUDxe/UniXNUDxe.inf
  meizu21Pkg/Drivers/Meizu21DisplayDepexDxe/Meizu21DisplayDepexDxe.inf
  meizu21Pkg/Drivers/Meizu21GopLogDxe/Meizu21GopLogDxe.inf
  meizu21Pkg/Drivers/Meizu21BootMemoryDxe/Meizu21BootMemoryDxe.inf
  UniXNUPkg/Driver/UniXNURamDiskDxe/UniXNURamDiskDxe.inf
  meizu21Pkg/Drivers/Meizu21KeyInputDxe/Meizu21KeyInputDxe.inf
  DarwinBootPkg/Driver/DarwinBoot.inf

[LibraryClasses]
  UniXNULib|UniXNUPkg/Library/UniXNULib/UniXNULib.inf
  FdtLib|MdePkg/Library/BaseFdtLib/BaseFdtLib.inf
