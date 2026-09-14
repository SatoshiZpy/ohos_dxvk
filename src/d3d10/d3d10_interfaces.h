#pragma once

#include "d3d10_include.h"

#ifdef _MSC_VER
struct __declspec(uuid("0803425a-57f5-4dd6-9465-a87570834a08")) ID3D10StateBlock;
#else
// 本项目的工具链分两类, 该声明只在旧头下需要:
//   x86 (Ubuntu mingw-w64 gcc): d3d10effect.h 没有该 UUID 声明,
//     必须由 dxvk 自己 __CRT_UUID_DECL, 否则链接期 undefined
//     __mingw_uuidof<ID3D10StateBlock>
//   arm64ec (llvm-mingw, 新 mingw-w64 头): d3d10effect.h 已声明同名
//     同值特化, 重复声明触发重定义错误, 必须跳过
#if !defined(__aarch64__) && !defined(__arm64ec__)
__CRT_UUID_DECL(ID3D10StateBlock, 0x0803425a,0x57f5,0x4dd6,0x94,0x65,0xa8,0x75,0x70,0x83,0x4a,0x08);
#endif
#endif
