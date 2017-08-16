// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

#ifndef XHUFFMAN_H
#define XHUFFMAN_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xhuffman_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XHuffman_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XHuffman;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XHuffman_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XHuffman_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XHuffman_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XHuffman_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XHuffman_Initialize(XHuffman *InstancePtr, u16 DeviceId);
XHuffman_Config* XHuffman_LookupConfig(u16 DeviceId);
int XHuffman_CfgInitialize(XHuffman *InstancePtr, XHuffman_Config *ConfigPtr);
#else
int XHuffman_Initialize(XHuffman *InstancePtr, const char* InstanceName);
int XHuffman_Release(XHuffman *InstancePtr);
#endif

void XHuffman_Start(XHuffman *InstancePtr);
u32 XHuffman_IsDone(XHuffman *InstancePtr);
u32 XHuffman_IsIdle(XHuffman *InstancePtr);
u32 XHuffman_IsReady(XHuffman *InstancePtr);
void XHuffman_EnableAutoRestart(XHuffman *InstancePtr);
void XHuffman_DisableAutoRestart(XHuffman *InstancePtr);

void XHuffman_Set_c_size(XHuffman *InstancePtr, u32 Data);
u32 XHuffman_Get_c_size(XHuffman *InstancePtr);
u32 XHuffman_Get_d_size(XHuffman *InstancePtr);
u32 XHuffman_Get_d_size_vld(XHuffman *InstancePtr);
u32 XHuffman_Get_code_lengths_BaseAddress(XHuffman *InstancePtr);
u32 XHuffman_Get_code_lengths_HighAddress(XHuffman *InstancePtr);
u32 XHuffman_Get_code_lengths_TotalBytes(XHuffman *InstancePtr);
u32 XHuffman_Get_code_lengths_BitWidth(XHuffman *InstancePtr);
u32 XHuffman_Get_code_lengths_Depth(XHuffman *InstancePtr);
u32 XHuffman_Write_code_lengths_Words(XHuffman *InstancePtr, int offset, int *data, int length);
u32 XHuffman_Read_code_lengths_Words(XHuffman *InstancePtr, int offset, int *data, int length);
u32 XHuffman_Write_code_lengths_Bytes(XHuffman *InstancePtr, int offset, char *data, int length);
u32 XHuffman_Read_code_lengths_Bytes(XHuffman *InstancePtr, int offset, char *data, int length);
u32 XHuffman_Get_compressed_BaseAddress(XHuffman *InstancePtr);
u32 XHuffman_Get_compressed_HighAddress(XHuffman *InstancePtr);
u32 XHuffman_Get_compressed_TotalBytes(XHuffman *InstancePtr);
u32 XHuffman_Get_compressed_BitWidth(XHuffman *InstancePtr);
u32 XHuffman_Get_compressed_Depth(XHuffman *InstancePtr);
u32 XHuffman_Write_compressed_Words(XHuffman *InstancePtr, int offset, int *data, int length);
u32 XHuffman_Read_compressed_Words(XHuffman *InstancePtr, int offset, int *data, int length);
u32 XHuffman_Write_compressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length);
u32 XHuffman_Read_compressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length);
u32 XHuffman_Get_decompressed_BaseAddress(XHuffman *InstancePtr);
u32 XHuffman_Get_decompressed_HighAddress(XHuffman *InstancePtr);
u32 XHuffman_Get_decompressed_TotalBytes(XHuffman *InstancePtr);
u32 XHuffman_Get_decompressed_BitWidth(XHuffman *InstancePtr);
u32 XHuffman_Get_decompressed_Depth(XHuffman *InstancePtr);
u32 XHuffman_Write_decompressed_Words(XHuffman *InstancePtr, int offset, int *data, int length);
u32 XHuffman_Read_decompressed_Words(XHuffman *InstancePtr, int offset, int *data, int length);
u32 XHuffman_Write_decompressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length);
u32 XHuffman_Read_decompressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length);

void XHuffman_InterruptGlobalEnable(XHuffman *InstancePtr);
void XHuffman_InterruptGlobalDisable(XHuffman *InstancePtr);
void XHuffman_InterruptEnable(XHuffman *InstancePtr, u32 Mask);
void XHuffman_InterruptDisable(XHuffman *InstancePtr, u32 Mask);
void XHuffman_InterruptClear(XHuffman *InstancePtr, u32 Mask);
u32 XHuffman_InterruptGetEnabled(XHuffman *InstancePtr);
u32 XHuffman_InterruptGetStatus(XHuffman *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
