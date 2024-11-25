# def longer_words_append(word: str):
#     sorted(longer_words, key=len, reverse=True)
#     if len(longer_words) < 3:
#         longer_words.append(word)
#     elif len(longer_words[2]) < len(word):
#         longer_words.pop()
#         longer_words.append(word)

    


# def repeated_words_append(word: str):
#     if word in most_repeated_words:
#         most_repeated_words[word] += 1
#     else:
#         most_repeated_words[word] = 1


def clean_string(line: str):
    del_chars = "-–'.,"
    clean_str: str = "".join(filter(lambda x: x not in del_chars, line))
    for word in clean_str.split():
        lista_palabras.append(word.lower())
        # longer_words_append(word)
        # repeated_words_append(word)


if __name__ == "__main__":
    lista_palabras = []

    with open("poem.txt", "rt") as f:
        elements = f.readlines()
    
    for lines in elements:
        clean_string(lines)
    
    print(sorted(lista_palabras, key=len, reverse=True)[:3])

    