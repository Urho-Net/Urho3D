# LLVM CMake target exports.  Do not include directly.
add_library(LLVMLTO STATIC IMPORTED)
set_property(TARGET LLVMLTO PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMLTO.a")
add_library(LLVMObjCARCOpts STATIC IMPORTED)
set_property(TARGET LLVMObjCARCOpts PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMObjCARCOpts.a")
add_library(LLVMLinker STATIC IMPORTED)
set_property(TARGET LLVMLinker PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMLinker.a")
add_library(LLVMBitWriter STATIC IMPORTED)
set_property(TARGET LLVMBitWriter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMBitWriter.a")
add_library(LLVMIRReader STATIC IMPORTED)
set_property(TARGET LLVMIRReader PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMIRReader.a")
add_library(LLVMBPFCodeGen STATIC IMPORTED)
set_property(TARGET LLVMBPFCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMBPFCodeGen.a")
add_library(LLVMBPFDesc STATIC IMPORTED)
set_property(TARGET LLVMBPFDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMBPFDesc.a")
add_library(LLVMBPFInfo STATIC IMPORTED)
set_property(TARGET LLVMBPFInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMBPFInfo.a")
add_library(LLVMBPFAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMBPFAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMBPFAsmPrinter.a")
add_library(LLVMAMDGPUCodeGen STATIC IMPORTED)
set_property(TARGET LLVMAMDGPUCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAMDGPUCodeGen.a")
add_library(LLVMAMDGPUAsmParser STATIC IMPORTED)
set_property(TARGET LLVMAMDGPUAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAMDGPUAsmParser.a")
add_library(LLVMAMDGPUUtils STATIC IMPORTED)
set_property(TARGET LLVMAMDGPUUtils PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAMDGPUUtils.a")
add_library(LLVMAMDGPUDesc STATIC IMPORTED)
set_property(TARGET LLVMAMDGPUDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAMDGPUDesc.a")
add_library(LLVMAMDGPUInfo STATIC IMPORTED)
set_property(TARGET LLVMAMDGPUInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAMDGPUInfo.a")
add_library(LLVMAMDGPUAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMAMDGPUAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAMDGPUAsmPrinter.a")
add_library(LLVMSystemZDisassembler STATIC IMPORTED)
set_property(TARGET LLVMSystemZDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSystemZDisassembler.a")
add_library(LLVMSystemZCodeGen STATIC IMPORTED)
set_property(TARGET LLVMSystemZCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSystemZCodeGen.a")
add_library(LLVMSystemZAsmParser STATIC IMPORTED)
set_property(TARGET LLVMSystemZAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSystemZAsmParser.a")
add_library(LLVMSystemZDesc STATIC IMPORTED)
set_property(TARGET LLVMSystemZDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSystemZDesc.a")
add_library(LLVMSystemZInfo STATIC IMPORTED)
set_property(TARGET LLVMSystemZInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSystemZInfo.a")
add_library(LLVMSystemZAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMSystemZAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSystemZAsmPrinter.a")
add_library(LLVMHexagonDisassembler STATIC IMPORTED)
set_property(TARGET LLVMHexagonDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMHexagonDisassembler.a")
add_library(LLVMHexagonCodeGen STATIC IMPORTED)
set_property(TARGET LLVMHexagonCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMHexagonCodeGen.a")
add_library(LLVMHexagonDesc STATIC IMPORTED)
set_property(TARGET LLVMHexagonDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMHexagonDesc.a")
add_library(LLVMHexagonInfo STATIC IMPORTED)
set_property(TARGET LLVMHexagonInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMHexagonInfo.a")
add_library(LLVMNVPTXCodeGen STATIC IMPORTED)
set_property(TARGET LLVMNVPTXCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMNVPTXCodeGen.a")
add_library(LLVMNVPTXDesc STATIC IMPORTED)
set_property(TARGET LLVMNVPTXDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMNVPTXDesc.a")
add_library(LLVMNVPTXInfo STATIC IMPORTED)
set_property(TARGET LLVMNVPTXInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMNVPTXInfo.a")
add_library(LLVMNVPTXAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMNVPTXAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMNVPTXAsmPrinter.a")
add_library(LLVMCppBackendCodeGen STATIC IMPORTED)
set_property(TARGET LLVMCppBackendCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMCppBackendCodeGen.a")
add_library(LLVMCppBackendInfo STATIC IMPORTED)
set_property(TARGET LLVMCppBackendInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMCppBackendInfo.a")
add_library(LLVMMSP430CodeGen STATIC IMPORTED)
set_property(TARGET LLVMMSP430CodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMSP430CodeGen.a")
add_library(LLVMMSP430Desc STATIC IMPORTED)
set_property(TARGET LLVMMSP430Desc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMSP430Desc.a")
add_library(LLVMMSP430Info STATIC IMPORTED)
set_property(TARGET LLVMMSP430Info PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMSP430Info.a")
add_library(LLVMMSP430AsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMMSP430AsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMSP430AsmPrinter.a")
add_library(LLVMXCoreDisassembler STATIC IMPORTED)
set_property(TARGET LLVMXCoreDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMXCoreDisassembler.a")
add_library(LLVMXCoreCodeGen STATIC IMPORTED)
set_property(TARGET LLVMXCoreCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMXCoreCodeGen.a")
add_library(LLVMXCoreDesc STATIC IMPORTED)
set_property(TARGET LLVMXCoreDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMXCoreDesc.a")
add_library(LLVMXCoreInfo STATIC IMPORTED)
set_property(TARGET LLVMXCoreInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMXCoreInfo.a")
add_library(LLVMXCoreAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMXCoreAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMXCoreAsmPrinter.a")
add_library(LLVMMipsDisassembler STATIC IMPORTED)
set_property(TARGET LLVMMipsDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMipsDisassembler.a")
add_library(LLVMMipsCodeGen STATIC IMPORTED)
set_property(TARGET LLVMMipsCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMipsCodeGen.a")
add_library(LLVMMipsAsmParser STATIC IMPORTED)
set_property(TARGET LLVMMipsAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMipsAsmParser.a")
add_library(LLVMMipsDesc STATIC IMPORTED)
set_property(TARGET LLVMMipsDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMipsDesc.a")
add_library(LLVMMipsInfo STATIC IMPORTED)
set_property(TARGET LLVMMipsInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMipsInfo.a")
add_library(LLVMMipsAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMMipsAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMipsAsmPrinter.a")
add_library(LLVMAArch64Disassembler STATIC IMPORTED)
set_property(TARGET LLVMAArch64Disassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64Disassembler.a")
add_library(LLVMAArch64CodeGen STATIC IMPORTED)
set_property(TARGET LLVMAArch64CodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64CodeGen.a")
add_library(LLVMAArch64AsmParser STATIC IMPORTED)
set_property(TARGET LLVMAArch64AsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64AsmParser.a")
add_library(LLVMAArch64Desc STATIC IMPORTED)
set_property(TARGET LLVMAArch64Desc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64Desc.a")
add_library(LLVMAArch64Info STATIC IMPORTED)
set_property(TARGET LLVMAArch64Info PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64Info.a")
add_library(LLVMAArch64AsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMAArch64AsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64AsmPrinter.a")
add_library(LLVMAArch64Utils STATIC IMPORTED)
set_property(TARGET LLVMAArch64Utils PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAArch64Utils.a")
add_library(LLVMARMDisassembler STATIC IMPORTED)
set_property(TARGET LLVMARMDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMARMDisassembler.a")
add_library(LLVMARMCodeGen STATIC IMPORTED)
set_property(TARGET LLVMARMCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMARMCodeGen.a")
add_library(LLVMARMAsmParser STATIC IMPORTED)
set_property(TARGET LLVMARMAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMARMAsmParser.a")
add_library(LLVMARMDesc STATIC IMPORTED)
set_property(TARGET LLVMARMDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMARMDesc.a")
add_library(LLVMARMInfo STATIC IMPORTED)
set_property(TARGET LLVMARMInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMARMInfo.a")
add_library(LLVMARMAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMARMAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMARMAsmPrinter.a")
add_library(LLVMPowerPCDisassembler STATIC IMPORTED)
set_property(TARGET LLVMPowerPCDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPowerPCDisassembler.a")
add_library(LLVMPowerPCCodeGen STATIC IMPORTED)
set_property(TARGET LLVMPowerPCCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPowerPCCodeGen.a")
add_library(LLVMPowerPCAsmParser STATIC IMPORTED)
set_property(TARGET LLVMPowerPCAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPowerPCAsmParser.a")
add_library(LLVMPowerPCDesc STATIC IMPORTED)
set_property(TARGET LLVMPowerPCDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPowerPCDesc.a")
add_library(LLVMPowerPCInfo STATIC IMPORTED)
set_property(TARGET LLVMPowerPCInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPowerPCInfo.a")
add_library(LLVMPowerPCAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMPowerPCAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPowerPCAsmPrinter.a")
add_library(LLVMSparcDisassembler STATIC IMPORTED)
set_property(TARGET LLVMSparcDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSparcDisassembler.a")
add_library(LLVMSparcCodeGen STATIC IMPORTED)
set_property(TARGET LLVMSparcCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSparcCodeGen.a")
add_library(LLVMSparcAsmParser STATIC IMPORTED)
set_property(TARGET LLVMSparcAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSparcAsmParser.a")
add_library(LLVMSparcDesc STATIC IMPORTED)
set_property(TARGET LLVMSparcDesc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSparcDesc.a")
add_library(LLVMSparcInfo STATIC IMPORTED)
set_property(TARGET LLVMSparcInfo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSparcInfo.a")
add_library(LLVMSparcAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMSparcAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSparcAsmPrinter.a")
add_library(LLVMMIRParser STATIC IMPORTED)
set_property(TARGET LLVMMIRParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMIRParser.a")
add_library(LLVMAsmParser STATIC IMPORTED)
set_property(TARGET LLVMAsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAsmParser.a")
add_library(LLVMLibDriver STATIC IMPORTED)
set_property(TARGET LLVMLibDriver PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMLibDriver.a")
add_library(LLVMOption STATIC IMPORTED)
set_property(TARGET LLVMOption PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMOption.a")
add_library(LLVMDebugInfoPDB STATIC IMPORTED)
set_property(TARGET LLVMDebugInfoPDB PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMDebugInfoPDB.a")
add_library(LLVMTableGen STATIC IMPORTED)
set_property(TARGET LLVMTableGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMTableGen.a")
add_library(LLVMOrcJIT STATIC IMPORTED)
set_property(TARGET LLVMOrcJIT PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMOrcJIT.a")
add_library(LLVMLineEditor STATIC IMPORTED)
set_property(TARGET LLVMLineEditor PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMLineEditor.a")
add_library(LLVMX86Disassembler STATIC IMPORTED)
set_property(TARGET LLVMX86Disassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86Disassembler.a")
add_library(LLVMX86AsmParser STATIC IMPORTED)
set_property(TARGET LLVMX86AsmParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86AsmParser.a")
add_library(LLVMX86CodeGen STATIC IMPORTED)
set_property(TARGET LLVMX86CodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86CodeGen.a")
add_library(LLVMSelectionDAG STATIC IMPORTED)
set_property(TARGET LLVMSelectionDAG PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSelectionDAG.a")
add_library(LLVMAsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMAsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAsmPrinter.a")
add_library(LLVMX86Desc STATIC IMPORTED)
set_property(TARGET LLVMX86Desc PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86Desc.a")
add_library(LLVMMCDisassembler STATIC IMPORTED)
set_property(TARGET LLVMMCDisassembler PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMCDisassembler.a")
add_library(LLVMX86Info STATIC IMPORTED)
set_property(TARGET LLVMX86Info PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86Info.a")
add_library(LLVMX86AsmPrinter STATIC IMPORTED)
set_property(TARGET LLVMX86AsmPrinter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86AsmPrinter.a")
add_library(LLVMX86Utils STATIC IMPORTED)
set_property(TARGET LLVMX86Utils PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMX86Utils.a")
add_library(LLVMMCJIT STATIC IMPORTED)
set_property(TARGET LLVMMCJIT PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMCJIT.a")
add_library(LLVMDebugInfoDWARF STATIC IMPORTED)
set_property(TARGET LLVMDebugInfoDWARF PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMDebugInfoDWARF.a")
add_library(LLVMPasses STATIC IMPORTED)
set_property(TARGET LLVMPasses PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMPasses.a")
add_library(LLVMipo STATIC IMPORTED)
set_property(TARGET LLVMipo PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMipo.a")
add_library(LLVMVectorize STATIC IMPORTED)
set_property(TARGET LLVMVectorize PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMVectorize.a")
add_library(LLVMInterpreter STATIC IMPORTED)
set_property(TARGET LLVMInterpreter PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMInterpreter.a")
add_library(LLVMExecutionEngine STATIC IMPORTED)
set_property(TARGET LLVMExecutionEngine PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMExecutionEngine.a")
add_library(LLVMRuntimeDyld STATIC IMPORTED)
set_property(TARGET LLVMRuntimeDyld PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMRuntimeDyld.a")
add_library(LLVMCodeGen STATIC IMPORTED)
set_property(TARGET LLVMCodeGen PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMCodeGen.a")
add_library(LLVMTarget STATIC IMPORTED)
set_property(TARGET LLVMTarget PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMTarget.a")
add_library(LLVMScalarOpts STATIC IMPORTED)
set_property(TARGET LLVMScalarOpts PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMScalarOpts.a")
add_library(LLVMProfileData STATIC IMPORTED)
set_property(TARGET LLVMProfileData PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMProfileData.a")
add_library(LLVMObject STATIC IMPORTED)
set_property(TARGET LLVMObject PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMObject.a")
add_library(LLVMMCParser STATIC IMPORTED)
set_property(TARGET LLVMMCParser PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMCParser.a")
add_library(LLVMBitReader STATIC IMPORTED)
set_property(TARGET LLVMBitReader PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMBitReader.a")
add_library(LLVMInstCombine STATIC IMPORTED)
set_property(TARGET LLVMInstCombine PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMInstCombine.a")
add_library(LLVMInstrumentation STATIC IMPORTED)
set_property(TARGET LLVMInstrumentation PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMInstrumentation.a")
add_library(LLVMTransformUtils STATIC IMPORTED)
set_property(TARGET LLVMTransformUtils PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMTransformUtils.a")
add_library(LLVMipa STATIC IMPORTED)
set_property(TARGET LLVMipa PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMipa.a")
add_library(LLVMMC STATIC IMPORTED)
set_property(TARGET LLVMMC PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMMC.a")
add_library(LLVMAnalysis STATIC IMPORTED)
set_property(TARGET LLVMAnalysis PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMAnalysis.a")
add_library(LLVMCore STATIC IMPORTED)
set_property(TARGET LLVMCore PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMCore.a")
add_library(LLVMSupport STATIC IMPORTED)
set_property(TARGET LLVMSupport PROPERTY IMPORTED_LOCATION "${_LLVM_LIBRARY_DIR}/libLLVMSupport.a")
# Explicit library dependency information.
#
# The following property assignments tell CMake about link
# dependencies of libraries imported from LLVM.
set_property(TARGET LLVMSupport PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES )
set_property(TARGET LLVMAArch64Utils PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMMC PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMAArch64AsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAArch64Utils LLVMMC LLVMSupport)
set_property(TARGET LLVMAArch64Info PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMAArch64Desc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAArch64AsmPrinter LLVMAArch64Info LLVMMC LLVMSupport)
set_property(TARGET LLVMMCParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMAArch64AsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAArch64Desc LLVMAArch64Info LLVMAArch64Utils LLVMMC LLVMMCParser LLVMSupport)
set_property(TARGET LLVMCore PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMAnalysis PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMSupport)
set_property(TARGET LLVMipa PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMSupport)
set_property(TARGET LLVMTransformUtils PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMSupport LLVMipa)
set_property(TARGET LLVMInstrumentation PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMMC LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMInstCombine PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMBitReader PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMSupport)
set_property(TARGET LLVMObject PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMBitReader LLVMCore LLVMMC LLVMMCParser LLVMSupport)
set_property(TARGET LLVMProfileData PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMObject LLVMSupport)
set_property(TARGET LLVMScalarOpts PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMInstCombine LLVMProfileData LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMTarget PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMMC LLVMSupport)
set_property(TARGET LLVMCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMInstrumentation LLVMMC LLVMScalarOpts LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(TARGET LLVMAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCodeGen LLVMCore LLVMMC LLVMMCParser LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(TARGET LLVMSelectionDAG PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCodeGen LLVMCore LLVMMC LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(TARGET LLVMAArch64CodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAArch64AsmPrinter LLVMAArch64Desc LLVMAArch64Info LLVMAArch64Utils LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMTarget)
set_property(TARGET LLVMMCDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMAArch64Disassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAArch64Desc LLVMAArch64Info LLVMAArch64Utils LLVMMC LLVMMCDisassembler LLVMSupport)
set_property(TARGET LLVMAMDGPUAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMAMDGPUInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMAMDGPUDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAMDGPUAsmPrinter LLVMAMDGPUInfo LLVMMC LLVMSupport)
set_property(TARGET LLVMAMDGPUUtils PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMAMDGPUAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAMDGPUDesc LLVMAMDGPUInfo LLVMAMDGPUUtils LLVMMC LLVMMCParser LLVMSupport)
set_property(TARGET LLVMVectorize PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMipo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMInstCombine LLVMScalarOpts LLVMSupport LLVMTransformUtils LLVMVectorize LLVMipa)
set_property(TARGET LLVMAMDGPUCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAMDGPUAsmParser LLVMAMDGPUAsmPrinter LLVMAMDGPUDesc LLVMAMDGPUInfo LLVMAMDGPUUtils LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMTarget LLVMTransformUtils LLVMipo)
set_property(TARGET LLVMARMAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMARMInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMARMDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMARMAsmPrinter LLVMARMInfo LLVMMC LLVMMCDisassembler LLVMSupport)
set_property(TARGET LLVMARMAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMARMDesc LLVMARMInfo LLVMMC LLVMMCParser LLVMSupport)
set_property(TARGET LLVMARMCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMARMAsmPrinter LLVMARMDesc LLVMARMInfo LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMTarget)
set_property(TARGET LLVMARMDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMARMDesc LLVMARMInfo LLVMMCDisassembler LLVMSupport)
set_property(TARGET LLVMAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMSupport)
set_property(TARGET LLVMBPFAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMBPFInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMBPFDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMBPFAsmPrinter LLVMBPFInfo LLVMMC LLVMSupport)
set_property(TARGET LLVMBPFCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAsmPrinter LLVMBPFAsmPrinter LLVMBPFDesc LLVMBPFInfo LLVMCodeGen LLVMCore LLVMMC LLVMSelectionDAG LLVMSupport LLVMTarget)
set_property(TARGET LLVMBitWriter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMSupport)
set_property(TARGET LLVMCppBackendInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMCppBackendCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMCppBackendInfo LLVMSupport LLVMTarget)
set_property(TARGET LLVMDebugInfoDWARF PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMObject LLVMSupport)
set_property(TARGET LLVMDebugInfoPDB PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMObject LLVMSupport)
set_property(TARGET LLVMRuntimeDyld PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMObject LLVMSupport)
set_property(TARGET LLVMExecutionEngine PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMMC LLVMObject LLVMRuntimeDyld LLVMSupport LLVMTarget)
set_property(TARGET LLVMMCJIT PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMExecutionEngine LLVMObject LLVMRuntimeDyld LLVMSupport LLVMTarget)
set_property(TARGET LLVMHexagonInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMHexagonDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMHexagonInfo LLVMMC LLVMSupport)
set_property(TARGET LLVMHexagonCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMHexagonDesc LLVMHexagonInfo LLVMMC LLVMSelectionDAG LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(TARGET LLVMHexagonDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMHexagonDesc LLVMHexagonInfo LLVMMCDisassembler LLVMSupport)
set_property(TARGET LLVMIRReader PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAsmParser LLVMBitReader LLVMCore LLVMSupport)
set_property(TARGET LLVMInterpreter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCodeGen LLVMCore LLVMExecutionEngine LLVMSupport)
set_property(TARGET LLVMLinker PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMObjCARCOpts PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMLTO PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMBitReader LLVMBitWriter LLVMCodeGen LLVMCore LLVMInstCombine LLVMLinker LLVMMC LLVMObjCARCOpts LLVMObject LLVMScalarOpts LLVMSupport LLVMTarget LLVMipa LLVMipo)
set_property(TARGET LLVMOption PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMLibDriver PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMObject LLVMOption LLVMSupport)
set_property(TARGET LLVMLineEditor PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMMIRParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAsmParser LLVMCodeGen LLVMCore LLVMSupport LLVMTarget)
set_property(TARGET LLVMMSP430AsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMMSP430Info PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMMSP430Desc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMSP430AsmPrinter LLVMMSP430Info LLVMSupport)
set_property(TARGET LLVMMSP430CodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMMSP430AsmPrinter LLVMMSP430Desc LLVMMSP430Info LLVMSelectionDAG LLVMSupport LLVMTarget)
set_property(TARGET LLVMMipsAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMMipsInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMMipsDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMipsAsmPrinter LLVMMipsInfo LLVMSupport)
set_property(TARGET LLVMMipsAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCParser LLVMMipsDesc LLVMMipsInfo LLVMSupport)
set_property(TARGET LLVMMipsCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMMipsAsmPrinter LLVMMipsDesc LLVMMipsInfo LLVMSelectionDAG LLVMSupport LLVMTarget)
set_property(TARGET LLVMMipsDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMCDisassembler LLVMMipsInfo LLVMSupport)
set_property(TARGET LLVMNVPTXAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMNVPTXInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMNVPTXDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMNVPTXAsmPrinter LLVMNVPTXInfo LLVMSupport)
set_property(TARGET LLVMNVPTXCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMNVPTXAsmPrinter LLVMNVPTXDesc LLVMNVPTXInfo LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(TARGET LLVMX86Utils PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMSupport)
set_property(TARGET LLVMX86AsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport LLVMX86Utils)
set_property(TARGET LLVMX86Info PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMX86Desc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCDisassembler LLVMObject LLVMSupport LLVMX86AsmPrinter LLVMX86Info)
set_property(TARGET LLVMX86CodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMSelectionDAG LLVMSupport LLVMTarget LLVMX86AsmPrinter LLVMX86Desc LLVMX86Info LLVMX86Utils)
set_property(TARGET LLVMOrcJIT PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMCore LLVMExecutionEngine LLVMObject LLVMRuntimeDyld LLVMSupport LLVMTransformUtils)
set_property(TARGET LLVMPasses PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMCore LLVMInstCombine LLVMScalarOpts LLVMSupport LLVMTransformUtils LLVMVectorize LLVMipa LLVMipo)
set_property(TARGET LLVMPowerPCAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMPowerPCInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMPowerPCDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMPowerPCAsmPrinter LLVMPowerPCInfo LLVMSupport)
set_property(TARGET LLVMPowerPCAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCParser LLVMPowerPCDesc LLVMPowerPCInfo LLVMSupport)
set_property(TARGET LLVMPowerPCCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMPowerPCAsmPrinter LLVMPowerPCDesc LLVMPowerPCInfo LLVMScalarOpts LLVMSelectionDAG LLVMSupport LLVMTarget LLVMTransformUtils)
set_property(TARGET LLVMPowerPCDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMCDisassembler LLVMPowerPCInfo LLVMSupport)
set_property(TARGET LLVMSparcAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMSparcInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMSparcDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSparcAsmPrinter LLVMSparcInfo LLVMSupport)
set_property(TARGET LLVMSparcAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCParser LLVMSparcDesc LLVMSparcInfo LLVMSupport)
set_property(TARGET LLVMSparcCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMSelectionDAG LLVMSparcAsmPrinter LLVMSparcDesc LLVMSparcInfo LLVMSupport LLVMTarget)
set_property(TARGET LLVMSparcDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMCDisassembler LLVMSparcInfo LLVMSupport)
set_property(TARGET LLVMSystemZAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMSystemZInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMSystemZDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport LLVMSystemZAsmPrinter LLVMSystemZInfo)
set_property(TARGET LLVMSystemZAsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCParser LLVMSupport LLVMSystemZDesc LLVMSystemZInfo)
set_property(TARGET LLVMSystemZCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMSelectionDAG LLVMSupport LLVMSystemZAsmPrinter LLVMSystemZDesc LLVMSystemZInfo LLVMTarget)
set_property(TARGET LLVMSystemZDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCDisassembler LLVMSupport LLVMSystemZDesc LLVMSystemZInfo)
set_property(TARGET LLVMTableGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMX86AsmParser PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMMCParser LLVMSupport LLVMX86CodeGen LLVMX86Desc LLVMX86Info)
set_property(TARGET LLVMX86Disassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMCDisassembler LLVMSupport LLVMX86Info)
set_property(TARGET LLVMXCoreAsmPrinter PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport)
set_property(TARGET LLVMXCoreInfo PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMSupport)
set_property(TARGET LLVMXCoreDesc PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMC LLVMSupport LLVMXCoreAsmPrinter LLVMXCoreInfo)
set_property(TARGET LLVMXCoreCodeGen PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMAnalysis LLVMAsmPrinter LLVMCodeGen LLVMCore LLVMMC LLVMSelectionDAG LLVMSupport LLVMTarget LLVMTransformUtils LLVMXCoreAsmPrinter LLVMXCoreDesc LLVMXCoreInfo)
set_property(TARGET LLVMXCoreDisassembler PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES LLVMMCDisassembler LLVMSupport LLVMXCoreInfo)
set_property(TARGET LLVMSupport APPEND PROPERTY IMPORTED_LINK_INTERFACE_LIBRARIES z pthread edit curses m )
