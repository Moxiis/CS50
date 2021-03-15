def luhn_algo(number):
    sum = 0
    for i in range(len(number)):
        if int(len(number)) % 2 == 0:
            if i % 2 == 0:
                if int(number[i]) * 2 > 9:
                    sum += (int(number[i]) * 2) % 10
                    sum += ((int(number[i]) * 2) - (int(number[i]) * 2) % 10) / 10
                else:
                    sum += int(number[i]) * 2
            else:
                sum += int(number[i])
        else:
            if i % 2 == 1:
                if int(number[i]) * 2 > 9:
                    sum += (int(number[i]) * 2) % 10
                    sum += ((int(number[i]) * 2) - (int(number[i]) * 2) % 10) / 10
                else:
                    sum += int(number[i]) * 2
            else:
                sum += int(number[i])
    if int(sum) % 10 == 0:
        return True
    else:
        return False


while(True):
    number = input("Number: ")  # number input

    if number.isdigit() == False:  # number check
        continue

    if luhn_algo(number) == False:  # Luhn algorithm check
        print("INVALID")
        exit(1)

    if len(number) == 15 and int(number[0:2]) in {34, 37}:  # American Express check
        print("AMEX")
        exit(0)

    elif len(number) == 16 and int(number[0:2]) in range(51, 56):  # MasterCard check
        print("MASTERCARD")
        exit(0)

    elif len(number) in {13, 16} and int(number[0:1]) == 4:  # Visa check
        print("VISA")
        exit(0)
    else:
        print("INVALID")  # Wrong card number
        exit(2)
