SECTION code_user

PUBLIC _clearscreen

_clearscreen:
	ld a,0x00
	ld hl,0x5000
	ld (hl),a
	ld de,0x5001
	ld bc,0x1000
	ldir
	ret