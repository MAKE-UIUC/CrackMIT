from pngcanvas import PNGCanvas

size = 21
scale = 16

num = int(raw_input('input '))
s = bin(num)[2:]

width = size * scale
height = size * scale
c = PNGCanvas(width, height)
c.color = bytearray([0xff, 0xff, 0xff, 0xff])
c.rectangle(0, 0, width-1, height-1)
c.color = bytearray([0x00, 0x00, 0x00, 0xff])

for i in range(0, size):
    for j in range(0, size):
        if s[i*size+j] == '1':
            c.filled_rectangle(scale * i, scale * j, scale * (i+1), scale * (j+1))

with open('qr.png', 'wb') as f:
    f.write(c.dump())