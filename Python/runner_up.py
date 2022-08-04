if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    first = arr[0]
    runner_up = arr[0]
    for i in range(n):
        if first < arr[i]:
            first = arr[i]
        if runner_up > arr[i]:
            runner_up = arr[i]
    for i in range(n):
        if runner_up < arr[i] and arr[i] != first:
            runner_up = arr[i]
    print(runner_up)
