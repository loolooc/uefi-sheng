// Stage-1 firmware modules for Meizu 21. Mu EDK2 baseline + Meizu 21 custom drivers.
// No stock vendor binaries: the previous stage's display keeps scanning out, so
// the boot manager is visible without any vendor hardware driver (MEIZU21_VENDOR_HW=0).
APRIORI DXE {
  INF MdeModulePkg/Core/Dxe/DxeMain.inf
  INF MdeModulePkg/Universal/PCD/Dxe/Pcd.inf
  INF MdeModulePkg/Universal/ReportStatusCodeRouter/RuntimeDxe/ReportStatusCodeRouterRuntimeDxe.inf
  INF MdeModulePkg/Universal/StatusCodeHandler/RuntimeDxe/StatusCodeHandlerRuntimeDxe.inf
  INF MdeModulePkg/Core/RuntimeDxe/RuntimeDxe.inf
  INF ArmPkg/Drivers/CpuDxe/CpuDxe.inf
  INF ArmPkg/Drivers/ArmGicDxe/ArmGicDxe.inf
  INF EmbeddedPkg/MetronomeDxe/MetronomeDxe.inf
  INF ArmPkg/Drivers/TimerDxe/TimerDxe.inf
  INF MdeModulePkg/Universal/ResetSystemRuntimeDxe/ResetSystemRuntimeDxe.inf
  INF MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf
  INF meizu21Pkg/Drivers/Meizu21BootMemoryDxe/Meizu21BootMemoryDxe.inf
  INF meizu21Pkg/Drivers/Meizu21KeyInputDxe/Meizu21KeyInputDxe.inf
}
