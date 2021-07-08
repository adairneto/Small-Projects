# Simply generates a random list of characters

nick <- function(n) {
  nickname <- sample(letters, n, replace = FALSE, prob = NULL)
  paste(nickname, collapse = "")
}

n = readline(prompt = "How many chars? ")
print(nick(n))