letter = 0
word = 1
sentence = 0

def coleman(letter,word,sentence):  # Coleman
    score =  round(0.0588 * ((letter * 100) / word) - 0.296 * ((sentence * 100) / word) - 15.8)
    if score < 1:
        return "Before Grade 1"
    elif score >= 16:
        return "Grade 16+"
    else:
        return score

text = input("Text:")
for i in range(len(text)):
    if text[i] in " ":
        word += 1
    elif text[i] in {".", "!", "?"}:
        sentence += 1
    elif text[i].isalpha() == True:
        letter += 1
    else:
        continue

print("Grade:" + str(coleman(letter,word,sentence)))
