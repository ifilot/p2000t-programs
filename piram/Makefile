main.rom: main.c
	zcc \
	+embedded -clib=sdcc_iy \
	main.c \
	assembly_routines.asm \
	-startup=0 \
	-pragma-define:CRT_ORG_CODE=0x7000 \
	-pragma-define:REGISTER_SP=-1 \
	-pragma-define:CLIB_FOPEN_MAX=0 \
	--max-allocs-per-node200000 \
	-SO3 -bn main.bin \
	-create-app -m