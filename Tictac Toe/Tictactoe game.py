arr=[[1,2,3],[4,5,6],[7,8,9]]
def show(arr):
    print("",arr[0][0], "|",arr[0][1], "|",arr[0][2])
    print("---|---|---")
    print("", arr[1][0], "|", arr[1][1], "|", arr[1][2])
    print("---|---|---")
    print("",arr[2][0], "|",arr[2][1], "|",arr[2][2])

p1=input('Enter PLayer 1 Name: ')
print("Yours position will be denoted by O")
p2=input('Enter PLayer 2 Name: ')
print("Yours position will be denoted by X")
c=1
show(arr)
list=[]
def check1(arr,p1,c):
    winp1=False
    for j in range(3):
        if arr[j].count('O')==3:
            winp1=True
    for j  in range(3):
        if arr[0][j]==arr[1][j]==arr[2][j]=='O':
            winp1 = True
    if arr[0][0]==arr[1][1]==arr[2][2]=='O':
        winp1=True
    if arr[0][2]==arr[1][1]==arr[2][0]=='O':
        winp1=True
    if winp1:
        return True
    else:
        return False

def check2(arr,p2,c):
    winp2=False
    for j in range(3):
        if arr[j].count('X')==3:
            winp2=True
    for j  in range(3):
        if arr[0][j]==arr[1][j]==arr[2][j]=='X':
            winp2 = True
    if arr[0][0]==arr[1][1]==arr[2][2]=='X':
        winp2=True
    if arr[0][2]==arr[1][1]==arr[2][0]=='X':
        winp2=True
    if winp2:

        return True
    else:

        return False

count=0
while c>0:
    if c%2!=0:
        print(p1," Chance, (0)")
        num=int(input("Enter a number: "))
        while (num in list) or (num<1 or num>9):
            print("invalid Input. You can't put O on position where already X has been placed. And You Can't enter a number less than 1 and greater than 9")
            num = int(input("Enter a number: "))
        arr[(num-1)//3][(num-1)%3]='O'
        check1(arr, p1, c)
        if check1(arr, p1, c):
            print(p1, "wins")
            show (arr)
            c=-56
            break
        c+=1
        count+=1
        show(arr)
        list.append(num)
        if count>8:
            print("DRAW")
            break

    else:
        print(p2, " Chance, (X)")
        num = int(input("Enter a number: "))
        while (num in list) or (num<1 or num>9):
            print("invalid Input. You can't put X on position where already O has been placed.")
            num = int(input("Enter a number: "))
        arr[(num - 1) // 3][(num - 1) % 3] = 'X'
        if check2(arr, p2, c):
            print(p2, "wins")
            show(arr)
            c = -56
            break
        c+=1
        count+=1
        show(arr)
        list.append(num)
        if count>8:
            print(" Sorry Guys, Game is DRAW")
            break