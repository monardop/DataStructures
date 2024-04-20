from random import randint

new_list = []
numbers_request = 20


for n in range(numbers_request):
    new_int = randint(0,100)
    while new_int in new_list:
        new_int = randint(0,100)
    new_list.append(new_int)


file_name = "Case2.txt"
with open(file_name, "w") as file:
    for number in new_list:
        file.write(f"{number}\n")

new_list.sort()

print("int vec[] = {", end="")
for n in new_list:
    print(f"{n}, ", end="")
print("};")
