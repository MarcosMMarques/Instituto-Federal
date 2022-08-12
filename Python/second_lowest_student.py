if __name__ == '__main__':
    name = []
    score = []
    second_lowest_name = []
    for j in range(int(input())):
        name.append(input())
        score.append(float(input()))
        if j == 0:
            bigger = score[j]
        elif score[j] > bigger:
            bigger = score[j]
    lowest, second_lowest = bigger, bigger
    for i in range(len(score)):
        if score[i] < lowest:
            lowest = score[i]
    for i in range(len(score)):
        if score[i] < second_lowest and score[i] > lowest:
            second_lowest = score[i]
    j=0
    for i in range(len(score)):
        if score[j] == second_lowest:
            second_lowest_name.append(name[j])
        second_lowest_name.sort()
        j -= 1
    j=0
    for i in second_lowest_name:
        print(second_lowest_name[j])
        j += 1
