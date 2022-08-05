#ifndef KERNEL_UTIL_H
#define KERNEL_UTIL_H

#include <stdint.h>
#include "BasicRenderer.h"
#include "def/cstr.h"
#include "efiMemory.h"
#include "memory/memory.h"
#include "def/Bitmap.h"
#include "./paging/PageFrameAllocator.h"
#include "./paging/PageMapIndexer.h"
#include "./paging/paging.h"
#include "./paging/PageTableManager.h"
#include "./userinput/mouse.h"
#include "acpi.h"
#include "pci.h"

struct BootInfo {
    Framebuffer* framebuffer;
    PSF1_FONT* psf1_Font;
    EFI_MEMORY_DESCRIPTOR* mMap;
    uint64_t mMapSize;
    uint64_t mMapDescSize;
    ACPI::RSDP2* rsdp;
};

extern uint64_t _KernelStart;
extern uint64_t _KernelEnd;

struct KernelInfo {
    PageTableManager* pageTableManager;
};

KernelInfo InitializeKernel(BootInfo* bootInfo);


#endif
