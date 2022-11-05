Release
$env:path += ";c:/local/zlib/"
$env:path += ";c:/local/llvm/"
debug
$env:path += ";c:/local/zlib/"
$env:path += ";c:/local/debug/llvm/"

#llvm_map_components_to_libnames(llvm_libs support core)
#llvm_map_components_to_libnames(llvm_libs Support Core native Object X86Desc MC )
#llvm_map_components_to_libnames(llvm_libs Support Core native )
#llvm_map_components_to_libnames(llvm_libs Core native )
llvm_map_components_to_libnames(llvm_libs native )
