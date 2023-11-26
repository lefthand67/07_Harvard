import re

def main():

    text = input("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = letters / words * 100
    S = sentences / words * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    grade = round(index)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 15:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_letters(text):

    letters_sum = 0;

    for i in range(len(text)):
        if re.match('[a-zA-Z]', text[i]) is not None:
            letters_sum += 1 
        else:
            continue

    return letters_sum


def count_words(text):

    words = 1;

    for i in range(len(text)):
        if re.match('[ ]', text[i]) is not None:
            words += 1
        else:
            continue

    return words


def count_sentences(text):

    sentences = 0;

    for i in range(len(text)):
        if re.match('[.!?]', text[i]) is not None:
            sentences += 1
        else:
            continue

    return sentences


main()
