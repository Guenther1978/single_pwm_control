# Writes the intensities in two files.
# The one file contains the most significant
# eight bits and the otherthe least
# significant two bits.

import math

number = 1
size = 255
max_value = 1023
expo = math.log(max_value)/(size - 1)
sin_arg = math.pi / (2 * size)

fh = open("intensities_high.inc", "w")
fh.write("\torg 0x200\n")
fh.write("table_high:\n")
fh.write("\tmovwf\tPCL")

fl = open("intensities_low.inc", "w")
fl.write("\torg 0x100\n")
fl.write("table_low:\n")
fl.write("\tmovwf\tPCL")

for row in range(15):
    fh.write("\n\t dt ")
    fl.write("\n\t dt ")
    for column in range(16):
        index = row * 16 + column
        value = round(math.exp(index * expo))
        print(index, value)
        fh.write(hex(int(value / 4)))
        fl.write(hex(value & 3))
        if (column != 15):
            fh.write(", ")
            fl.write(", ")
            
row = 15
fh.write("\n\t dt ")
fl.write("\n\t dt ")
for column in range(15):
    index = row * 16 + column
    value = round(math.exp(index * expo))
    print(index, value)
    fh.write(hex(int(value / 4)))
    fl.write(hex(value & 3))
    if (column != 14):
        fh.write(", ")
        fl.write(", ")

fh.write("\n")
fh.close()
fl.write('\n')
fl.close()
