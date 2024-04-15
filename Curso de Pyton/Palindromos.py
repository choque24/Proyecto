def is_palindrome(word):
    return word == word[::-1]

word = input("Enter a word: ")
if is_palindrome(word):
    print(word, "es un palindromo")
else:
    print(word, "no es un palindromo")                  