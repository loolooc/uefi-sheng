// Board raw files must come from meizu21 firmware, not QRD8550.
  FILE FREEFORM = A1E235DE-E825-4591-9623-C43175811826 {
    SECTION UI = "SecParti.cfg"
    SECTION RAW = Binaries/meizu21/RawFiles/SecParti.cfg
  }

!if $(USE_CUSTOM_DISPLAY_DRIVER) == 1
  # REQUIRED: stock meizu21 panel data (original FFS GUIDs and UI names,
  # 2340x1080 AMOLED), extracted from the official firmware archive.
  FILE FREEFORM = 15A84758-9EE1-4543-9C82-F430A70F0813 {
    SECTION UI = "Panel_N81A_36_02_0a_p0_duldsi_dsc_vid.xml"
    SECTION RAW = Binaries/meizu21/RawFiles/Panel_N81A_36_02_0a_p0_duldsi_dsc_vid.xml
  }
  FILE FREEFORM = 43013DAA-0CE4-4D82-99EE-17F772A38401 {
    SECTION UI = "Panel_N81A_36_02_0a_duldsi_dsc_vid.xml"
    SECTION RAW = Binaries/meizu21/RawFiles/Panel_N81A_36_02_0a_duldsi_dsc_vid.xml
  }
!endif
