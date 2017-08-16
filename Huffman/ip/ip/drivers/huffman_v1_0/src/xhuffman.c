// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xhuffman.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XHuffman_CfgInitialize(XHuffman *InstancePtr, XHuffman_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XHuffman_Start(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL) & 0x80;
    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XHuffman_IsDone(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XHuffman_IsIdle(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XHuffman_IsReady(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XHuffman_EnableAutoRestart(XHuffman *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XHuffman_DisableAutoRestart(XHuffman *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_AP_CTRL, 0);
}

void XHuffman_Set_c_size(XHuffman *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_C_SIZE_DATA, Data);
}

u32 XHuffman_Get_c_size(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_C_SIZE_DATA);
    return Data;
}

u32 XHuffman_Get_d_size(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_D_SIZE_DATA);
    return Data;
}

u32 XHuffman_Get_d_size_vld(XHuffman *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_D_SIZE_CTRL);
    return Data & 0x1;
}

u32 XHuffman_Get_code_lengths_BaseAddress(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE);
}

u32 XHuffman_Get_code_lengths_HighAddress(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_HIGH);
}

u32 XHuffman_Get_code_lengths_TotalBytes(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_HIGH - XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + 1);
}

u32 XHuffman_Get_code_lengths_BitWidth(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHUFFMAN_AXILITES_WIDTH_CODE_LENGTHS;
}

u32 XHuffman_Get_code_lengths_Depth(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHUFFMAN_AXILITES_DEPTH_CODE_LENGTHS;
}

u32 XHuffman_Write_code_lengths_Words(XHuffman *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_HIGH - XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XHuffman_Read_code_lengths_Words(XHuffman *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_HIGH - XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + (offset + i)*4);
    }
    return length;
}

u32 XHuffman_Write_code_lengths_Bytes(XHuffman *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_HIGH - XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XHuffman_Read_code_lengths_Bytes(XHuffman *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_HIGH - XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_CODE_LENGTHS_BASE + offset + i);
    }
    return length;
}

u32 XHuffman_Get_compressed_BaseAddress(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE);
}

u32 XHuffman_Get_compressed_HighAddress(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_COMPRESSED_HIGH);
}

u32 XHuffman_Get_compressed_TotalBytes(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XHUFFMAN_AXILITES_ADDR_COMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + 1);
}

u32 XHuffman_Get_compressed_BitWidth(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHUFFMAN_AXILITES_WIDTH_COMPRESSED;
}

u32 XHuffman_Get_compressed_Depth(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHUFFMAN_AXILITES_DEPTH_COMPRESSED;
}

u32 XHuffman_Write_compressed_Words(XHuffman *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHUFFMAN_AXILITES_ADDR_COMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XHuffman_Read_compressed_Words(XHuffman *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHUFFMAN_AXILITES_ADDR_COMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + (offset + i)*4);
    }
    return length;
}

u32 XHuffman_Write_compressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHUFFMAN_AXILITES_ADDR_COMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XHuffman_Read_compressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHUFFMAN_AXILITES_ADDR_COMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_COMPRESSED_BASE + offset + i);
    }
    return length;
}

u32 XHuffman_Get_decompressed_BaseAddress(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE);
}

u32 XHuffman_Get_decompressed_HighAddress(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_HIGH);
}

u32 XHuffman_Get_decompressed_TotalBytes(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + 1);
}

u32 XHuffman_Get_decompressed_BitWidth(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHUFFMAN_AXILITES_WIDTH_DECOMPRESSED;
}

u32 XHuffman_Get_decompressed_Depth(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHUFFMAN_AXILITES_DEPTH_DECOMPRESSED;
}

u32 XHuffman_Write_decompressed_Words(XHuffman *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XHuffman_Read_decompressed_Words(XHuffman *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + (offset + i)*4);
    }
    return length;
}

u32 XHuffman_Write_decompressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XHuffman_Read_decompressed_Bytes(XHuffman *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_HIGH - XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XHUFFMAN_AXILITES_ADDR_DECOMPRESSED_BASE + offset + i);
    }
    return length;
}

void XHuffman_InterruptGlobalEnable(XHuffman *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_GIE, 1);
}

void XHuffman_InterruptGlobalDisable(XHuffman *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_GIE, 0);
}

void XHuffman_InterruptEnable(XHuffman *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_IER);
    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_IER, Register | Mask);
}

void XHuffman_InterruptDisable(XHuffman *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_IER);
    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_IER, Register & (~Mask));
}

void XHuffman_InterruptClear(XHuffman *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHuffman_WriteReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_ISR, Mask);
}

u32 XHuffman_InterruptGetEnabled(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_IER);
}

u32 XHuffman_InterruptGetStatus(XHuffman *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHuffman_ReadReg(InstancePtr->Axilites_BaseAddress, XHUFFMAN_AXILITES_ADDR_ISR);
}
