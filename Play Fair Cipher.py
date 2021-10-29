import string

# Function To Convert List To 2D List/Matrix


def toMatrix(list, rows, columns):
    result, start, end = [], 0, columns
    for _ in range(rows):
        result.append(list[start:end])
        start += columns
        end += columns
    return result


# Initializations
cipherText = ''
upPT, tempMatrix = [], []
mCount = 0
# Getting Plain Text From User
plainText = list(
    (input("Enter Plain Text :: ").upper().replace(" ", "")).replace("J", "I"))
# Converting Plain Text To Pairs
print(plainText)
upPT.append(plainText[0])
mCount += 1
c = 1
while True:
    if c != len(plainText):
        upPT.append(plainText[c])
        mCount += 1
        c += 1
        print(upPT)
        print(mCount)
        if c != len(plainText):
            if mCount % 2 == 1:
                if upPT[mCount-1] != plainText[c]:
                    upPT.append(plainText[c])
                    mCount += 1
                    c += 1
                else:
                    upPT.append('X')
                    upPT.append(plainText[c])
                    mCount += 2
                    c += 1
            else:
                continue
        else:
            break
    else:
        break
if mCount % 2 != 0:
    upPT.append('X')
# Getting Key From User
key = list(input("Enter Key :: ").upper().replace("J", "I"))
# Converting Key To List
for c in key:
    if c not in tempMatrix:
        tempMatrix.append(c)
for c in string.ascii_uppercase:
    if c not in tempMatrix and c != 'J':
        tempMatrix.append(c)
# Converting Key List To 5x5 Matrix
tempMatrix = toMatrix(tempMatrix, 5, 5)
# Getting Transpose Of The Matrix For Column Checking
tempMatrixT = [[tempMatrix[j][i] for j in range(5)] for i in range(5)]
# Converting Plain Text Pairs To 2x2 Matrix
upPT = toMatrix(upPT, int(len(upPT)/2), 2)
# Displaying 5x5 Matrix
print("\nEncoding Matrix:")
for rows in tempMatrix:
    print(rows)
# Converting Each Pairs To Cipher Text
for rowsC in upPT:
    l1, l2 = 0, 0
    flagRow, flagCol = False, False
    # Row Check
    for rowsM in tempMatrix:
        if (rowsC[0] in rowsM) and (rowsC[1] in rowsM):
            cipherText += rowsM[(rowsM.index(rowsC[0]) + 1) % 5]
            cipherText += rowsM[(rowsM.index(rowsC[1]) + 1) % 5]
            flagRow = True
    # Column Check
    for colsM in tempMatrixT:
        if (rowsC[0] in colsM) and (rowsC[1] in colsM):
            cipherText += colsM[(colsM.index(rowsC[0]) + 1) % 5]
            cipherText += colsM[(colsM.index(rowsC[1]) + 1) % 5]
            flagCol = True
    # Rectangle Check
    if flagRow == False and flagCol == False:
        for rowsM in tempMatrix:
            if rowsC[0] in rowsM:
                r1 = rowsM.index(rowsC[0])
                break
            else:
                l1 += 1

        for rowsM in tempMatrix:
            if rowsC[1] in rowsM:
                r2 = rowsM.index(rowsC[1])
                break
            else:
                l2 += 1
        cipherText += tempMatrix[l1][r2]
        cipherText += tempMatrix[l2][r1]
    else:
        continue
# Displaying Encoding Of Each Pairs
tempCT = cipherText
tempCT = toMatrix(list(tempCT), int(len(tempCT)/2), 2)
print("\nEncoding Of Each Pairs:")
for row1, row2 in zip(upPT, tempCT):
    print(f'{row1} = {row2}')
# Displaying Cipher Text
print("\nCipher Text:", cipherText)
