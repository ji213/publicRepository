##open file in same dir in 'r'ead mode
with open("story.txt", "r") as f:
    ##init story
    story = f.read()

##create set for input words
words = set()
start_of_word = -1

target_start = "<"
target_end = ">"


##look up enumerate
for i, char in enumerate(story):
    if char == target_start:
        start_of_word = i

    if char == target_end and start_of_word != -1:
        word = story[start_of_word: i + 1]
        words.add(word)
        start_of_word = -1

##dictionary
answers = {}

for word in words:
    answer = input("Enter a word for " + word + ": ")
    answers[word] = answer

for word in words:
    story = story.replace(word, answers[word])

print(story)

##output result to text file
