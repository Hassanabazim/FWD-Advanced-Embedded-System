
/*	
	@Author : Hassan abdelazeam Abdelsalam 

	@attension 
	that's the linker script from scratch implemented for STM32F103C8 
	
	@note-1 ALIGN(4): use to align the memory section into 4-bytes bundries
	might cause padding in the memory but that efficent for these reasons
	1. pressor performance 2. DMA transfer 3. pressor caching 4. MEMORY mapped registers
	
	@note-2 KEEP: use to prevent the linker from discard these symbols or section in the 
	linking process due to linker optimization, as that very crucal to the MCU as that hold
	the address of the all ISRs even if that not used in the application.
*/


/*	ENTRY POINT  */ 
ENTRY(Reset_Handler)

/*	Highest address of the user mode stack 	*/ 
_estack = ORIGIN(RAM) + LENGTH(RAM);

/*	set the Amount of bytes for stack  and heep */
_Min_stack_size  = 	0x500 ;
_heap_size = 	0x100 ;

/* Memories definition */
MEMORY
{
	FLASH(rx): ORIGIN = 0x08000000,  LENGTH = 64K 
	RAM (rwx): ORIGIN = 0x20000000,  LENGTH = 20k	
}
 
/*	MEMORY SECTIONS */ 
SECTIONS
{
	.isr_vector :				/* VECTOR TABLE */ 
	{
		. = ALIGN(4);			
		KEEP(*(.isr_vector))
		. = ALIGN(4);
	}>FLASH
	
	.text :					
	{
		. = ALIGN(4);
		*(.text)
		*(.text.*)
		*(.glue_7)
		*(.glue_7t)	
		*(.eh_frame)
		
		KEEP (*(.init))
		KEEP (*(.fini))
		. = ALIGN(4);
		_etext = . ;
	}>FLASH
	
	.rodata :
	{
		. = ALIGN(4);
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
	}>FLASH
	
	_sidata = LOADADDR(.data);
	.data :
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_edata = .;
	}>RAM AT> FLASH
	
	.bss :
	{
		. = ALIGN(4);
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		*(.bss.*)
		. = ALIGN(4);
		_ebss = . ;
		__bss_end__ = _ebss;
	}>RAM
	
	.heap :
	{
		. = ALIGN(8); 
		. = . + _heap_size; 
		. = ALIGN(8);	
		_end = . ;
		end = . ;

		__end__ = .;
	}>RAM
	
	.stack :
	{
		. = ALIGN(8); 
		. = . + _stack_size;	
		. = ALIGN(8);	
		_enstack = . ;
	
	}>RAM
	
	/*	Remove information compiler library from the final elf file to reduce size */ 
	/DISCARD/:
	{
		libc.a 		(*)
		libm.a 		(*)
		libgcc.a 	(*)	
	}
	
	.ARM.attributes 0 : { *(.ARM.attributes) }
}
	