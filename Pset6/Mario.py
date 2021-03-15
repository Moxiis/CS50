height = input("Height: ")# Height input

while height.isdigit() == False:
    height = input("Height: ")

while int(height) <= 0 or  int(height) > 8:
    height = input("Height: ")

height  = int(height)
block = 1
space = height - 1

for i in range(height):
    print(space * " ",  end="")
    print(block * "#",  end="")
    print("  ", end="")
    print(block * "#",  end="")
    print()
    space -= 1
    block += 1
