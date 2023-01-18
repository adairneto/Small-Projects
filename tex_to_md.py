# This program takes a .tex file and breaks its sections, saving each section into a .tex file and converting it to .md

import string
import os

# Creates and stores the text into a .tex file
def storeTeX(title, new_text):
    if new_text != []:
        new_title = title+".tex"
        new_file = open(new_title, 'w')
        str_text = ' '.join(map(str, new_text))
        new_file.write(str_text)
        new_file.close()

# Search for sections and save them
def sectionSearch(text):
    title = "Intro"
    new_text = []

    for line in text[2:]:
        if "\section" in line:
            # If a new section is found, save the title and text 
            storeTeX(title, new_text)
            # Create new title and new text
            title = line[9:-2]
            new_text = [line]
        else:
            # Otherwise, append the text to the previous section
            new_text.append(line)

    # Save the final file at the end of the process
    storeTeX(title, new_text)

# Same as sectionSearch, but functional
def recSearch(title, new_text, rec_text):
    if rec_text == []:
        storeTeX(title, new_text)
        return
    else: 
        line = rec_text[0]
        if "\section" in line:
            # If a new section is found, save the title and text 
            storeTeX(title, new_text)
            # Create new title and new text
            title = line[9:-2]
            new_text = [line]
        else:
            # Otherwise, append the text to the previous section
            new_text.append(line)
        return recSearch(title, new_text, rec_text[1:])

# Convert .tex to .md
def texToMd(filename):
    for files in os.listdir():
        file_title = files[:-4]
        if files[-4:] == ".tex" and files != filename:
            print("Saving", files)
            new_file_title = file_title+".md"
            cmd = "pandoc -f latex -t markdown '"+files+"' -o '"+new_file_title+"'"
            os.system(cmd)

def main():
    print("Welcome to TeX Section Breaker!")
    filename = input("Please, input your filename (.tex): ")
    with open(filename, 'r') as file:
        text = file.readlines()
        functional = True 
        if functional:
            recSearch("Introduction", [], text[2:])
        else:
            sectionSearch(text)
        convertMd = input("Do you also want to convert to .md? \n'[Y]': Yes \n'N': No \n") or "Y"
        if convertMd == "Y":
            print()
            texToMd(filename)
        print("\nThat's all! Thanks for using TeX Section Breaker!")

if __name__ == "__main__":
    main()