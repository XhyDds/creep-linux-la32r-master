// SPDX-License-Identifier: GPL-2.0
/*
 * Author: Huacai Chen <chenhuacai@loongson.cn>
 * Copyright (C) 2020-2021 Loongson Technology Corporation Limited
 */

#include <linux/binfmts.h>
#include <linux/elf.h>
#include <linux/export.h>
#include <linux/sched.h>

#include <asm/cpu-features.h>
#include <asm/cpu-info.h>

int arch_elf_pt_proc(void *_ehdr, void *_phdr, struct file *elf,
		     bool is_interp, struct arch_elf_state *state)
{
	return 0;
}

int arch_check_elf(void *_ehdr, bool has_interpreter, void *_interp_ehdr,
		   struct arch_elf_state *state)
{
	return 0;
}

void loongarch_set_personality_fcsr(struct arch_elf_state *state)
{
	current->thread.fpu.fcsr = boot_cpu_data.fpu_csr0;
}

int loongarch_elf_read_implies_exec(void *elf_ex, int exstack)
{
	if (exstack != EXSTACK_DISABLE_X) {
		/* The binary doesn't request a non-executable stack */
		return 1;
	}

	return 0;
}
EXPORT_SYMBOL(loongarch_elf_read_implies_exec);