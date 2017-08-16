// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2016.1
// Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

// AXILiteS
// 0x00000 : Control signals
//           bit 0  - ap_start (Read/Write/COH)
//           bit 1  - ap_done (Read/COR)
//           bit 2  - ap_idle (Read)
//           bit 3  - ap_ready (Read)
//           bit 7  - auto_restart (Read/Write)
//           others - reserved
// 0x00004 : Global Interrupt Enable Register
//           bit 0  - Global Interrupt Enable (Read/Write)
//           others - reserved
// 0x00008 : IP Interrupt Enable Register (Read/Write)
//           bit 0  - Channel 0 (ap_done)
//           bit 1  - Channel 1 (ap_ready)
//           others - reserved
// 0x0000c : IP Interrupt Status Register (Read/TOW)
//           bit 0  - Channel 0 (ap_done)
//           bit 1  - Channel 1 (ap_ready)
//           others - reserved
// 0x80000 : Data signal of in_size
//           bit 31~0 - in_size[31:0] (Read/Write)
// 0x80004 : reserved
// 0x80008 : Data signal of out_size
//           bit 31~0 - out_size[31:0] (Read)
// 0x8000c : Control signal of out_size
//           bit 0  - out_size_ap_vld (Read/COR)
//           others - reserved
// 0x20000 ~
// 0x3ffff : Memory 'in_file' (30000 * 8b)
//           Word n : bit [ 7: 0] - in_file[4n]
//                    bit [15: 8] - in_file[4n+1]
//                    bit [23:16] - in_file[4n+2]
//                    bit [31:24] - in_file[4n+3]
// 0x40000 ~
// 0x7ffff : Memory 'out_file' (37500 * 8b)
//           Word n : bit [ 7: 0] - out_file[4n]
//                    bit [15: 8] - out_file[4n+1]
//                    bit [23:16] - out_file[4n+2]
//                    bit [31:24] - out_file[4n+3]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBRAM_DECOMPRESS_AXILITES_ADDR_AP_CTRL       0x00000
#define XBRAM_DECOMPRESS_AXILITES_ADDR_GIE           0x00004
#define XBRAM_DECOMPRESS_AXILITES_ADDR_IER           0x00008
#define XBRAM_DECOMPRESS_AXILITES_ADDR_ISR           0x0000c
#define XBRAM_DECOMPRESS_AXILITES_ADDR_IN_SIZE_DATA  0x80000
#define XBRAM_DECOMPRESS_AXILITES_BITS_IN_SIZE_DATA  32
#define XBRAM_DECOMPRESS_AXILITES_ADDR_OUT_SIZE_DATA 0x80008
#define XBRAM_DECOMPRESS_AXILITES_BITS_OUT_SIZE_DATA 32
#define XBRAM_DECOMPRESS_AXILITES_ADDR_OUT_SIZE_CTRL 0x8000c
#define XBRAM_DECOMPRESS_AXILITES_ADDR_IN_FILE_BASE  0x20000
#define XBRAM_DECOMPRESS_AXILITES_ADDR_IN_FILE_HIGH  0x3ffff
#define XBRAM_DECOMPRESS_AXILITES_WIDTH_IN_FILE      8
#define XBRAM_DECOMPRESS_AXILITES_DEPTH_IN_FILE      30000
#define XBRAM_DECOMPRESS_AXILITES_ADDR_OUT_FILE_BASE 0x40000
#define XBRAM_DECOMPRESS_AXILITES_ADDR_OUT_FILE_HIGH 0x7ffff
#define XBRAM_DECOMPRESS_AXILITES_WIDTH_OUT_FILE     8
#define XBRAM_DECOMPRESS_AXILITES_DEPTH_OUT_FILE     37500

