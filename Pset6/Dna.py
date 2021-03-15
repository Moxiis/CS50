import csv
import sys

def check(text,sequence):
    # initializing count and max(and 2 help variable)
    count = 0
    max  = 0
    j = 0
    k = 0

    # checking how many STR in file
    for i in range(len(text)):
        check = True
        if text[i:i + len(sequence)] == sequence:
            count += 1
            while check == True:
                j += len(sequence)
                k += len(sequence)
                if text[i + j:i + k + len(sequence)] == sequence:
                    count += 1
                else:
                    if count > max:
                        max = count
                    check = False
                    j = 0
                    k = 0
                    count = 0
    return max

#argv check
if len(sys.argv) != 3:
    print("Wrong number of arguments")

# opening and writing CSV file into memory
with open(sys.argv[1], newline = '') as file:
    reader = csv.DictReader(file)
    list = []
    for row in reader:
        list.append(row)
file.close()

with open(sys.argv[1], newline = '') as file:
    reader = csv.reader(file)
    sequence = next(reader)
    sequence.remove("name")

# opening sequence file and writing it into memory
file =  open (sys.argv[2], "r")
text = file.read()
file.close

winner = {}

for indexes in range(len(sequence)):
    for index in range(len(list)):
        if int(list[index][sequence[indexes]]) == check(text,sequence[indexes]):
            if list[index]['name'] in winner:
                winner[list[index]['name']] += 1
            else:
                winner.update({list[index]['name']: 1})

for index in winner:
    if int(winner[index]) == len(sequence):
        print(index)
        exit(0)
print("No match")
