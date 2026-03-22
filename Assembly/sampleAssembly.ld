MEMORY
{
    RAM : ORIGIN = 0x00000000 , LENGTH = 4k
}
SECTIONS
{
.text : {
    *(.text*)
    } > RAM
}