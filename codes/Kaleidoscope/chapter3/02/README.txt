clang.exe ../testprj.ll -o ./testprj.exe
clang++ -g -O3 main.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core` -o testprj.exe

set(LLVM_ALL_PROJECTS "bolt;clang;clang-tools-extra;
compiler-rt;cross-project-tests;
libc;libclc;libcxx;libcxxabi;libunwind;lld;lldb;mlir;openmp;polly;pstl")

cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi;clang-tools-extra;libunwind;compiler-rt" 
-DLLVM_ENABLE_ASSERTIONS=ON -DCMAKE_INSTALL_PREFIX=D:\LLVM  ..\llvm\


cmake -S llvm -B build -G "Visual Studio 17 2022" -DLLVM_ENABLE_PROJECTS="clang-tools-extra" `
     -DLLVM_BUILD_EXAMPLES=ON `
     -DLLVM_TARGETS_TO_BUILD="X86" `
     -DCMAKE_BUILD_TYPE=Release `
     -DLLVM_ENABLE_ASSERTIONS=ON
	 
cd d:\work\llvm_work\llvm-project\	 
	 
	 cmake -S llvm -B build -G "Visual Studio 17 2022" -DLLVM_ENABLE_PROJECTS="clang-tools-extra" `
     -DLLVM_BUILD_EXAMPLES=ON `
     -DLLVM_TARGETS_TO_BUILD="X86" `
     -DCMAKE_BUILD_TYPE=Debug `
     -DLLVM_ENABLE_ASSERTIONS=ON
	 
cmake --build build --config Debug
	 
cmake --install build --prefix="c:/local/debug/llvm"
	 
cmake --install build --prefix="D:/tmp/test"
cmake --install build --prefix="c:/local/llvm"

cmake .. -D CMAKE_PREFIX_PATH:PATH=c:/local/llvm/
cmake .. -D CMAKE_PREFIX_PATH:PATH=c:/local/llvm:c:/local/zlib/

get_directory_property( my_system_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} BUILDSYSTEM_TARGETS )
get_directory_property( my_import_targets DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} IMPORTED_TARGETS )

message( STATUS "my_system_targets=${my_system_targets}" )
message( STATUS "my_import_targets=${my_import_targets}" )

-- my_import_targets=LLVMDemangle;LLVMSupport;LLVMTableGen;LLVMTableGenGlobalISel;
llvm-tblgen;LLVMCore;LLVMFuzzerCLI;LLVMFuzzMutate;LLVMFileCheck;LLVMInterfaceStub;
LLVMIRReader;LLVMCodeGen;LLVMSelectionDAG;LLVMAsmPrinter;LLVMMIRParser;LLVMGlobalISel;
LLVMBinaryFormat;LLVMBitReader;LLVMBitWriter;LLVMBitstreamReader;LLVMDWARFLinker;LLVMExtensions;
LLVMFrontendOpenACC;LLVMFrontendOpenMP;LLVMTransformUtils;LLVMInstrumentation;LLVMAggressiveInstCombine;
LLVMInstCombine;LLVMScalarOpts;LLVMipo;LLVMVectorize;LLVMObjCARCOpts;LLVMCoroutines;
LLVMCFGuard;LLVMLinker;LLVMAnalysis;LLVMLTO;LLVMMC;LLVMMCParser;
LLVMMCDisassembler;LLVMMCA;LLVMObjCopy;LLVMObject;
LLVMObjectYAML;LLVMOption;LLVMRemarks;LLVMDebuginfod;
LLVMDebugInfoDWARF;LLVMDebugInfoGSYM;LLVMDebugInfoMSF;
LLVMDebugInfoCodeView;LLVMDebugInfoPDB;LLVMSymbolize;
LLVMDWP;LLVMExecutionEngine;LLVMInterpreter;LLVMJITLink;
LLVMMCJIT;LLVMOrcJIT;LLVMOrcShared;LLVMOrcTargetProcess;LLVMRuntimeDyld;
LLVMTarget;LLVMX86CodeGen;LLVMX86AsmParser;LLVMX86Disassembler;LLVMX86TargetMCA;
LLVMX86Desc;LLVMX86Info;LLVMAsmParser;LLVMLineEditor;LLVMProfileData;LLVMCoverage;
LLVMPasses;LLVMTextAPI;LLVMDlltoolDriver;LLVMLibDriver;LLVMXRay;LLVMWindowsDriver;
LLVMWindowsManifest;LTO;llvm-ar;llvm-config;llvm-lto;llvm-profdata;bugpoint;dsymutil;
llc;lli;llvm-as;llvm-bcanalyzer;llvm-c-test;llvm-cat;llvm-cfi-verify;LLVMCFIVerify;
llvm-cov;llvm-cvtres;llvm-cxxdump;llvm-cxxfilt;llvm-cxxmap;llvm-debuginfod;
llvm-debuginfod-find;llvm-diff;LLVMDiff;llvm-dis;llvm-dwarfdump;
llvm-dwarfutil;llvm-dwp;llvm-exegesis;LLVMExegesisX86;LLVMExegesis;
llvm-extract;llvm-gsymutil;llvm-ifs;llvm-jitlink;llvm-libtool-darwin;
llvm-link;llvm-lipo;llvm-lto2;llvm-mc;llvm-mca;llvm-ml;llvm-modextract;
llvm-mt;llvm-nm;llvm-objcopy;llvm-objdump;llvm-opt-report;llvm-pdbutil;
llvm-profgen;llvm-rc;llvm-readobj;llvm-reduce;llvm-remark-size-diff;
llvm-remarkutil;llvm-rtdyld;LLVM-C;llvm-sim;llvm-size;llvm-split;
llvm-stress;llvm-strings;llvm-symbolizer;llvm-tapi-diff;
llvm-tli-checker;llvm-undname;llvm-xray;opt;Remarks;sancov;
sanstats;verify-uselistorder;ExampleIRTransforms

https://zlib.net/
$env:path+=";c:\your_path"
Release
$env:path += ";c:/local/zlib/"
$env:path += ";c:/local/llvm/"
debug
$env:path += ";c:/local/zlib/"
$env:path += ";c:/local/debug/llvm/"
