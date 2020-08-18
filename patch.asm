[cDyl_InitAsync()] + 0x30:
b init

0x803449dc:
; lis r3, 0x8060 ; set Arena low to 0x80600BFF
; with inject at 0x80560000 gives us 0xA0BFF bytes
u32 0x3c608060

0x802fa798:
b draw

0x800086ac:
bl game_loop

0x8037a3ac:
b read_controller