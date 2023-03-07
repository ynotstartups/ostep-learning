# first 2 bits 01 is vitrual page number
# remaining 4 bits is offset
# (offset for the bytes in virtual page we interested in)
VirtualAddress = 0b010101

OFFSET_MASK    = 0b000101
SHIFT          = 4

PFN            = 0b111

offset = VirtualAddress & OFFSET_MASK
assert offset == 0b0101
PhysAddr = (PFN << SHIFT) | offset
assert PhysAddr == 0b1110101

