# n – długość wiersza
# H – maksymalna długość nawiasowania
n, H = map(int, input().split())
# w – wiersz z nawiasami no kto by się spodziewał
w = input()

changeCounter = 0
deepCounter = 0

for i in range(0, n-1):
    bracket = w[i]
    if bracket == '(':
        deepCounter += 1

    if bracket == ')':
        deepCounter -= 1

    if deepCounter > H or deepCounter <= 0:
        changeCounter += 1
        if bracket == ')':
            deepCounter += 2
        else:
            deepCounter -= 2
print(changeCounter)
