import random
player1 = 0
player2 = 0

for i in range(1000000):
    dice = [[1, 2, 3, 4, 5, 6], [1, 2, 3, 4, 5, 6], [1, 2, 3, 4, 5, 6], [1, 2, 3, 4, 5, 6]]
    cards = [[1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
             [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]]
    dicesuit= random.randint(0,3)
    diceroll = random.choice(dice[dicesuit])
    cardsuit = random.randint(0,3)
    card = random.choice(cards[cardsuit])
    deletion = cards[cardsuit].index(card)
    if dicesuit == cardsuit:
        score = card*diceroll
    else:
        score = card + diceroll
    del cards[cardsuit][deletion]
    dicesuit2 = dicesuit
    while dicesuit2 == dicesuit:
        dicesuit2 = random.randint(0, 3)
    diceroll2 = random.choice(dice[dicesuit2])
    counter = 0
    temp= random.randint(1,39)
    for i in range(4):
        for j in range(len(cards[i])):
            counter += 1
            if (counter == temp):
                cardsuit2 = i
    card2 = random.choice(cards[cardsuit2])
    if dicesuit2 == cardsuit2:
        score2 = card2*diceroll2
    else:
        score2 = card2 + diceroll2
    if score >= score2:
        player1 = player1 + 1
    else:
        player2 = player2 + 1
print(player1)
print(player2)