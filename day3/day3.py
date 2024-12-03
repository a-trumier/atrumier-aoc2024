f = open("input.txt")

s = str(f.read())

totals = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]

print(str("0" in totals))

i = 0
l = len(s)
return_val = 0
should_mul = True
while (i < l):
    itera = 1
    if s[i] == "m":
        if (s[i+1] == "u"):
            if (s[i+2] == "l"):
                if (s[i+3] == "("):
                    c = 0
                    num1 = ""
                    num2 = ""
                    cur_char = s[i+4]
                    while cur_char in totals:
                        num1 += cur_char
                        c += 1
                        cur_char = s[i+4+c]
                    if (cur_char == ","):
                        c += 1
                        cur_char = s[i+4+c]
                        while cur_char in totals:
                            num2 += cur_char
                            c += 1
                            cur_char = s[i+4+c]
                        if (cur_char == ")" and should_mul):
                            return_val += int(num1) * int(num2)
    dontdo = ""
    for x in range(0, 7):
        if i+x < l:
            dontdo += s[i+x]
    dodo = ""
    for x in range(0, 4):
        if i+x < l:
            dodo += s[i+x]
    if dontdo == "don't()":
        should_mul = False
    if dodo == "do()":
        should_mul = True
    i += 1

print("Return val " + str(return_val))


    

f.close()
