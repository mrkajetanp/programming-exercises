import random

random.seed(8)
state = random.getstate()

guess = random.randint(1,100)

print (guess)

random.setstate(state)

guess = random.randint(1,100)

print (guess)
