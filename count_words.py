# This code is an expansion on MIT 6.001 material, not purely mine

# Open file as read

import string
import pylab as plt
filename = input("Filename (.txt): ")
text = open(filename).read()

# Remove punct
rem_punct_text = ''.join([' ' if char in string.punctuation else char for char in text.lower()])
cleaned_text = ' '.join(rem_punct_text.split()) + ' '
cleaned_list = cleaned_text.split()

# Stores words in a dictionary
def words_to_frequencies(text):
    myDict = {}
    for word in text:
        if word in myDict:
              myDict[word] += 1
        else:
            myDict[word] = 1
    return myDict

# Returns the most common word
def most_common_words(freqs):
    values = freqs.values()
    best = max(values)
    words = []
    for k in freqs:
        if freqs[k] == best:
            words.append(k)
    return (words,best)

# Returns a list of words most often used
def words_often(freqs, minTimes):
    result = []
    done = False
    while not done:
        temp = most_common_words(freqs)
        if temp[1] >= minTimes:
            result.append(temp)
            for w in temp[0]:
                del(freqs[w])
        else:
            done = True
    return result

# Printing the results
result = words_often(words_to_frequencies(cleaned_list), 10)
# print(result)

# Eliminates short words and returns a dictionary with frequencies
def rem_short(dataset, length):
    my_dict = {}
    for i in dataset:
        for j in i[0]:
            if len(j) > length:
                my_dict[j] = i[1]
    return my_dict

print(rem_short(result, 3))

'''Ploting the data
my_dict = rem_short(result, 5)
myList = my_dict.items()
myList = sorted(myList)
x, y = zip(*myList)
val = [] #
val.append(x+y) #
plt.hist(val, bins = 10)
plt.xlabel('Palavra')
plt.ylabel('Contagem')
plt.title('Palavras mais usadas')
plt.show()
'''
