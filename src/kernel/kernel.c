
// This file is a part of MRNIU/SimpleKernel (https://github.com/MRNIU/SimpleKernel).

// kernel.c for MRNIU/SimpleKernel.

#include "kernel.h"
#include "../test/test.h"

// 内核入口
void kernel_main(uint32_t magic, uint32_t addr) {
		console_init();       // 控制台初始化

		gdt_init();        // GDT 初始化
		idt_init();       // IDT 初始化
		clock_init();       // 时钟初始化
		keyboard_init();       // 键盘初始化
		pmm_init((multiboot_tag_t *)addr);
		debug_init(magic, addr);
		showinfo();
		test();

		while(1);

		return;
}
