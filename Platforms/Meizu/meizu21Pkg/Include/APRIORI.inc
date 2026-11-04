APRIORI DXE {
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/EnvDxe/EnvDxe.inf
!endif

  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/SmemDxe/SmemDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/DALSYSDxe/DALSYSDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/HWIODxe/HWIODxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ChipInfoDxe/ChipInfoDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/PlatformInfoDxe/PlatformInfoDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ProjectInfoDxe/ProjectInfoDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/HALIOMMUDxe/HALIOMMUDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ULogDxe/ULogDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/IPCCDxe/IPCCDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/GLinkDxe/GLinkDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/CmdDbDxe/CmdDbDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/PwrUtilsDxe/PwrUtilsDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/NpaDxe/NpaDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/RpmhDxe/RpmhDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/VcsDxe/VcsDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ClockDxe/ClockDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ICBDxe/ICBDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ShmBridgeDxe/ShmBridgeDxeLA.inf
  INF Binaries/meizu21/QcomPkg/Drivers/TzDxe/ScmDxeCompat.inf
  INF Binaries/meizu21/QcomPkg/Drivers/TLMMDxe/TLMMDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/I2CDxe/I2CDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/SPMIDxe/SPMIDxe.inf
!endif

  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/PmicDxe/PmicDxeLa.inf
!endif

  INF MdeModulePkg/Universal/Disk/DiskIoDxe/DiskIoDxe.inf
  INF MdeModulePkg/Universal/Disk/PartitionDxe/PartitionDxe.inf
  INF MdeModulePkg/Universal/Disk/UnicodeCollation/EnglishDxe/EnglishDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/SdccDxe/SdccDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/UFSDxe/UFSDxe.inf
!endif

  INF FatPkg/EnhancedFatDxe/Fat.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/TzDxe/TzDxeLA.inf
!endif

  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/DDRInfoDxe/DDRInfoDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/FeatureEnablerDxe/FeatureEnablerDxe.inf
!endif
!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  INF meizu21Pkg/Drivers/Meizu21GopLogDxe/Meizu21GopLogDxe.inf
  INF meizu21Pkg/Drivers/Meizu21DisplayDepexDxe/Meizu21DisplayDepexDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/DisplayDxe/DisplayDxe.inf
!else
  INF SiliciumPkg/Drivers/SimpleFbDxe/SimpleFbDxe.inf
!endif
!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/PILProxyDxe/PILProxyDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/PILDxe/PILDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/SPSSDxe/SPSSDxe.inf
!endif

  INF MdeModulePkg/Universal/WatchdogTimerDxe/WatchdogTimer.inf
  INF MdeModulePkg/Universal/SecurityStubDxe/SecurityStubDxe.inf
  INF EmbeddedPkg/EmbeddedMonotonicCounter/EmbeddedMonotonicCounter.inf
  INF EmbeddedPkg/RealTimeClockRuntimeDxe/RealTimeClockRuntimeDxe.inf
  INF MdeModulePkg/Universal/PrintDxe/PrintDxe.inf
  INF Binaries/meizu21/MdeModulePkg/Universal/DevicePathDxe/DevicePathDxe.inf
  INF MdeModulePkg/Universal/CapsuleRuntimeDxe/CapsuleRuntimeDxe.inf
  INF MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabaseDxe.inf
  INF MdeModulePkg/Universal/BdsDxe/BdsDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/SPIDxe/SPIDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/PmicGlinkDxe/PmicGlinkDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/UsbPwrCtrlDxe/UsbPwrCtrlDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/QcomChargerDxe/QcomChargerDxeLA.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ChargerExDxe/ChargerExDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/UsbfnDwc3Dxe/UsbfnDwc3Dxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/XhciPciEmulationDxe/XhciPciEmulationDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/XhciDxe/XhciDxe.inf
!endif

  INF MdeModulePkg/Bus/Usb/UsbBusDxe/UsbBusDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbKbDxe/UsbKbDxe.inf
  INF MdeModulePkg/Bus/Usb/UsbMassStorageDxe/UsbMassStorageDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/UsbMsdDxe/UsbMsdDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/UsbDeviceDxe/UsbDeviceDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/UsbConfigDxe/UsbConfigDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/ButtonsDxe/ButtonsDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/TsensDxe/TsensDxe.inf

  # Headless until stock meizu21 framebuffer data is available.

  INF Binaries/meizu21/QcomPkg/Drivers/LimitsDxe/LimitsDxe.inf
  # Headless until stock meizu21 framebuffer data is available.
  INF Binaries/meizu21/QcomPkg/Drivers/GpiDxe/GpiDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/UCDxe/UCDxe.inf
  INF Binaries/meizu21/QcomPkg/Drivers/RNGDxe/RngDxe.inf
!endif

  INF EmbeddedPkg/SimpleTextInOutSerial/SimpleTextInOutSerial.inf
  INF MdeModulePkg/Universal/Console/ConPlatformDxe/ConPlatformDxe.inf
  INF MdeModulePkg/Universal/Console/ConSplitterDxe/ConSplitterDxe.inf
  INF MdeModulePkg/Universal/Console/GraphicsConsoleDxe/GraphicsConsoleDxe.inf

!if $(MEIZU21_VENDOR_HW) == 1
  INF Binaries/meizu21/QcomPkg/Drivers/RscDxe/RscDxe.inf
!endif
}
