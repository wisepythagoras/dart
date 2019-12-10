#ifndef VESA_H
#define VESA_H

#include "../def.h"

struct VBEInfoBlock
{
    CHAR   signature[4]; // should be 'VESA'
    UINT16 version;
    UINT32 oem_ptr;
    UINT32 capabilities;
    UINT32 video_ptr;
    UINT16 total_memory;
    // VESA 2.x stuff
    UINT16 oem_software_rev;
    UINT32 oem_vendor_name_ptr;
    UINT32 oem_product_name_ptr;
    UINT32 oem_product_rev_ptr;
    UINT8  reserved[222];
    UINT8  oem_data[256];
} __attribute__ ((packed));

struct VBEModeInfoBlock
{
    UINT16 attributes;
    UINT8  wina_attributes;
    UINT8  winb_attributes;
    UINT16 win_granulatiry;
    UINT16 win_size;
    UINT16 wina_segment;
    UINT16 winb_segment;
    UINT32 win_function_ptr;
    UINT16 bytes_per_scanline;

    UINT16 x_resolution;
    UINT16 y_resolution;
    UINT8  x_charsize;
    UINT8  y_charsize;
    UINT8  num_planes;
    UINT8  bits_per_pixel;
    UINT8  num_banks;
    UINT8  memory_model;
    UINT8  bank_size;
    UINT8  num_image_pages;
    UINT8  _reserved;

    UINT8  red_mask_size;
    UINT8  red_field_position;
    UINT8  green_mask_size;
    UINT8  green_field_position;
    UINT8  blue_mask_size;
    UINT8  blue_field_position;
    UINT8  reserved_mask_size;
    UINT8  reserved_field_position;
    UINT8  direct_color_mode_info;

    UINT32 phys_base_ptr;
    UINT32 offscreen_mem_offset;
    UINT16 offscreen_mem_size;
    UINT8  _reserved2[206];
} __attribute__ ((packed));

#endif