from collections import deque


def update_snake():
    try:
        index_wk = wk.index({'k': snakeHeadX, 'w': snakeHeadY})
        snakeColor.append(c[index_wk])
        snake.append({'x': snakeHeadX, 'y': snakeHeadY})
        wk[index_wk] = -4
    except:
        snake.append({'x': snakeHeadX, 'y': snakeHeadY})
        snake.popleft()


# m – długość i szerokość zarazem (plansza jest kwadratem)
# p – liczba przekąsek na planszy
# n – liczba poleceni do obsłużenia
m, p, n = map(int, input().split())

# k – kolumna (oś x)
# w – wiersz (oś y)
# c – kolor przekąski
wk = []
c = []

snake = deque([{'x': 1, 'y': 1}])
snakeColor = [0]
snakeHeadX = 1  # pozycja głowy na osi x
snakeHeadY = 1  # pozycja głowy na osi y

for i in range(p):
    i = list(map(int, input().split()))
    wk.append({'w': i[0], 'k': i[1]})
    c.append(i[2])


for j in range(n):
    j = input()
    if j == 'G':
        snakeHeadY -= 1
        update_snake()
    elif j == 'D':
        snakeHeadY += 1
        update_snake()
    elif j == 'L':
        snakeHeadX -= 1
        update_snake()
    elif j == 'P':
        snakeHeadX += 1
        update_snake()
    else:
        j, x, y = j.split()
        try:
            print(snakeColor[snake.index({'x': int(y), 'y': int(x)})])
        except:
            print(-1)
